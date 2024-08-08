#include <lib.h>
#include "/realms/thurtea/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Room 2");
    SetLong("This is the second test room.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetInventory(([
        "/realms/thurtea/area/npc/guy" : 1,
      ]));

}

void init(){
    ::init();
}
