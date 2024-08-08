#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("legwand");
    SetAdjectives( ({"courageous", "loyal", "independent", "athletic", "affectionate"}) );
    SetId(({"npc","mob","character","mobile","poodle"}));
    SetShort("Legwand the dog");
    SetLong("A rather majestic, obviously well-trained, powerful and athletic dog.");
    SetLevel(99);
    SetMelee(99);
    SetRace("dog");
    SetGender("male");
    SetPosition("sitting");
}

void init(){
    ::init();
    add_action("pet", "pet");
}

int pet(string str) {
    if(!str || present(str, environment(this_player())) != this_object()) {
        notify_fail("Pet who?\n");
        return 0;
    }
    write("You pet Legwand. He wags his tail happily!\n");
    say(this_player()->GetName() + " pets Legwand. He wags his tail happily!\n");
    return 1;
}
