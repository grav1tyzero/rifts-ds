#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("copy of arcave4.c");
    SetLong("<placeholder>");

}
void init(){
    ::init();
}
