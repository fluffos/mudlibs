// Chernobog & Titania (4/11/22)
// The Wailing Isle - Roaming Ship Galley

#include <std.h>
#include "../../defs.h"
#define search_herbs ({ "alfalfa", "skullcap", "thyme", "basil", "cinnamon", "garlic", "ginger", "parsley", "red pepper", "rosemary", "tea", "vanilla", "saffron", "clove", "bay" })

inherit ROOM;

int searchflag;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("the galley");
    set_short("%^RESET%^%^CRST%^%^C245%^The Galley");
    set_long("%^RESET%^%^CRST%^%^C245%^Most of the small kitchen is dominated by an %^C059%^iron stove%^C245%^ that hangs from the ceiling by %^C243%^h%^C247%^e%^C243%^a%^C247%^v%^C243%^y %^C247%^c%^C243%^h%^C247%^a%^C243%^i%^C247%^n%^C243%^s%^RESET%^%^C245%^, and the floor and walls are covered with %^C253%^old tin%^RESET%^%^C245%^, all in an effort to keep from setting the ship on fire. A %^C100%^table%^C245%^ off to one side provides a space for chopping %^C124%^m%^C130%^e%^C131%^a%^C125%^t%^C124%^s%^RESET%^%^C245%^ and %^C082%^v%^C076%^e%^C070%^g%^C082%^e%^C083%^t%^C084%^a%^C082%^b%^C046%^l%^C040%^e%^C034%^s%^RESET%^%^C245%^, just below a row of hanging %^C058%^pots%^C245%^ and %^C058%^pans%^C245%^. A few %^C100%^barrels%^C245%^ of %^C101%^pr%^C107%^ov%^C113%^is%^C107%^io%^C101%^ns%^RESET%^%^C245%^ are tucked away in a corner, and a small %^C100%^pantry%^C245%^ attached to the wall reveals some %^C196%^s%^C124%^c%^C130%^a%^C136%^n%^C142%^t %^C196%^s%^C124%^p%^C130%^i%^C136%^c%^C142%^e%^C196%^s%^RESET%^%^C245%^.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C130%^There is a lingering scent of %^C124%^meat%^C130%^ and %^C136%^spice%^C130%^.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C137%^T%^C138%^h%^C137%^e r%^C138%^a%^C137%^ttli%^C138%^n%^C137%^g of %^C143%^pots%^C137%^ a%^C138%^n%^C137%^d %^C143%^pans%^C137%^ ke%^C138%^e%^C137%^ps r%^C138%^h%^C137%^yt%^C138%^h%^RESET%^%^C137%^m w%^C138%^i%^C137%^th t%^C138%^h%^C137%^e r%^C138%^o%^C137%^ll of t%^C138%^h%^C137%^e wa%^C138%^v%^C137%^es.%^CRST%^");
    set_items(([
        ({"barrels", "pantry"}) : "%^RESET%^%^CRST%^%^C245%^Being between voyages, the food stocks are currently pretty low, but you might be able to find something tasty if you search around.%^CRST%^",
		({"pots", "pans"}) : "%^RESET%^%^CRST%^%^C142%^The copper pots and pans look new and shiny.%^CRST%^",			
		({"walls", "floor","tin"}) : "%^RESET%^%^CRST%^%^C153%^The walls and floor are kept tidy and covered by some old tin to prevent flames from catching.%^CRST%^",		
		({"table", "oven"}) : "%^RESET%^%^CRST%^%^C245%^This small oven allows the ship's cook to provide the crew with some heartier meals such as %^C058%^stews%^C245%^ and %^C052%^fresh meat%^RESET%^%^C245%^. It hangs from the ceiling by %^C059%^heavy chains%^C245%^ to assure some stability from the incessant rocking of the ship.%^CRST%^",
        ({"stove", "chains"}) : "%^RESET%^%^CRST%^%^C059%^This is a small iron stove. It is simple in design, with a shallow oven that holds a single wire rack. Strong side handles are attached to thick chains hung from above, allowing the stove to roll with the ship's constant motion.%^CRST%^",
        ]));
    set_exits(([
        "bunks" : SHIP"bunks",
        ]));
    set_search("barrels", (:this_object(),"search_barrels":));
    set_search("pantry", (:this_object(),"search_pantry":));
    searchflag = random(5) + 1;
}

void reset(){
    object room;
    
    ::reset();
	searchflag = random(5) + 1;
    
    room = this_object();
    if(!present("first mate", room)) new(MON"firstmate")->move(room);
}

void search_barrels(){
    object player, room;
    player = this_player();
    room = environment(player);
    
    switch(searchflag){
        case 1 :
            new(OBJ"apple")->move(room);
            tell_object(player, "You find a small red apple.\n");
            tell_room(room, ""+player->query_cap_name()+" pokes around inside of the barrels, eventually pulling out a small apple.\n", player);
            searchflag = 0;
            break;
        case 2 :
            new(OBJ"orange")->move(room);
            tell_object(player, "You find an old orange.\n");
            tell_room(room, ""+player->query_cap_name()+" finds an old orange in the barrel.\n", player);
            searchflag = 0;
            break;
        case 3 :
            new(OBJ"deadrat")->move(room);
            tell_object(player,"You pull a leathery rat corpse from the depths of a barrel.\n");
            tell_room(room,""+player->query_cap_name()+" searches deep and finds the leathery corpse of a rat in a barrel.\n", player);
            searchflag = 0;
            break;
	    case 4 :
            new(OBJ"rottenmeat")->move(room);
            tell_object(player,"You pull out a putrid slab of mystery meat.\n");
            tell_room(room,""+player->query_cap_name()+" pulls rotting meat from a a barrel.\n", player);
            searchflag = 0;
            break;
        default:
            tell_object(player,"You don't find anything.");
            tell_room(room,""+player->query_cap_name()+" searches through the barrels but doesn't find anything.", player);
            break;
    }
    return;
}

void search_pantry(){
    object player, room, herb;
    player = this_player();
    room = environment(player);
    
    if(searchflag == 5){
		herb = new("/d/common/obj/brewing/herb_inherit");
		herb->set_herb_name(search_herbs[random(sizeof(search_herbs))]);
		herb->move(room);
        tell_object(player, "You grab something from the pantry.\n");
        tell_room(room, ""+player->query_cap_name()+" grabs something from the pantry.\n", player);
        searchflag = 0;
    }
    else{
        tell_object(player, "The pantry is empty.");
        tell_room(room, ""+player->query_cap_name()+" searches through the pantry but doesn't find anything.", player);
    }
    return;
}

