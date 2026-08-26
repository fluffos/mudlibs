// Chernobog (8/30/22)
// Wailing Isle - The Zephyr

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("The Zephyr");
    set_id(({ "ship", "merchantman", "zephyr", "Zephyr", "the zephyr", "The Zephyr" }));
    set_short("%^RESET%^%^CRST%^%^C144%^T%^C101%^he %^C144%^Z%^C101%^ephyr%^C100%^, a grand %^C220%^m%^C214%^erc%^C220%^h%^C214%^an%^C220%^t %^C100%^vessel%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C100%^Sitting low in the water at the dock, this merchant ship is massive. Three masts rise up from a bulky hull, outfitted to carry cargo from port to port, and almost constantly abuzz from its crew working diligently. A stylish script has been applied along the side of the vessel, proclaiming this to be %^C255%^\"%^C144%^T%^C101%^he %^C144%^Z%^C101%^ephyr%^C255%^\"%^RESET%^%^C100%^.\n\n%^RESET%^%^CRST%^%^C100%^A gangplank is present, allowing one to board the ship.%^CRST%^");
    set_weight(100000);
    set_property("no animate", 1);
    set_no_clean(1);
}

void init(){
    ::init();
    add_action("board_fun","board");
}

int board_fun(string str){
    object player, room, ship;
    
    if(!str) return 0;
    if(!id(str)) return 0;
    
    player = this_player();
    room = environment(this_object());
    ship = find_object_or_load("/d/dagger/islands/wailing_isle/room/roaming_ship/deck");
    
    message("info", "%^RESET%^%^CRST%^%^C027%^You step across the gangplank and board the ship.%^CRST%^\n", player, room);
    message("info", "%^RESET%^%^CRST%^%^C027%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C027%^ steps across the gangplank and boards the ship.%^CRST%^", room, player);
    player->move_player(ship);
    return 1;
}

