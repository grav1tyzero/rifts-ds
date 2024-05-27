#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("copy of batcave.c");
    SetLong("This is another sample room.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetExits(([
        "in" : "/realms/gravity/area/room/batcave",
      ]));
    SetInventory(([
      ]));

}

void init(){
    ::init();
}
