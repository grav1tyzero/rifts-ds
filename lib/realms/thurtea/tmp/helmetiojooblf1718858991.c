#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

static void create(){
    armor::create();
    SetKeyName("helmet");
    SetAdjectives( ({"iron", "thick", "horned", "formidable", "protective"}) );
    SetId( ({"helm", "headgear", "cover"}) );
    SetShort("a horned viking helmet");
    SetLong("Vikings didn't really wear horned helmets into combat, but this one does look formidable with its large bull horns and thick iron construction. It should prove very protective.");
    SetMass(200);
    SetArmorType(A_HELMET);
    SetProtection(KNIFE, 5);
    SetProtection(COLD, 5);
}
void init(){
    ::init();
}
