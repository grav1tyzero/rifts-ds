#include <lib.h>
#include ROOMS_H

#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("copy of waynemanorhall3.c");
    SetLong("The long and very ornate hallway is finally coming to and end, the burgundy colored carpet comes to a halt at the end of the hallway. Further down the hall, you see a large grandfather clock and a vertical sliding window, framed in mahogany is in the center at the end of the hall. Looks like only a little more hallway looms before you for the rest of your journey.");
    SetExits( ([
        "south" : "/realms/gravity/area/room/waynemanorhall3",
        "north" : "/realms/gravity/area/room/waynemanorhall1.c",
      ]) );

}

void init(){
    ::init();
}
