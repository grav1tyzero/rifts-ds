#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Eastward, Vibrant Artery.");
    SetLong("The street outside Moxim�s tower in Chi-Town, stretching eastward, is a vibrant artery in a fortress-arcology, flanked by futuristic mega-crete and MDC metal structures. Regular patrols of Coalition troops in SAMAS power armor are a common sight, and citizens of varying classes move purposefully through the cityscape. The imposing architecture of the city reveals signs of neglect in the lower levels. However, the unbroken spirit of the residents is palpable. The city extends upwards into the artificial sky for miles, a symbol of the Coalition States� power.");

}
void init(){
    ::init();
}
