#include <lib.h>
#include "/realms/thurtea/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Sample Room");
    SetLong("This is a room you can use as a template.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetExits( ([ 
        "east" : "/realms/thurtea/area/room/sample_two",
        "west" : "/realms/thurtea/workroom",
      ]) );
    SetInventory( ([
        MY_OBJ "/table" : 1,
        MY_NPC "/fighter" : 1,
      ]) );
}

void init(){
    ::init();
}
