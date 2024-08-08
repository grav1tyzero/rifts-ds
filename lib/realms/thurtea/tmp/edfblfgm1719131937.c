#include <lib.h>
#include ROOMS_H

#include "/realms/thurtea/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("a blank room");
    SetLong("A featureless area.");
}

void init(){
    ::init();
}
