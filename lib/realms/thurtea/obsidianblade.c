#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;


static void create() {
    item::create();
    SetKeyName("obsidian blade");
    SetId( ({ "blade", "obsidian blade" }) );
    SetAdjectives( ({ "blade" }) );
    SetShort("a jagged obsidian blade");
    SetLong("This jagged obsidian blade glistens with a menacing "+
      "sheen. Its sharp edges and crimson veins give it a "+
      "blood-like appearance. The worn leather hilt provides "+
      "a firm grip, exuding an aura of ancient power.");
    SetMass(150);
    SetBaseCost("universal credits",1000000);
    SetVendorType(VT_WEAPON);
    SetClass(20);
    SetDamageType(BLADE);
    SetWeaponType("blade");
}
void init(){
    ::init();
}
