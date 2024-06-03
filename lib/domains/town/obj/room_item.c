#include <lib.h>

inherit LIB_DUMMY; // These do not show up in desc, but you can look at them

int ShowRoomDesc(){
    this_player()->eventDescribeEnvironment();
    return 1;
}


static void create() {
    dummy::create();
    SetKeyName("room");
    SetId(({"here","around","place","area" }));
    SetAdjectives("this", "current");
    SetShort("");
    SetLong( (: ShowRoomDesc :) );
}
