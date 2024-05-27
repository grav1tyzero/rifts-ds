#include <lib.h>
#include ROOMS_H

#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("The end of the hallway");
    SetLong("The long and very ornate hallway is finally coming to and end, the
burgundy colored carpet comes to a halt at the end of the hallway.  a large
grandfather clock stands tall to the right side of the hall, and a vertical
sliding window, framed in mahogany is in the center at the end of the hall.
Heading the other way, the long hallway looms before your journey.");
    SetExits( ([
        "north" : "/realms/gravity/area/room/waynemanorhall2.c",
      ]) );
	SetItems( ([ ({ "grandfather clock", "clock" }) : "A very ornate very "
                 "expensive grandfather clock." ]) );
    SetSearch( ([ "clock" : "You see a wear mark on the side of the clock." ]) );
}

	void PostExit(string dir){;
	RemoveExit ("clock");
}

	void init(){
    ::init();
    add_action("slide_clock", "slide");
}

int slide_clock(string str) {
    if(str == "clock") {
        write("You slide the grandfather clock to the side, revealing a staircase.");
		AddExit ("clock", "/realms/gravity/area/room/batcave", 0, (: PostExit :));
        return 1;
    }
    return 0;
}