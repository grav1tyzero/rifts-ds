#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <modules.h>

inherit LIB_ITEM;
inherit MODULES_ARMOR;
inherit MODULES_CREATE;
inherit MODULES_MAPPING;
inherit MODULES_GENERIC;
inherit MODULES_ROOM;
inherit MODULES_FILE;
inherit MODULES_MONEY;
inherit MODULES_READ;
inherit MODULES_DOOR;

static void create(){
    item::create();
    SetKeyName("wiztool");
    SetId( ({ "tool", "wiztool", "tanstaafl"  }) );
    SetAdjectives( ({ "tool","obsidian","wizard","wizard's","wiztool" }) );
    SetShort("%^RED%^The Creation Wiz-Tool%^RESET%^ %^BOLD%^%^YELLOW%^1.0%^RESET%^");
    SetLong("This is an Admin Wiz-Tool see '%^BOLD%^%^GREEN%^help staff%^RESET%^' for more information.");
    SetProperties(([
        "no steal" : 1,
      ]));
    SetDamagePoints(50);
    SetClass(100);
    SetMass(100);
    SetNoCondition(1);
    SetWeaponType("blunt");
    SetHands(2);
    SetDamageType(BLUNT);
}
void init(){
    ::init();
}

int CanSell() { return 0; }
