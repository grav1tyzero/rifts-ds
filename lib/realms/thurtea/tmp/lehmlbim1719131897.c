#include <lib.h>
#include "/realms/thurtea/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("This is another test room.");
    SetLong(0);
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetInventory(([
      ]));

}

void init(){
    ::init();
}
