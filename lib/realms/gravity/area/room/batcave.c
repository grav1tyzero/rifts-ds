#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Batcave");
    SetLong("you're in the batcave, there's a retinal scanner next to the bat
computer");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
SetExits( ([
"out" : "/realms/gravity/area/room/waynemanordrive",
"west" : "/realms/gravity/area/room/sample_two",
"down" : "/realms/gravity/area/room/bunker.c",
]) );
    SetDoor("down", "/realms/gravity/area/doors/hatch");
    SetInventory(([
      ]));
}

	void PostExit(string dir){;
	RemoveExit ("up");
}

	void init(){
    ::init();
    add_action("scan_eye", "scan");
}

int scan_eye(string str) {
    if(str == "eye") {
        write("You scan your eye with a retinal scanner, the grandfather clock up the stairs slides to the side.");
		AddExit ("up", "/realms/gravity/area/room/waynemanorhall3.c", 0, (: PostExit :));
        return 1;
    }
    return 0;
}

