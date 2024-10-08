#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_FLASK;

void create(){
    ::create();
    SetKeyName("cask");
    SetId( ({"cask","keg"}) );
    SetAdjectives( ({"large","wooden","wood"}) );
    SetShort("a wooden cask");
    SetLong("A large wooden cask for containing fluids.");
    SetMass(1000);
    SetBaseCost("universal credits",10);
    SetVendorType(VT_TREASURE);
    SetFlaskContents("water");
    SetFlaskUses(20);
    SetStrength(5);
    SetMaxFlask(50); 
    SetMealType(MEAL_DRINK);
    SetTapped(1);
}

void init(){
    ::init();
}
