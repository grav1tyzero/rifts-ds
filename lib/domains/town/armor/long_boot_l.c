#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("riding boot");
    SetId(({"boot"}));
    SetAdjectives(({"long","riding","black","leather","left"}));
    SetShort("a long riding boot");
    SetLong("A long riding boot, made of black leather. It is "+
            "designed for wear on the left foot and leg.");
    SetMass(40);
    SetBaseCost("universal credits",75);
    SetProtection(BLUNT,5);
    SetProtection(BLADE,5);
    SetProtection(KNIFE,5);
    SetArmorType(A_LONG_BOOT);
    SetRestrictLimbs(({"left foot","left leg"}));
}

void init(){
    ::init();
}
