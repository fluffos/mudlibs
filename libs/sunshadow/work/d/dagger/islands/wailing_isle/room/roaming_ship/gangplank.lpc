// Chernobog & Titania (4/8/22)
// The Wailing Isle - Roaming Ship Gangplank

#include <std.h>
#include "../../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_name("a wooden gangplank");
    set_short("%^RESET%^%^CRST%^%^C094%^A Wooden Gangplank%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C094%^This wide plank of wood stretches between the land and the %^C096%^majestic ship%^C094%^ docked here. Lettering across the bow of the vessel declares it to be %^C027%^\"The Zephyr\"%^C094%^. A far drop below, the %^C123%^b%^C051%^r%^C087%^i%^C159%^n%^C158%^y %^C122%^s%^C123%^e%^C051%^a%^RESET%^%^C094%^ laps against the fine hull of the ship, the constant %^C095%^un%^C096%^du%^C095%^la%^C096%^ti%^C095%^ng mo%^C096%^ti%^C095%^on%^RESET%^%^C094%^ of the %^C025%^waves%^C094%^ making crossing somewhat precarious. The wood is sturdy and thick beneath your feet.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C123%^It smells of the %^C158%^briny%^C123%^ sea.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C087%^The %^C086%^waves%^C087%^ rock incessantly beneath you while %^C159%^gulls%^C087%^ cry overhead.%^CRST%^");
    set_items(([
        "dock" : "%^RESET%^%^CRST%^%^C101%^Many ships of various sizes and purposes line the docks. It's a flurry of activity at any time, day or night.%^CRST%^",
        "ship" : "%^RESET%^%^CRST%^%^C094%^This grand ship is huge, featuring three full masts, their %^C253%^white sails%^C094%^ currently rolled up while docked. Her wide wooden body %^C101%^gleams%^C094%^, showing off her decorative rails and splended hull. A few %^C096%^sailors%^C094%^ can be seen wandering around her decks.%^CRST%^",
        ]));
    set_exits(([
        "deck" : SHIP"deck",
        ]));
    set_pre_exit_functions(({"deck"}),({"sailor_guards"}));
}

void reset(){
    object room;
    
    ::reset();
    room = this_object();
    while(!present("sailor 2", room)) new(MON"sailor")->move(room);
}

int sailor_guards(){
    object player, room;
    player = this_player();
    room = environment(player);
    
    if(player->query_true_invis()) return 1;
    if(!present("sailor")) return 1;
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^The sailors block your way, waving you off.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C101%^The sailors block "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^'s way, waving them off.%^CRST%^", player);
    return 0;
}

