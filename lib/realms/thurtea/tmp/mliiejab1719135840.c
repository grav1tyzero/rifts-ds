#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("copy of street2.c");
    SetLong("<placeholder>");

}
void init(){
    ::init();
}
