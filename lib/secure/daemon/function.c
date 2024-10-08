#include <lib.h>
#include <save.h>
#include <daemons.h>
#include <runtime_config.h>

inherit LIB_DAEMON;

static string globaltmp;
static string *files = ({});
static string SaveFuns = save_file(SAVE_FUNCTIONS);
static int seeking = 0;
static int count = 0;
mapping FileSize = ([]);
mapping FunctionCache = ([]);
mixed *Functions = ({});
mapping LCFunctions = ([]);
mapping TmpMap = ([]);

static private void validate() {
    if (!this_player()) return 0;
    if (!(master()->valid_apply(({ "ASSIST" })))) {
        error("Illegal attempt to access FUNCTIONS_D: " + get_stack() + " " + identify(previous_object(-1)));
    }
    if (query_os_type() == "windows") {
        error("The functions daemon has been disabled for your mud because it is running on windows. Intensive file operations in windows are not yet supported on Dead Souls.");
    }
}

void heart_beat() {
    if (seeking) {
        foreach (mixed arr in call_out_info()) {
            if (arr[0] == this_object()) {
                return;
            }
        }
        SaveObject(SaveFuns);
        seeking = 0;
    }
    count++;
    if (count > 700) {
        SaveObject(SaveFuns);
        count = 0;
    }
}

mixed SendFiles(string *arr) {
    if (query_os_type() == "windows" || !(MASTER_D->GetPerfOK())) {
        return 0;
    }
    validate();
    foreach (string sub in arr) {
        load_object("/secure/cmds/creators/showfuns")->cmd(sub);
    }
    return 1;
}

mixed SendFiles2(string *arr) {
    string prefix, file, tmpfile, ret = "";
    object ob;
    mixed deffed = ({});
    int err;

    foreach (string element in arr) {
        if (!strsrch(element, "/lib/")) {
            prefix = path_prefix(element);
            file = replace_string(element, prefix, "");
            tmpfile = prefix + "/" + file + alpha_crypt(5) + time() + ".c";
            write_file(tmpfile, "#pragma save_types\n", 1);
            write_file(tmpfile, read_file(element));
            err = catch(ob = load_object(tmpfile));
            if (err) {
                ret += "Error loading " + tmpfile + ": " + err + "\n";
                continue;
            }
            foreach (string fun in functions(ob)) {
                deffed += ({ fun });
            }
            rm(tmpfile);
        }
    }
    return deffed;
}

void ReadFuns(string path) {
    if (query_os_type() == "windows" || !(MASTER_D->GetPerfOK())) {
        return;
    }
    validate();
    foreach (string file in get_dir(path + "*.c")) {
        if (file_size(path + file) > 0) {
            write_file(SaveFuns, read_file(path + file));
        }
    }
}

static int save_file(string file) {
    return save_object(file);
}

static int old_savename(string file) {
    return restore_object(file);
}

varargs mixed GetFunctions(string str) {
    if (!str) return copy(Functions);
    if (this_player() && (!FileSize[str] || stat(str)[0] != FileSize[str])) return 0;
    return FunctionCache[str];
}

varargs mixed GetLCFunctions(string str, int subs) {
    string *ret = ({}), *l_funs, *e_funs, *se_funs;
    if (!LCFunctions) LCFunctions = ([]);
    if (!str) return copy(LCFunctions);
    str = lower_case(str);
    if (!subs) {
        return LCFunctions[str];
    }
    l_funs = regexp(keys(LCFunctions), str);
    foreach (mixed foo in l_funs) {
        if (sizeof(LCFunctions[foo])) {
            ret += LCFunctions[foo];
        }
    }
    ret = distinct_array(ret);
    e_funs = regexp(efuns(), str);
    se_funs = regexp(sefuns(), str);
    if (sizeof(e_funs) + sizeof(ret) < 64000) ret += e_funs;
    if (sizeof(se_funs) + sizeof(ret) < 64000) ret += se_funs;
    ret = sort_array(distinct_array(ret), 1);
    return ret;
}

int eventDestruct() {
    SaveObject(SaveFuns);
    return ::eventDestruct();
}

varargs mixed GetInstances(string str, string where) {
    string cooked_list = "";
    if (!where || !sizeof(where)) where = "/lib/";
    if (!sizeof(FunctionCache)) return 0;
    foreach (string key, string val in FunctionCache) {
        string funex;
        object cle;
        if (grepp(val, str) && !strsrch(key, where)) {
            if (!sizeof(key) || !unguarded((: file_exists($(key)) :)) ||
                    catch(cle = load_object(key)) || !cle) {
                continue;
            }
            funex = function_exists(str, cle, 1);
            if (funex && !grepp(cooked_list, funex + "\n")) {
                cooked_list += funex + "\n";
            }
        }
    }
    return cooked_list;
}
