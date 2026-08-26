#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_property("indoors",0);
   set_property("light",1);
   set_name("outside the armorsmithy");
   set_short("%^RESET%^%^C098%^I%^C099%^n%^C141%^d%^C140%^u%^C141%^s%^C099%^t%^C098%^r%^C099%^i%^C141%^a%^C140%^l %^RESET%^%^C098%^W%^C099%^a%^C099%^y%^CRST%^");
   set_long("%^RESET%^%^C244%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^RESET%^%^C241%^Shadovar fortress%^RESET%^%^C244%^, far in the sky above. It casts the entire city under a pall of %^RESET%^%^C241%^unrelenting darkness%^RESET%^%^C244%^. Beneath its%^RESET%^ %^C241%^shadow%^RESET%^%^C244%^, the m%^RESET%^%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d c%^RESET%^%^C246%^o%^RESET%^%^C247%^b%^C248%^b%^C249%^l%^C248%^e%^C247%^s%^C246%^t%^RESET%^%^C244%^o%^RESET%^%^C246%^n%^C247%^e %^RESET%^%^C244%^streets in this part of the city appear freshly lain. Here the sidewalks are made of simple %^RESET%^%^C249%^gray stone %^RESET%^%^C244%^and %^RESET%^%^C242%^s%^C243%^c%^C245%^u%^C246%^f%^C245%^f%^C244%^e%^C242%^d %^RESET%^%^C244%^from the work boots that constantly tread upon them. %^C241%^Street lamps %^RESET%^%^C244%^housing tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^RESET%^%^C134%^w %^RESET%^%^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ line the avenue at regular intervals. The %^RESET%^%^C087%^air %^RESET%^%^C244%^is clotted with thick %^C255%^g%^C252%^r%^C250%^a%^y %^C247%^s%^C250%^m%^C252%^o%^C255%^k%^C252%^e %^RESET%^%^C250%^b%^C247%^i%^C255%^l%^C252%^l%^C255%^o%^C247%^w%^C255%^i%^C252%^n%^C250%^g %^RESET%^%^C244%^from the various %^RESET%^%^C052%^chimney stacks %^RESET%^%^C244%^that rise into the %^RESET%^%^C141%^g%^C140%^l%^C139%^o%^C140%^o%^RESET%^%^C141%^m%^RESET%^%^C244%^. To the east is the entrance to a rather plain, but well-built building with a sign on the outside declaring it as the city %^RESET%^%^C248%^armorsmithy%^RESET%^%^C244%^. The road continues northward and to the south lies the main intersection of the thoroughfare along which much of the city's %^RESET%^%^C058%^manufacturing %^RESET%^%^C244%^occurs.%^CRST%^\n");
   set_smell("default","%^RESET%^%^CRST%^%^C141%^The air carries a thousand scents of a busy city.%^CRST%^");
   set_listen("default","%^RESET%^%^CRST%^%^C099%^You hear the bustle of the citizens going about their day.%^CRST%^");
   set_items(([
        "sign": "%^RESET%^%^C244%^A %^RESET%^%^C250%^s%^C249%^i%^C248%^l%^C247%^v%^C249%^e%^C250%^r %^RESET%^%^C249%^s%^C248%^i%^C247%^g%^C249%^n %^RESET%^%^C244%^has been affixed to the right side of the arched doorway of this sturdy building. The neat, %^RESET%^%^C093%^l%^C099%^u%^C105%^m%^C111%^i%^C153%^n%^C147%^o%^C147%^u%^C141%^s %^RESET%^%^C135%^s%^C129%^c%^C093%^r%^C099%^i%^C105%^p%^C111%^t %^RESET%^%^C244%^that adorns it seems to %^RESET%^%^C093%^s%^C099%^h%^C141%^i%^C135%^f%^C129%^t %^RESET%^%^C244%^before your eyes, some manner of %^RESET%^%^C141%^enchantment %^RESET%^%^C244%^changing it to your native tongue.%^CRST%^",
        "fortress": "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^RESET%^%^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"street lamp", "glow globes"}): "%^RESET%^%^CRST%^%^C244%^Tall %^C241%^iron lamp posts %^RESET%^%^C244%^line the avenue at regular intervals. Tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ housed are within their %^RESET%^%^C051%^g%^C087%^l%^C123%^a%^C159%^s%^RESET%^%^C051%^s %^RESET%^%^C244%^cages, their %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^RESET%^%^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e%^C141%^n%^C135%^c%^C141%^e %^RESET%^%^C244%^allowing the normal-sighted people of the city to move around with relative ease without hindering the Nyctophiles.%^CRST%^",
        ({"cobblestones", "street", "road", "ground"}): "%^RESET%^%^CRST%^%^C244%^The streets here are freshly lain %^RESET%^%^C249%^cobblestones%^RESET%^%^C244%^, mostly in m%^RESET%^%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^RESET%^%^C249%^gray%^RESET%^%^C244%^.%^CRST%^",
        ]));
   set_exits(([
      "north" : ROOMS "industry3",
      "east" : ROOMS "tharis_armor",
      "south" : ROOMS "industry",
   ]));
}

void init(){
    ::init();
    add_action("read_em", "read");
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int read_em(string str){
    if(!str) return 0;
    if(str == "sign") {
        tell_object(TP, "%^RESET%^%^C250%^This %^RESET%^%^C249%^s%^C248%^i%^C247%^g%^C249%^n%^RESET%^%^C250%^ reads:%^CRST%^\n\n%^RESET%^%^C093%^G%^C099%^u%^C105%^l%^C111%^t%^C153%^h%^C147%^r%^C147%^u%^C141%^n%^RESET%^%^C135%^'%^RESET%^%^C129%^s %^C093%^A%^C099%^r%^C105%^m%^C111%^o%^RESET%^%^C105%^r%^C105%^s%^C099%^m%^C093%^i%^C099%^t%^C105%^h%^RESET%^%^C111%^y%^CRST%^");
        if(!TP->query_invis() && !TP->query_hidden()) tell_room(TO, "" + TPQCN + " seems to be studying the sign.");
        return 1;
        return 0;
    }
}