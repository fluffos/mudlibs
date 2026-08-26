#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_property("indoors",0);
   set_property("light",1);
   set_name("intersection of the industrial section");
   set_short("%^RESET%^%^C244%^Intersection of %^RESET%^%^C098%^I%^C099%^n%^C141%^d%^C140%^u%^C141%^s%^C099%^t%^C098%^r%^C099%^i%^C141%^a%^C140%^l %^RESET%^%^C098%^W%^C099%^a%^C099%^y%^CRST%^");
   set_long("%^RESET%^%^RESET%^%^C244%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^RESET%^%^C241%^Shadovar fortress%^RESET%^%^C244%^, far in the sky above. It casts the entire city under a pall of %^RESET%^%^C241%^unrelenting darkness%^RESET%^%^C244%^. Beneath its %^C241%^shadow%^RESET%^%^C244%^, the m%^RESET%^%^C028%^o%^RESET%^%^C246%^t%^C247%^t%^C249%^l%^RESET%^%^C022%^e%^RESET%^%^C251%^d c%^RESET%^%^C022%^o%^RESET%^%^C249%^b%^C247%^b%^C246%^l%^C245%^e%^C246%^s%^C247%^t%^RESET%^%^C028%^o%^RESET%^%^C250%^n%^C244%^e streets in this part of the city appear freshly lain. On either side of the road are raised %^RESET%^%^C250%^m%^C248%^a%^C244%^r%^C248%^b%^C250%^le s%^RESET%^%^C244%^i%^C248%^d%^C241%^e%^C248%^w%^C244%^a%^C250%^lks%^C244%^, allowing safe travel for pedestrians on foot, and %^C241%^street lamps %^C244%^housing tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ line the avenue at regular intervals. This intersection lies at the center of a north-south thoroughfare along which much of the city's %^RESET%^%^C058%^manufacturing %^RESET%^%^C244%^occurs. The %^RESET%^%^C087%^air %^RESET%^%^C244%^is clotted with thick %^C255%^g%^C252%^r%^C250%^a%^y %^C247%^s%^C250%^m%^C252%^o%^C255%^k%^C252%^e %^RESET%^%^C250%^b%^C247%^i%^C255%^l%^C252%^l%^C255%^o%^C247%^w%^C255%^i%^C252%^n%^C250%^g %^RESET%^%^C244%^from the various %^RESET%^%^C052%^chimney stacks %^C244%^that rise into the %^C141%^g%^C140%^l%^C139%^o%^C140%^o%^C141%^m%^RESET%^%^C244%^. %^RESET%^%^C135%^S%^C141%^i%^C147%^g%^C141%^n%^C135%^s %^RESET%^%^C244%^indicate what can be found in each direction. To the east loom the city %^RESET%^%^C241%^gates%^RESET%^%^C244%^, tall and %^RESET%^%^C240%^i%^C241%^m%^C242%^p%^C243%^o%^C244%^s%^C242%^i%^C241%^n%^C240%^g%^RESET%^C244%^, while to the west is a sprawling building behind a tall %^RESET%^%^C241%^iron fence%^RESET%^%^C244%^.%^CRST%^\n");
   set_smell("default","%^RESET%^%^CRST%^%^C141%^The air carries a thousand scents of a busy city.%^CRST%^");
   set_listen("default","%^RESET%^%^CRST%^%^C099%^You hear the bustle of the citizens going about their day.%^CRST%^");
   set_items(([
        ({"street signs","plaques"}): "%^RESET%^%^C250%^S%^C249%^i%^C248%^l%^C247%^v%^C249%^e%^C250%^r %^RESET%^%^C250%^p%^C249%^l%^C248%^a%^C247%^q%^C248%^u%^C249%^e%^C250%^s %^RESET%^%^C244%^have been affixed to the %^RESET%^%^C241%^lamp posts %^RESET%^%^C244%^at each corner of the crossroads. They indicate what can be found should one travel to the east, west, north, or south. The neat, %^RESET%^%^C093%^l%^C099%^u%^C105%^m%^C111%^i%^C153%^n%^C147%^o%^C147%^u%^C141%^s %^RESET%^%^C135%^s%^C129%^c%^C093%^r%^C099%^i%^C105%^p%^C111%^t %^RESET%^%^C244%^that adorns them seems to %^RESET%^%^C093%^s%^C099%^h%^C141%^i%^C135%^f%^C129%^t %^RESET%^%^C244%^before your eyes, some manner of %^RESET%^%^C141%^enchantment %^RESET%^%^C244%^changing it to your native tongue.%^CRST%^",
        "fortress": "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^RESET%^%^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"street lamp", "glow globes"}): "%^RESET%^%^CRST%^%^C244%^Tall %^C241%^iron lamp posts %^RESET%^%^C244%^line the avenue at regular intervals. Tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ housed are within their %^RESET%^%^C051%^g%^C087%^l%^C123%^a%^C159%^s%^RESET%^%^C051%^s %^RESET%^%^C244%^cages, their %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^RESET%^%^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e%^C141%^n%^C135%^c%^C141%^e %^RESET%^%^C244%^allowing the normal-sighted people of the city to move around with relative ease without hindering the Nyctophiles.%^CRST%^",
        ({"cobblestones", "street", "road", "ground"}): "%^RESET%^%^CRST%^%^C244%^The streets here are freshly lain %^RESET%^%^C249%^cobblestones%^RESET%^%^C244%^, mostly in m%^RESET%^%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^RESET%^%^C249%^gray%^RESET%^%^C244%^. However, swaths of them have been painted with a %^RESET%^%^C022%^v%^C028%^e%^C029%^r%^C035%^d%^C041%^a%^C035%^n%^C029%^t %^RESET%^%^C028%^g%^C022%^l%^C028%^a%^C029%^z%^C035%^e%^RESET%^%^C244%^, making them stand out amongst the rest.%^CRST%^",
        ]));
   set_exits(([
      "north" : ROOMS "industry2",
      "east" : ROOMS "egate1",
      "west" : ROOMS "elf3",
   ]));
}

