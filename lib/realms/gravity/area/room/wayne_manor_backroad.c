#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("a road outside a cave);
    SetLong("This is a road outside a cave, nothing special to see.");
     SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetExits(([
        "west" : "/realms/gravity/area/room/batcave",
      ]));
    SetInventory(([
      ]));

}

void init(){
    ::init();
}