#include <lib.h>
#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("copy of sample_two.c");
    SetLong("This is another sample room.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );

    SetInventory(([
        MY_OBJ "/case" :1,
      ]));

}

void init(){
    ::init();
}
