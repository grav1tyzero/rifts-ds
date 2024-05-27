#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();

    SetSide("down", (["id" : ({ "door", "trap door", "hatch"}),
                "short" : "a door leading down",
                "long" : "This is a plain wooden door.",
                "lockable" : 1 ]) );

    SetSide("up", (["id" : ({ "door" "hatch", "trap door" }),
                "short" : "a hatch leading up",
                "long" : "This is a handsome wooden door.",
                "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(1);
    SetKeys("down", ({ "key", "batkey", "bat key", "the batkey" "666" }));
    SetKeys("up", ({ "key", "batkey", "bat key", "the batkey" "666" }));
}
void init(){
    ::init();
}