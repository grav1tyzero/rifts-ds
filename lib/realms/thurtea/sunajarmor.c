#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("Sunaj Assassin armor");
    SetId(({"armor", "Sunaj armor", "assassin armor", "Sunaj Assassin armor"}));
    SetAdjectives(({"black", "stealthy", "concealing", "Sunaj"}));
    SetShort("%^B_RED%^%^BLACK%^Sunaj Assassin Armor%^RESET%^");
    SetLong("Shrouded in mystery, this armor is crafted from an alien alloy, offering superb protection while concealing the wearer's identity with its demonic visage helmet.");
    SetMass(2500);
    SetBaseCost("universal credits",15000);
    SetProtection(BLUNT,25);
    SetProtection(BLADE,100);
    SetProtection(KNIFE,100);
    SetArmorType(A_CUSTOM);
    SetProperty("no steal", 1); // Prevents the armor from being stolen
}

void init(){
    ::init();
}

