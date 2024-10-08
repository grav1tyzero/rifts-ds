#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("leather boot");
    SetAdjectives( ({"leather", "simple", "orc", "orcish", "inelegant", "protective"}) );
    SetId(({"boot","left boot"}));
    SetShort("a leather boot");
    SetLong("A leather boot of orcish design. Simple and inelegant, but quite protective. It is designed for the left foot.");
    SetMass(60);
    SetBaseCost("universal credits", 30);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_BOOT);
    SetRestrictLimbs(({"left foot"}));
}

void init(){
    ::init();
}
