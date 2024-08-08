#include <lib.h>
#include "/realms/thurtea/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Room One");
    SetLong("This is another sample room.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetInventory(([
      ]));

}

void init(){
    ::init();
}
