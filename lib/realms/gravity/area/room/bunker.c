#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("copy of batcave.c");
    SetLong("You are in the middle of an underground bunker, a ladder leads back up to the batcave.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
SetExits(([
"up" : "/realms/gravity/area/room/batcave",
]));
    SetDoor("up", "/realms/gravity/area/doors/hatch");
    SetInventory(([
      ]));
}

void init(){
    ::init();
    add_action("scan_eye", "scan");
}

int scan_eye(string str) {
    if(str == "eye") {
        write("You scan your eye with a retinal scanner.");
        return 1;
    }
    return 0;
}
