#include <lib.h>              /* see this everywhere */
#include <armor_types.h>     /* a listing of armour types */
#include <damage_types.h>     /* a listing of damage types */

inherit LIB_ARMOR;           /* the armour inheritable */

static void create() {
    armor::create();         /* call create() in armor.c */
    SetKeyName("juicer plate armor");
    SetId( ({ "plate", "juicer plate", "a rusty armor" }) );
    SetAdjectives( ({ "rusty", "juicer", "plate" }) );
    SetShort("a busted ass juicer plate armor");
    SetLong("A rusty armor which will be better than nothing on your body.");
    SetMass(75);
    SetValue(200);
    SetDamagePoints(1000);    
    SetProtection(ALL_DAMAGE, 100);   /* SetProtection() sets the sort of */
    SetProtection(ALL_EXTERNAL_DAMAGE, 100);   /* protection for a given damage type */
    SetProtection(BLADE, 100);
	SetProtection(PIERCE, 100);
    SetArmorType(A_BODY_ARMOR);     /* set what kind of armour this is */
}