#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Moxim's Mystical, Arcane Sanctuary.");
    SetLong("Moxim�s room, a secluded tower, is a sanctuary of arcane power. Mystic symbols etched into the walls pulse with light, providing constant protection. A large oaken table holds magical artifacts, each with its own story. A massive bookshelf covers one wall, filled with tomes of ancient knowledge from countless dimensions. A large magic circle in the room�s center serves as the site for opening rifts, the air around it crackling with residual energy. Despite the mystical atmosphere, there are touches of comfort: a plush chair by the fire and a small bed in one corner.");
}
void init(){
    ::init();
}
