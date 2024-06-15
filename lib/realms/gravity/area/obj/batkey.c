#include <lib.h>

inherit LIB_ITEM;


static void create() {
    item::create();
    SetKeyName("key");
    SetId( ({ "key", "batkey", "bat key", "the batkey" "666" }) );
    SetAdjectives( ({ "bat key", "batkey","key" }) );
    SetShort("a bat shaped key");
    SetLong("It is a laser cut key with batman logos etched into it.");
    SetMass(20);
    SetBaseCost("universal credits",1000);
}
void init(){
    ::init();
}
