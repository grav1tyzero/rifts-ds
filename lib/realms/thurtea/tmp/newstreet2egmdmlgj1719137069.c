#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("copy of newstreet.c");
    SetLong("<placeholder>");
    SetExits( ([
        "east" : "/domains/chi-town/room/newstreet3",
        "west" : "/domains/chi-town/room/newstreet",
        "north" : "/domains/chi-town/room/shop1.c",
      ]) );

}
void init(){
    ::init();
}
