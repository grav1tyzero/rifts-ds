/*  /verbs/players/score.c
 *  from the Dead Souls Library
 *  Displays a list of score and related info
 *  created by Blitz@Dead Souls
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

varargs mixed eventScore();

static void create() {
    daemon::create();
    SetNoClean(1);
    SetHelp("Syntax: score\n\n"
            "Displays information about your character.\n"
            "See also: stat, status, env");
}

static string *FoodDegree =
({ "starving!", "very hungry.",
 "hungry.", " partially hungry.",
 "feeling full.", "quite full." });

static string *DrunkDegree =
({ "sober", "tipsy", "drunk", "blitzed",
 "three sheets to the wind", "FUBAR" });

static string *DrinkDegree =
({ "parched", "extremely thirsty", "very thirsty", "thirsty",
 "somewhat thirsty", "unthirsty" });

mixed cmd(string arg) {
    eventScore(arg);
    return 1;
}

varargs mixed eventScore(string arg) {
    string *str;
    int birth, age, x, y, z, qp, xp, dbt;
    string *tmp;
    mapping lev;
    object who;
    string prn, haben, be, poss;
    string past, qual, cnj;

    if(!arg || !creatorp(this_player()) || !(who = find_player(arg))){
        who = this_player();
        haben = "have";
        be = "are";
        poss = "your";  
        prn = "you";
        past = "were";
        qual = "qualify";
        cnj = "";
    }

    else {
        haben = "has";
        be = "is";
        poss = possessive(who);
        prn = nominative(who);
        past = "was";
        qual = "qualifies";
        cnj = "s";
    }
    str  = ({ ".======================( " + "%^GREEN%^Megaversal Identification%^RESET%^" + " )======================." });
    str += ({ "|  Name    : " + who->GetShort() + " (" +
        who->GetMoralityDescription() + ")." });
    str += ({ "|-------------------------------------------------------------------------|" });
	str += ({ sprintf("|  %-15s [%d]  \t%-15s [%s]", "Level:", who->GetLevel(), " Race", capitalize(who->GetRace() || "nothing")) });

	str += ({ sprintf("|  %-15s [%s]   %-15s [%s]", "Class:", capitalize(who->GetClass() || "commoner"), " Native town", who->GetTown()) });
	str += ({ sprintf("|  %-15s [%s]   %-15s [%s]", "Faith:", (who->GetReligion() || "Agnostic"), " Titles", consolidate(sizeof(who->GetTitles()), "one title")) });

    str += ({ "|-------------------------------------------------------------------------|" });
	
/*	    str += ({ sprintf(capitalize(prn)+" "+past+
                " born on the %d%s day of %s, year %d. "
                "(%d years old)", query_date(birth), ordinal(query_date(birth)),
                query_month(birth), query_year(birth), age) });
	*/
    birth = who->GetBirth();
    age = ( query_year(time()) - query_year(birth) );
    str += ({ sprintf("|  %-15s [%s]", "Birth date",
	            "Born on "+ query_date(birth) + " of " + query_month(birth) + ", year " + query_year(birth) + ". "
                "(" + age + " years old)", query_date(birth), ordinal(query_date(birth)),
                query_month(birth), query_year(birth), age) });
    str += ({ "|-------------------------------------------------------------------------|" });
    if( x = who->GetTrainingPoints() < 1 ) {
        y = who->GetLevel() + 1 + (x / -4);
        str += ({ sprintf("|  %-15s [%s]", "Training points",
                    "await "+(who == this_player() ? "you" :
                    objective(who))+" at level " + y + ".") });
    }
    else str += ({ sprintf("|  %-15s [%d]", "Training points",
                    who->GetTrainingPoints()) });
    if( who->GetWimpy() )
        str += ({ sprintf("|  %-15s [%s]", "Feeling",
                    "wimpy.") });
    else
        str += ({ sprintf("|  %-15s [%s]", "Feeling",
                    "brave.") });
    if( who->GetPoison() > 0 )
        str += ({ sprintf("|  %-15s [%s]", "Condition",
                    "poisoned.") });
    x = who->GetFood() / 17;
    if( x > sizeof(FoodDegree) - 1 ) x = (sizeof(FoodDegree) - 1);
    y = who->GetDrink() / 17;
    if( y > sizeof(DrinkDegree) - 1 ) y = (sizeof(DrinkDegree) - 1);
    z = who->GetAlcohol();
    if(z) z = (z/17) + 1;
    if( z > sizeof(DrunkDegree) - 1 ) z = (sizeof(DrunkDegree) - 1);
    str += ({ sprintf("|  %-15s [%s]", "Food",
                    FoodDegree[x]) });
    str += ({ sprintf("|  %-15s [%s]", "Drink",
                    DrinkDegree[y]) });
    str += ({ sprintf("|  %-15s [%s]", "Alcohol",
                    DrunkDegree[z]) });
    str += ({ "|-------------------------------------------------------------------------|" });
    x = who->GetCustomStats();

    tmp = ({});
    qp = who->GetQuestPoints();
    xp = who->GetExperiencePoints();
    dbt = who->GetExperienceDebt();
    lev = PLAYERS_D->GetLevelList()[(who->GetLevel()) + 1];

    if(dbt){
        str += ({ sprintf("|  %-15s [%d]", "Experience debt",
                    dbt) });
    }

    if(lev){
        if(REQUIRE_QUESTING){
            qp = lev["qp"] - qp;
            if(qp > 0) tmp += ({sprintf("|  %-15s [%s]", "Quest points required",
                    comma(qp))});
        }

        xp = lev["xp"] - xp;
        if(xp > 0) tmp += ({sprintf("|  %-15s [%s]", "Experience points required",
                comma(xp))});
        if(!sizeof(tmp)) tmp = ({sprintf("|  %-15s [%s]", "Qualification",
                "to advance a level.")});
        str += tmp; 
    }

    if(x){
        str += ({ sprintf("|  %-15s [%d]", "Customization points",
                    x) });
    }
    str += ({ "'========================================================================='" });
    this_player()->eventPage(str, "info");
    return 1;
}