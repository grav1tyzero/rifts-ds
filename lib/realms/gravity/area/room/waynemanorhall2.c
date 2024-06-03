#include <lib.h>
#include ROOMS_H

#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Wayne Manor Hallway");
    SetLong("Spanning the length of Wayne Manor, the hallway is a testament to timeless elegance. Ornate chandeliers hang from the high ceilings, casting shimmering light on the marble floors. A series of Gothic arches frame the path, leading to heavy oak doors that guard the manor's secrets. The quiet hush of the hall speaks of grandeur and mystery, with whispers of the past lingering in the air.");
    SetExits( ([
        "south" : "/realms/gravity/area/room/waynemanorhall3",
        "north" : "/realms/gravity/area/room/waynemanorhall1.c",
      ]) );

}

void init(){
    ::init();
}
