#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("A road in the city");
    set_short("%^RESET%^%^CRST%^%^C244%^Outside the Bastion of the %^RESET%^%^C019%^E%^C020%^c%^C021%^l%^C027%^i%^C021%^p%^C020%^s%^C019%^e%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C244%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^C241%^Shadovar fortress%^C244%^, far in the sky above. It casts the entire city under a pall of %^C241%^unrelenting darkness%^C244%^. Beneath its %^C241%^shadow%^C244%^, the m%^RESET%^%^C028%^o%^RESET%^%^C246%^t%^C247%^t%^C249%^l%^RESET%^%^C022%^e%^RESET%^%^C251%^d c%^RESET%^%^C022%^o%^RESET%^%^C249%^b%^C247%^b%^C246%^l%^C245%^e%^C246%^s%^C247%^t%^RESET%^%^C028%^o%^RESET%^%^C250%^n%^C244%^e streets in this part of the city appear freshly lain. On either side of the main road are raised %^C250%^m%^C248%^a%^C244%^r%^C248%^b%^C250%^le s%^C244%^i%^C248%^d%^C241%^e%^C248%^w%^C244%^a%^C250%^lks%^C244%^, allowing safe travel for pedestrians on foot, and %^C241%^street lamps %^C244%^housing tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s %^RESET%^%^C244%^line the avenue at regular intervals. To the north is a %^C241%^compound %^C244%^surrounded by imposing walls of %^C241%^black stone%^C244%^, a monolith of military might nestled within the %^RESET%^%^C088%^h%^C124%^e%^C196%^a%^C124%^r%^C088%^t %^RESET%^%^C244%^of the east side. Directly south is the %^RESET%^%^C231%^c%^C225%^a%^C189%^r%^C231%^r%^C230%^i%^C194%^a%^C231%^g%^C159%^e %^RESET%^%^C231%^h%^C195%^o%^C153%^u%^C231%^s%^C189%^e%^RESET%^%^C244%^ and to the east is a busy %^RESET%^%^C183%^plaza%^C244%^, a towering %^C241%^obsidian obelisk %^C244%^at its center.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C141%^The air carries the thousand scents of a busy city.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C099%^The occasional shout and clash of weapons can be heard from the compound to the north.%^CRST%^");
    set_items(([
        ({"cobblestones", "street", "road", "ground"}): "%^RESET%^%^CRST%^%^C244%^The streets here are freshly lain %^C249%^cobblestones%^C244%^, mostly in m%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^C249%^gray%^C244%^. However, swaths of them have been painted with a %^RESET%^%^C022%^v%^C028%^e%^C029%^r%^C035%^d%^C041%^a%^C035%^n%^C029%^t %^C028%^g%^C022%^l%^C028%^a%^C029%^z%^C035%^e%^RESET%^%^C244%^, making them stand out amongst the rest.%^CRST%^",
        ({"street lamp", "glow globes"}): "%^RESET%^%^CRST%^%^C244%^Tall %^C241%^iron lamp posts %^C244%^line the avenue at regular intervals. Tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ housed are within their %^RESET%^%^C051%^g%^C087%^l%^C123%^a%^C159%^s%^RESET%^%^C051%^s %^RESET%^%^C244%^cages, their %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e%^C141%^n%^C135%^c%^C141%^e %^RESET%^%^C244%^allowing the normal-sighted people of the city to move around with relative ease without hindering the Nyctophiles.%^CRST%^",
        "fortress": "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"flagpole", "flag"}): "%^RESET%^%^CRST%^%^C248%^This flagpole towers above the %^RESET%^%^C058%^courtyard%^RESET%^%^C248%^, a flag emblazoned with a %^C241%^black starburst %^C248%^on a %^RESET%^%^C124%^r%^C160%^e%^C124%^d %^RESET%^%^C248%^background fluttering dramatically in the %^RESET%^%^C030%^wind%^RESET%^%^C248%^. The sheer height of the pole and size of the flag ensure its %^RESET%^%^C031%^vi%^C039%^s%^C038%^i%^C045%^b%^C014%^i%^C045%^l%^C038%^i%^C039%^t%^C031%^y %^RESET%^%^C248%^from well beyond the bastion's %^C241%^w%^C244%^a%^C247%^l%^C241%^ls%^RESET%^%^C248%^.%^CRST%^",
        ]));
    set_exits(([
        "east" : ROOMS"eastplaza",
        "west" : ROOMS"east3",
        "south" : ROOMS"office",
        "north" : "/d/player_houses/caledor/room/courtyard",
        ]));
    set_door("wooden gate", "/d/player_houses/caledor/room/courtyard", "north", 0, 0);
    //set_door("wooden gate", "/d/player_houses/caledor/room/courtyard", "north", "caledor_gate", "lock");
	//set_locked("wooden gate", 1, "lock");
    //lock_difficulty("wooden gate", 55, "lock");
    //set_lock_description("wooden gate", "lock", "%^RESET%^%^CRST%^%^C058%^This is a huge wooden bar that glides across to secure the gate.%^CRST%^");
	set_door_description("wooden gate", "%^RESET%^%^CRST%^%^C058%^Before you is a massive wooden gate bound together with what seems to be forged cold iron bands. A great edifice in the shape of a starburst emblazoned upon it.%^CRST%^");
}

void init(){
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

