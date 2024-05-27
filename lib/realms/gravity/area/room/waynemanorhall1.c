#include <lib.h>
#include ROOMS_H

#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("copy of waynemanorhall2.c");
    SetLong("Before you stands an annoyingly long and very ornate hallway, the burgundy colored carpet comes to a halt at the end of the hallway. wayyyy further down the hall, you see a large grandfather clock and a vertical sliding windows, on either side of the hallway, are framed in rich mahogany. Looks like a long hallway looms before you, may be worth checking out.");
    SetExits(([
        "south" : "/realms/gravity/area/room/waynemanorhall2",
      ]));

}

void init(){
    ::init();
}
