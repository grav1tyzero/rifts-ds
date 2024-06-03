#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Batcave");
    SetLong("Hidden deep beneath Wayne Manor, the Batcave is a sprawling, high-tech sanctuary teeming"
	        "with cutting-edge technology and invaluable relics. Illuminated by the eerie glow of multiple"
            "computer screens, the cavernous space is a stark contrast to the opulent mansion above."
			"                                                                                     \n"
			"Stalactites hang from the ceiling, and a subterranean river winds through the rocky terrain,"
			"adding to the cave's natural grandeur. In the eastern corner, the iconic Batmobile rests, next"
			"to a large vault-like room,ready for action, while various Bat-gadgets and prototypes are"
			"meticulously organized in another."
			"\n"
			"A giant penny, a retinal scanner, and an array of Batsuits are displayed like trophies, each telling"
			"a story of past victories and formidable foes. The cave also houses a sophisticated crime lab and"
			"the all-seeing Batcomputer, the nerve center of Batman's vigilant operations."
			"\n                                                                                                 "
			"This lair, steeped in secrets, is where Bruce Wayne transforms into Gotham's relentless protector."
			"\n");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
SetExits( ([
"out" : "/realms/gravity/area/room/waynemanordrive",
"east" : "/realms/gravity/area/room/vault",
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

