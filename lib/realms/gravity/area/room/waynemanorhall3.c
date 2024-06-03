#include <lib.h>
#include ROOMS_H

#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("The end of the hallway");
    SetLong("In a secluded corridor of Wayne Manor, the hallway is lined with dark wood paneling and illuminated by flickering candle sconces. Portraits of Wayne ancestors gaze down, their eyes following your every step. At the far end stands an imposing grandfather clock, its pendulum swinging with a steady, rhythmic tick. The clock, an intricately carved masterpiece, features brass accents and a rich, walnut finish, a testament to the craftsmanship of a bygone era.  This clock, a family heirloom, conceals more than just time; it is rumored to be the gateway to Bruce Wayne's clandestine operations, hidden in plain sight amidst the manor's timeless luxury. The air is thick with a sense of history and mystery, the soft ticking of the clock echoing through the hall, a constant reminder of the secrets that Wayne Manor holds within its walls.");
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