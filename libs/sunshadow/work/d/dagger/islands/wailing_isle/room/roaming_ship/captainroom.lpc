// Chernobog & Titania (4/8/22)
// The Wailing Isle - Roaming Ship Captain's Quarters

#include <std.h>
#include "../../defs.h"
inherit VAULT;

int guarded;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("captain's quarters");
    set_short("%^RESET%^%^CRST%^%^C138%^The Captain's Quarters%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C138%^Windows overlooking the %^C081%^h%^C080%^y%^C079%^p%^C078%^n%^C079%^o%^C080%^t%^C081%^i%^C080%^c %^C079%^s%^C080%^e%^C081%^a%^RESET%^%^C138%^ spill %^C144%^light%^C138%^ into this well appointed cabin, which could only belong to the captain of this mighty vessel. A %^C132%^large bed%^C138%^ lines the wall beneath the windows, covered in %^C139%^c%^C140%^o%^C141%^m%^C135%^f%^C134%^o%^C133%^r%^C139%^t%^C140%^a%^C141%^b%^C135%^l%^C134%^e %^C133%^q%^C139%^u%^C140%^i%^C141%^l%^C135%^t%^C134%^s%^RESET%^%^C138%^ and %^C137%^f%^C136%^u%^C130%^r%^C137%^s%^RESET%^%^C138%^, and off to the side is a %^C101%^wardrobe%^C138%^, its %^C159%^m%^C153%^i%^C152%^r%^C159%^ro%^C152%^r%^C153%^e%^C159%^d d%^C153%^o%^C152%^o%^C159%^rs%^C138%^ reflecting the stately room. The smooth %^C101%^wooden floor%^C138%^ is covered by a %^C160%^p%^C088%^a%^C089%^t%^C095%^t%^C096%^e%^C095%^r%^C089%^n%^C088%^e%^C160%^d r%^C088%^e%^C160%^d r%^C088%^u%^C160%^g%^RESET%^%^C138%^ that exemplifies opulence. An %^C243%^impressive table%^RESET%^%^C138%^ sits off to one side, its fine details carved from %^C059%^he%^C058%^a%^C243%^v%^C059%^y da%^C243%^r%^C059%^k w%^C243%^o%^C059%^od%^RESET%^%^C138%^, and its surface is strewn with %^C143%^maps%^C138%^ and %^C131%^navigational tools%^C138%^. Dancing %^C160%^f%^C088%^l%^C089%^a%^C088%^m%^C160%^e%^C166%^s%^RESET%^%^C138%^ within the %^C247%^glass sconces%^C138%^ that line the walls, casting a %^C191%^w%^C192%^a%^C191%^r%^C192%^m g%^C191%^l%^C192%^o%^C191%^w%^RESET%^%^C138%^ over the room.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C140%^The %^C139%^s%^C140%^e%^C139%^du%^C140%^c%^C139%^ti%^C140%^v%^C139%^e sc%^C140%^en%^C139%^ts%^C140%^ of %^C146%^va%^C140%^nil%^C146%^la%^C140%^ and %^C146%^s%^C140%^an%^C146%^dalw%^C140%^oo%^C146%^d%^RESET%^%^C140%^ come as a bit of a surprise.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C136%^The %^C137%^wooden panels%^C136%^ creak in time with the %^C137%^lull%^C136%^ of the ship.%^CRST%^");
    set_items(([
        ({"flames", "sconces"}) : "%^RESET%^%^CRST%^%^C131%^The %^C196%^fla%^C124%^m%^C196%^es%^C131%^ burn brightly in their %^C245%^glass sconces%^C131%^, without any hints of oil or even candles present.%^CRST%^",
		"windows" : "%^RESET%^%^CRST%^%^C244%^A panel of 8 small square windows overlook the %^C039%^sea%^C244%^ from the aft of the ship.%^CRST%^",
		({"quilts", "furs", "bed"}) : "%^RESET%^%^CRST%^%^C153%^This bed looks luscious and irresistibly soft, with %^C152%^feathery pillows%^C153%^, %^C060%^dark blankets%^C153%^, and %^C058%^furs%^C153%^ for warmth. The captain seems to be no stranger to luxury.%^CRST%^",
		"wardrobe" : "%^RESET%^%^CRST%^%^C243%^The wardrobe is large and features two doors, along with a partitioned section at the bottom which holds bottles of %^C060%^wine%^C243%^ and %^C060%^spirits%^C243%^. The two doors of the wardrobe open outward, and the center of each is carved with a coiled, %^C066%^serpentine dragon%^RESET%^%^C243%^.%^CRST%^",
		"rug" : "%^RESET%^%^CRST%^%^C160%^At a glance the plush rug appears to feature a pattern of %^C029%^tu%^C030%^rq%^C036%^uo%^C035%^is%^C029%^e c%^C030%^re%^C036%^sc%^C035%^en%^C029%^ts%^RESET%^%^C160%^ entwined with %^C035%^vines%^C160%^ and %^C030%^flowers%^RESET%^%^C160%^, but a closer look delightfully reveals the shapes are actually long-necked, %^C029%^gr%^C030%^ac%^C036%^ef%^C035%^ul %^C029%^bi%^C030%^rd%^C036%^s%^RESET%^%^C160%^.%^CRST%^",
		({"table", "map", "maps", "navigational tools"}) : "%^RESET%^%^CRST%^%^C045%^This heavy table features elaborate carvings in the %^C059%^d%^C058%^a%^C059%^rk%^C045%^, %^C059%^strong wo%^C058%^o%^C059%^d%^C045%^. The surface is strewn with maps and charts, as if someone was recently studying them. The maps focus on the %^C044%^Saakrune Sea%^C045%^ and its myriad islands. A %^C117%^sextant%^C045%^ and a %^C117%^compass%^C045%^ sit nearby.%^CRST%^",
		({"walls", "painting"}) : "%^RESET%^%^CRST%^%^C101%^The walls are smooth planks of fine wood, which are polished to a shine. Heavy %^C060%^ve%^C061%^lv%^C060%^et c%^C061%^u%^C060%^rtai%^C061%^n%^C060%^s%^RESET%^%^C101%^ soften the hard angles of the room, and a few paintings add color and culture. The paintings are thematically nautical - a %^C158%^lighthouse%^C101%^, some %^C087%^ships%^C101%^, and there is even a conservative painting of a trio of %^C075%^sirens%^C101%^ singing out from atop some rocks.%^CRST%^",
        ]));
    set_exits(([
        "doorway" : SHIP"deck",
        ]));
    set_door("ebony door", SHIP"deck", "doorway", 0);
	set_door_description("ebony door", "%^CRST%^%^RESET%^%^C059%^Solid planks of stalwart ebony fill the doorway, bound together by bands of %^C058%^brass%^C059%^. The metal has been polished to an impressive gleam, and the wood has been varnished to bring out the rich hues. A %^C244%^keyhole%^C059%^ rests above the smooth curve of the door handle.%^CRST%^");
    set_locked("ebony door", 1, "lock");
    set_search("map", (:this_object(),"search_maps":));
    set_search("maps", (:this_object(),"search_maps":));
    guarded = 1;
}

