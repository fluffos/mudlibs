#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("Outside the Academy");
    set_short("%^RESET%^%^CRST%^%^C244%^Outside the %^RESET%^%^C098%^A%^C099%^c%^C141%^a%^C140%^d%^C141%^e%^C099%^m%^C098%^y%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C244%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^C241%^Shadovar fortress%^RESET%^%^C244%^, far in the sky above. It casts the entire city under a pall of %^C241%^unrelenting darkness%^C244%^. Beneath its %^C241%^shadow%^C244%^, the m%^RESET%^%^C028%^o%^RESET%^%^C246%^t%^C247%^t%^C249%^l%^RESET%^%^C022%^e%^RESET%^%^C251%^d c%^RESET%^%^C022%^o%^RESET%^%^C249%^b%^C247%^b%^C246%^l%^C245%^e%^C246%^s%^C247%^t%^RESET%^%^C028%^o%^RESET%^%^C250%^n%^C244%^e streets in this part of the city appear freshly lain. On either side of the road are raised %^C250%^m%^C248%^a%^C244%^r%^C248%^b%^C250%^le s%^C244%^i%^C248%^d%^C241%^e%^C248%^w%^C244%^a%^C250%^lks%^C244%^, allowing safe travel for pedestrians on foot, and %^C241%^street lamps %^C244%^housing tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ line the avenue at regular intervals. To the south is a majestic, %^C241%^multi-spired %^C244%^wonder of %^RESET%^%^C055%^architecture %^RESET%^%^C244%^rising high into the air, %^RESET%^%^C201%^highlighted %^C244%^by dancing %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^. Tall %^C241%^stone walls %^C244%^encircle the building with gothic style %^RESET%^%^C241%^gargoyles %^C124%^leering %^C244%^down at the streets below and ornate %^C241%^iron gates %^C244%^barring passage to a large %^RESET%^%^C022%^c%^C028%^o%^C034%^u%^C040%^rty%^C034%^a%^C028%^r%^C022%^d %^RESET%^%^C244%^beyond. From here, more unique structures can be seen looming on the %^RESET%^%^C098%^h%^C097%^o%^C096%^r%^C095%^i%^C096%^z%^C097%^o%^C098%^n %^C244%^on all sides, %^C189%^magical %^C159%^i%^C153%^lu%^C231%^mi%^C183%^na%^C189%^ti%^C194%^o%^C225%^n %^RESET%^%^C244%^creating an awe-inspiring landscape within the %^RESET%^%^C241%^gloom%^C244%^. Further east lies the %^C058%^industrial center %^RESET%^%^C244%^and to the west, a large %^RESET%^%^C099%^plaza%^RESET%^%^C244%^.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C141%^The air carries a thousand scents of a busy city.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C099%^You hear the bustle of the citizens going about their day.%^CRST%^");
    set_items(([
        "fortress": "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"street lamp", "glow globes"}): "%^RESET%^%^CRST%^%^C244%^Tall %^C241%^iron lamp posts %^C244%^line the avenue at regular intervals. Tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ housed are within their %^RESET%^%^C051%^g%^C087%^l%^C123%^a%^C159%^s%^RESET%^%^C051%^s %^RESET%^%^C244%^cages, their %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e%^C141%^n%^C135%^c%^C141%^e %^RESET%^%^C244%^allowing the normal-sighted people of the city to move around with relative ease without hindering the Nyctophiles.%^CRST%^",
        ({"cobblestones", "street", "road", "ground"}): "%^RESET%^%^CRST%^%^C244%^The streets here are freshly lain %^C249%^cobblestones%^C244%^, mostly in m%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^C249%^gray%^C244%^. However, swaths of them have been painted with a %^RESET%^%^C022%^v%^C028%^e%^C029%^r%^C035%^d%^C041%^a%^C035%^n%^C029%^t %^C028%^g%^C022%^l%^C028%^a%^C029%^z%^C035%^e%^RESET%^%^C244%^, making them stand out amongst the rest.%^CRST%^",
        "architecture": "%^RESET%^%^CRST%^%^C244%^From here you can see that some unique architecture has been erected in the northeast and southeast quadrants of the city. In the northeast, the buildings resemble towering black stalagmites %^C231%^s%^C183%^h%^C189%^i%^C194%^m%^C195%^m%^C225%^e%^C230%^r%^C159%^i%^C153%^n%^C231%^g %^RESET%^%^C244%^with %^RESET%^%^C046%^p%^C047%^h%^C048%^o%^C049%^s%^C050%^p%^C051%^h%^C087%^o%^C086%^r%^C085%^e%^C084%^s%^C083%^c%^C082%^e%^C119%^n%^C120%^t %^C121%^l%^C122%^i%^C123%^c%^RESET%^%^C040%^h%^C041%^e%^C042%^n%^RESET%^%^C244%^. Carved directly from the rock are elegant archways, lofty %^C242%^balconies%^C244%^, and %^C255%^w%^C250%^e%^C255%^b%^C244%^-like walkways connecting the structures. The buildings in the southeast section are more traditional in make and %^C241%^gothic %^C244%^by design, featuring pointed archways, flying buttresses, and %^RESET%^%^C053%^s%^C054%^t%^C055%^a%^C056%^i%^C057%^n%^C089%^e%^C090%^d%^RESET%^%^C244%^-%^C091%^g%^C092%^l%^C093%^a%^C057%^s%^C063%^s %^RESET%^%^C244%^windows.%^CRST%^",
        ({"building", "academy"}): "%^RESET%^%^CRST%^%^C244%^A sprawling %^C241%^stone building %^C244%^can be seen through the tall %^C241%^iron gates%^C244%^, with two obvious wings and a %^C022%^l%^C028%^u%^C034%^s%^C022%^h %^C022%^c%^C028%^o%^C034%^u%^C040%^rty%^C034%^a%^C028%^r%^C022%^d g%^C028%^a%^C034%^rd%^C028%^e%^RESET%^%^C022%^n %^RESET%^%^C244%^front and center. Based on the %^RESET%^%^C058%^books %^C244%^carried by most of the people traversing the %^C248%^pathways %^C244%^bisecting the quad, this appears to be an academy of some sort.%^CRST%^",
        ]));
    set_exits(([
        "east" : ROOMS"industry",
        "west" : ROOMS"eastplaza",
        ]));
}

void init(){
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

