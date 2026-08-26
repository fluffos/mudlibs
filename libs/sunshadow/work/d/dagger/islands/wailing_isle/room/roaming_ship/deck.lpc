// Chernobog & Titania (4/8/22)
// The Wailing Isle - Roaming Ship Deck

#include <std.h>
#include "../../defs.h"
inherit VAULT;

int gangplank;

void create(){
    ::create();
    set_terrain(BOATS);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_name("the deck of a merchant ship");
    set_short("%^RESET%^%^CRST%^%^C094%^The Deck of a Merchant Ship%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C094%^Stately railings and panels define this fine ship, marking it as belonging to somebody with some wealth and resources. Three masts stand tall and erect, with rolled up %^C250%^white canvas sails%^C094%^ that yearn to feel the snapping of the %^C021%^s%^C026%^e%^C031%^a %^C021%^b%^C026%^r%^C031%^e%^C021%^e%^C026%^z%^C031%^e%^RESET%^%^C094%^ once again. The rigging is taut and tight; whomever captains this ship seems to appreciate order and tidiness. Most of the crew must be ashore currently, leaving you free to wander the stunning decks at leisure. The %^C101%^companionway%^C094%^ stairs lead down to the lower quarters, while a %^C101%^doorway%^C094%^ leads aft into the captain's quarters.\n\n%^RESET%^%^CRST%^%^C094%^There is a %^C058%^gangplank %^C094%^set aside on the deck that can be raised or lowered to the nearby dock.%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C123%^It smells of the %^C158%^briny%^C123%^ sea.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C087%^The %^C086%^waves%^C087%^ rock incessantly beneath you while %^C159%^gulls%^C087%^ cry overhead.%^CRST%^");
    set_items(([
        ({"masts", "sails", "rigging"}) : "%^RESET%^%^CRST%^%^C255%^These hatches are securely battened down, and the ship seems well secured for docking.%^CRST%^",
		"deck" : "%^RESET%^%^CRST%^%^C094%^The surface of the upper deck is highly polished and organized, its numerous containers, ropes, and rigging all properly stowed.%^CRST%^",
		({"companionway", "stairs"}) : "%^RESET%^%^CRST%^%^C094%^These simple stairs vanish into the %^C243%^dark passageways%^C094%^ beneath the deck.%^CRST%^",
        ]));
    set_exits(([
        "doorway" : SHIP"captainroom",
        "stairs" : SHIP"hallway",
        ]));
    set_door("ebony door", SHIP"captainroom", "doorway", "merchant_key_xx", "lock");
	set_door_description("ebony door", "%^CRST%^%^RESET%^%^C059%^Solid planks of stalwart ebony fill the doorway, bound together by bands of %^C058%^brass%^C059%^. The metal has been polished to an impressive gleam, and the wood has been varnished to bring out the rich hues. A %^C244%^keyhole%^C059%^ rests above the smooth curve of the door handle.%^CRST%^");
    set_locked("ebony door", 1, "lock");
    lock_difficulty("ebony door", 50, "lock");
    
    gangplank = 0;
}

void init(){
    ::init();
    add_action("unlock_fun", "unlock");
    add_action("lower_fun", "lower");
    add_action("raise_fun", "raise");
}

int lower_fun(string str){
    object player, ship, ship_location;
    
    if(!str) return 0;
    if(str != "gangplank" && str != "the gangplank") return 0;
    
    player = this_player();
    if(gangplank){
        message("info", "%^RESET%^%^CRST%^%^C059%^The gangplank has already been lowered.%^CRST%^", player);
        return 1;
    }
    
    ship = find_object_or_load("/d/dagger/islands/wailing_isle/obj/zephyr");
    if(!environment(ship)){
        switch(random(4)){
            case 0 : ship_location = find_object_or_load("/d/shadow/virtual/sea/shadow.dock"); break;
            case 1 : ship_location = find_object_or_load("/d/shadow/virtual/sea/torm.dock"); break;
            case 2 : ship_location = find_object_or_load("/d/shadow/virtual/sea/serakii.dock"); break;
            case 3 : ship_location = find_object_or_load("/d/shadow/virtual/sea/undead.dock"); break;
        }
        ship->move(ship_location);
    }
    ship_location = environment(ship);
    
    if(player->query_bound() || player->query_unconscious() || player->query_tripped()){
        player->send_paralyzed_message("info", player);
        return 1;
    }
    
    gangplank = 1;
    message("environment", "%^RESET%^%^CRST%^%^C058%^You lower the %^C136%^gangplank%^C058%^.%^CRST%^", player);
    message("environment", "%^RESET%^%^CRST%^%^C058%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ lowers the %^C136%^gangplank%^C058%^.%^CRST%^", this_object(), player);
    add_exit(base_name(ship_location), "gangplank");
    return 1;
}

int raise_fun(string str){
    object player;
    
    if(!str) return 0;
    if(str != "gangplank" && str != "the gangplank") return 0;
    
    player = this_player();
    
    if(player->query_bound() || player->query_unconscious() || player->query_tripped()){
        player->send_paralyzed_message("info", player);
        return 1;
    }
    if(!gangplank){
        message("info", "%^RESET%^%^CRST%^%^C059%^The gangplank has already been raised.%^CRST%^", player);
        return 1;
    }
    
    gangplank = 0;
    message("environment", "%^RESET%^%^CRST%^%^C058%^You raise the %^C136%^gangplank%^C058%^.%^CRST%^", player);
    message("environment", "%^RESET%^%^CRST%^%^C058%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ raises the %^C136%^gangplank%^C058%^.%^CRST%^", this_object(), player);
    remove_exit("gangplank");
    return 1;
}

int unlock_fun(string str){
    object player, room;
    if(!str) return 0;
    
    player = this_player();
    room = this_object();
    if(!present("sailor", room)) return 0;

    tell_object(player, "%^CRST%^%^RESET%^%^C101%^One of the sailors shoves you away from the door with a scowl. %^CRST%^%^RESET%^%^C255%^\"What do you think you're doing?\"");
    tell_room(room, "%^CRST%^%^RESET%^%^C101%^One of the sailors shoves "+player->query_cap_name()+"%^CRST%^%^RESET%^%^C101%^ away from the door with a scowl. %^CRST%^%^RESET%^%^C255%^\"What do you think you're doing?\"", player);
    return 1;
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

void reset(){
    object room;
    
    ::reset();
    room = this_object();
    while(!present("sailor 3", room)) new(MON"sailor")->move(room);
}

