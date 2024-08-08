#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Eastward, Vibrant Artery.");
    SetLong("This bustling crossroads in the fortress-arcology of Chi-Town is nestled between towering mega-crete and MDC metal structures. Regular patrols of Coalition troops in gleaming SAMAS power armor add a sense of order to the lively scene. Citizens from all walks of life navigate the cityscape, their purposeful strides echoing off the imposing architecture. Despite the grandeur, signs of neglect are visible in the lower levels, contrasting with the resilience of the residents. The city�s skyline, reaching for the artificial sky, serves as a constant reminder of the Coalition States� dominance. Exits lead west, back towards the heart of the city, and further east into the sprawling metropolis.");

}
void init(){
    ::init();
}