void init(){
    ::init();
    add_action("read_em", "read");
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int read_em(string str){
    if(!str) return 0;
    if(str == "north plaque" || str == "north sign") {
        tell_object(TP, "%^RESET%^%^CRST%^%^C250%^The p%^RESET%^%^C249%^l%^C248%^a%^C247%^q%^C248%^u%^C250%^e read:%^CRST%^\n\n%^RESET%^%^C093%^A%^C099%^r%^C105%^m%^C111%^o%^C153%^r%^RESET%^%^C147%^s%^C141%^m%^C135%^i%^C129%^t%^C128%^h%^RESET%^%^C127%^y%^CRST%^\n%^RESET%^%^C129%^W%^C135%^e%^C141%^a%^C147%^p%^C111%^o%^C105%^n%^RESET%^%^C099%^s%^C093%^m%^C099%^i%^C105%^t%^C111%^h%^RESET%^%^C147%^y%^CRST%^\n   %^RESET%^%^C088%^F%^C124%^o%^C125%^r%^C126%^g%^C127%^e%^CRST%^");
        if(!TP->query_invis() && !TP->query_hidden()) tell_room(TO, "" + TPQCN + " seems to be studying the street signs.");
        return 1;
        return 0;
    }
    
    if(str == "south plaque" || str == "south sign") {
        tell_object(TP, "%^RESET%^%^CRST%^%^C250%^The p%^RESET%^%^C249%^l%^C248%^a%^C247%^q%^C249%^u%^C250%^e reads:%^CRST%^\n\n%^RESET%^%^C093%^L%^C099%^u%^C105%^m%^C147%^b%^C141%^e%^C135%^r %^RESET%^%^C129%^m%^C128%^i%^C127%^l%^C126%^l%^CRST%^");
        if(!TP->query_invis() && !TP->query_hidden()) tell_room(TO, "" + TPQCN + " seems to be studying the street signs.");
        return 1;
        return 0;
    }
    
    if(str == "east plaque" || str == "east sign") {
        tell_object(TP, "%^RESET%^%^CRST%^%^C250%^The p%^RESET%^%^C249%^l%^C248%^a%^C247%^q%^C249%^u%^C250%^e reads:%^CRST%^\n\n%^RESET%^%^C093%^E%^C092%^a%^C091%^s%^C090%^t %^RESET%^%^C089%^G%^C088%^a%^C124%^t%^C125%^e%^CRST%^");
        if(!TP->query_invis() && !TP->query_hidden()) tell_room(TO, "" + TPQCN + " seems to be studying the street signs.");
        return 1;
        return 0;
    }
    
    if(str == "west plaque" || str == "west sign") {
        tell_object(TP, "%^RESET%^%^CRST%^%^C250%^The p%^RESET%^%^C249%^l%^C248%^a%^C247%^q%^C249%^u%^C250%^e reads:%^CRST%^\n\n%^RESET%^%^C099%^T%^C098%^h%^C099%^e %^RESET%^%^C098%^A%^C099%^c%^C141%^a%^C140%^d%^C141%^e%^C099%^m%^C098%^y%^CRST%^");
        if(!TP->query_invis() && !TP->query_hidden()) tell_room(TO, "" + TPQCN + " seems to be studying the street signs.");
        return 1;
        return 0;
    }
    
}

