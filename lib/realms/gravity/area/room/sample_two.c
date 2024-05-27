#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Second Sample Room");
    SetLong("This is another sample room.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetExits( ([
        "west" : "/realms/gravity/area/room/sample_room",
        "east" : "/realms/gravity/area/room/batcave.c",
      ]) );
    SetInventory(([
        MY_OBJ "/case" :1,
      ]));

}

void init(){
    ::init();
}
