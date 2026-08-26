// Maenoh (3/11/22)
// Tharis Reconstruction

#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("City boroughs");
    set_short("%^RESET%^%^CRST%^%^C244%^The %^RESET%^%^C098%^B%^C099%^o%^C141%^r%^C140%^o%^C141%^u%^C099%^g%^C098%^h%^C099%^s%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C244%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^C241%^Shadovar fortress%^C244%^, far in the sky above. It casts the entire city under a pall of %^C241%^unrelenting darkness%^C244%^. Beneath its %^C241%^shadow%^C244%^, the m%^RESET%^%^C028%^o%^RESET%^%^C246%^t%^C247%^t%^C249%^l%^RESET%^%^C022%^e%^RESET%^%^C251%^d c%^RESET%^%^C022%^o%^RESET%^%^C249%^b%^C247%^b%^C246%^l%^C245%^e%^C246%^s%^C247%^t%^RESET%^%^C028%^o%^RESET%^%^C250%^n%^C244%^e streets in this part of the city appear freshly lain. On either side of the road are raised %^C250%^m%^C248%^a%^C244%^r%^C248%^b%^C250%^le s%^C244%^i%^C248%^d%^C241%^e%^C248%^w%^C244%^a%^C250%^lks%^C244%^, allowing safe travel for pedestrians on foot. Similarly, the buildings here - a collection of %^RESET%^%^C098%^businesses%^C244%^, %^RESET%^%^C099%^apartments%^RESET%^%^C244%^, and modest, but lovely, %^RESET%^%^C141%^homes %^RESET%^%^C244%^- are in pristine condition and constructed from the finest of materials. Pruned %^C196%^f%^C197%^r%^C203%^u%^C202%^i%^C208%^t %^C214%^t%^C131%^r%^C132%^e%^C126%^e%^C127%^s %^RESET%^C244%^line the avenue at regular intervals, as do %^RESET%^%^C241%^street lamps %^C244%^housing tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^.%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C141%^The %^C196%^c%^C197%^i%^C198%^t%^C204%^r%^C203%^u%^C202%^s%^C208%^y%^C141%^-%^C125%^s%^C126%^w%^C127%^e%^C128%^e%^C129%^t%^RESET%^%^C141%^ smell of the fruit trees permeates the air.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C099%^You hear the bustle of the citizens going about their day.%^CRST%^");
    set_items (([
        ({"cobblestones", "street", "road", "ground"}): "%^RESET%^%^CRST%^%^C244%^The streets here are freshly lain %^C249%^cobblestones%^C244%^, mostly in m%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^C249%^gray%^C244%^. However, swaths of them have been painted with a %^RESET%^%^C022%^v%^C028%^e%^C029%^r%^C035%^d%^C041%^a%^C035%^n%^C029%^t %^C028%^g%^C022%^l%^C028%^a%^C029%^z%^C035%^e%^RESET%^%^C244%^, making them stand out amongst the rest.%^CRST%^",
        ({"street lamp", "glow globes"}): "%^RESET%^%^CRST%^%^C244%^Tall %^C241%^iron lamp posts %^C244%^line the avenue at regular intervals. Tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ housed are within their %^RESET%^%^C051%^g%^C087%^l%^C123%^a%^C159%^s%^RESET%^%^C051%^s %^RESET%^%^C244%^cages, their %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e%^C141%^n%^C135%^c%^C141%^e %^RESET%^%^C244%^allowing the normal-sighted people of the city to move around with relative ease without hindering the Nyctophiles.%^CRST%^",
        "fortress": "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"homes", "apartments", "businesses", "buildings"}): "%^RESET%^%^CRST%^%^C244%^The buildings here are a collection of well-built %^RESET%^%^C141%^homes%^RESET%^%^C244%^, %^C099%^apartments%^RESET%^%^C244%^, and %^C098%^businesses%^RESET%^%^C244%^. Everything from the %^C099%^p%^C098%^a%^C141%^i%^C098%^n%^C099%^t%^RESET%^%^C241%^ to the %^C248%^mortar %^C244%^between the %^C241%^b%^C245%^r%^C248%^i%^C245%^c%^C241%^ks %^C244%^seems relatively %^C250%^pristine%^C244%^, so either this area is new construction or very well maintained.%^CRST%^",
        "trees": "%^RESET%^%^CRST%^%^C244%^Pruned %^C196%^f%^C197%^r%^C203%^u%^C202%^i%^C208%^t %^C214%^t%^C131%^r%^C132%^e%^C126%^e%^C127%^s %^RESET%^%^C244%^line the avenue, their %^C196%^c%^C197%^i%^C198%^t%^C204%^r%^C203%^u%^C202%^s%^C208%^y%^C244%^-%^C125%^s%^C126%^w%^C127%^e%^C128%^e%^C129%^t%^RESET%^%^C244%^ scent thick in the air. They bear delicious looking %^RESET%^%^C124%^a%^C196%^p%^C160%^p%^C196%^l%^C124%^e%^C160%^s%^RESET%^%^C244%^, %^RESET%^%^C202%^o%^C166%^r%^C208%^a%^C166%^n%^C202%^g%^C166%^e%^C208%^s%^RESET%^%^C244%^, %^RESET%^%^C190%^p%^C191%^e%^C192%^a%^C191%^r%^C190%^s%^RESET%^%^C244%^, %^C166%^g%^C167%^r%^C168%^a%^C167%^p%^C166%^e%^C208%^f%^C209%^r%^C210%^u%^C211%^i%^C210%^t%^C209%^s%^RESET%^%^C244%^, and %^RESET%^%^C089%^p%^C090%^l%^C091%^u%^C090%^m%^C089%^s%^RESET%^%^C244%^. There is an unusually %^C241%^dark%^RESET%^%^C244%^, %^C062%^o%^C063%^i%^C069%^l%^C062%^y %^RESET%^%^C244%^sap that bleeds from beneath their %^RESET%^%^C058%^bark%^RESET%^%^C244%^.%^CRST%^",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}