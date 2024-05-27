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