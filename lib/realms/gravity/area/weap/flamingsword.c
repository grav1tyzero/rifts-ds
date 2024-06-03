#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

int is_ignited = 0;

static void create() {
    item::create();
    SetKeyName("empty metal hilt");
    SetId( ({ "hilt", "metal hilt", "empty hilt" }));
    SetAdjectives( ({ "empty", "metal" }));
    SetShort("an empty metal hilt");
    SetLong("An empty metal hilt that can be charged to ignite a flaming sword.");
    SetMass(50);
    SetVendorType(VT_WEAPON);
    SetClass(30);
    SetDamageType(BLADE);
    SetWeaponType("blade");
}

void init(){
    ::init();
    add_action("charge_hilt", "charge");
}

int charge_hilt(string str) {
    if(str == "hilt" && !is_ignited) {
        is_ignited = 1;
        SetShort("a flaming sword");
        SetLong("A sword ignited in a burst of crackling flames.");
        call_out("extinguish_flame", 420); // 7 minutes = 420 seconds
        write("You charge the hilt. It ignites in a burst of crackling flames, creating a flaming sword.");
        return 1;
    }
    else {
        write("You can't charge that.");
        return 0;
    }
}

void extinguish_flame() {
    is_ignited = 0;
    SetShort("an empty metal hilt");
    SetLong("An empty metal hilt that can be charged to ignite a flaming sword.");
    write("The flames on your sword extinguish after 7 minutes.");
}