void init(){
    ::init();
    add_action("retrieve_fun", "retrieve");
}

void reset(){
    ::reset();
    guarded = 1;
}

void search_maps(){
    object player, room, katerina;
    int power;
    
    player = this_player();
    room = environment(player);
    
    if(guarded && !present("katerina")){
        power = max(({ player->query_level() / 10, 1 }));
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^As you attempt to poke through the charts on the table, you hear %^C144%^someone %^C101%^clear her throat behind you...%^CRST%^\n");
        tell_room(room, "%^RESET%^%^CRST%^%^C101%^As "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ attempts to poke through the charts on the table, you see a %^C144%^woman %^C101%^enter the room, clearing her throat with an arched brow.%^CRST%^\n", player);
        katerina = new(MON"katerina");
        katerina->move(room);
        katerina->set_powerlevel(power);
        if(!player->query_invis() || !player->query_hidden()) katerina->force_me("say Those do not belong to you, trespasser.");
        else katerina->force_me("emoteat katerina %^RESET%^%^CRST%^%^C101%^$M looks about the room warily.%^CRST%^");
        guarded = 0;
        return;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C144%^These are maps of the Saakrune and Dagger Seas, with notes here and there about the various routes that merchant ships have plotted to steer clear of dangerous waters.%^CRST%^");
    if(player->query("wailing isle quest") == 9) tell_object(player, "\n%^RESET%^%^CRST%^%^C101%^Ah, there they are. The trade route maps that Mister Brookes is looking for. You could easily %^C100%^retrieve %^C101%^them and be on your way.%^CRST%^");
    return;
}

int retrieve_fun(string str){
    object player, room, katerina, map;
    
    if(!str) return 0;
    if(str != "map" && str != "maps" && str != "charts") return 0;
    
    player = this_player();
    room = environment(player);
    
    if(katerina = present("katerina", room) && (!player->query_invis() || !player->query_hidden())){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^As you try to search among the charts, an odd blast of wind knocks you away. The captain narrows her eyes suspiciously.%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C059%^As "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ tries to search among the charts, an odd blast of wind knocks them away. The captain narrows her eyes suspiciously.%^CRST%^", player);
        katerina->force_me("say You should leave.");
        return 1;
    }
    
    if(player->query("wailing isle quest") == 9){
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^You quickly grab the %^C144%^map%^C101%^, rolling it up and pocketing it.%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C101%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ searches among the charts on the table, rolling up a %^C144%^map %^C101%^and pocketing it.%^CRST%^", player);
        map = new(OBJ"map");
        map->move(player);
        player->set("wailing isle quest", 10);
    }
    else{
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't see anything of particular interest among the charts.%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ searches among the charts on the table.%^CRST%^", player);
    }
    return 1;
}

