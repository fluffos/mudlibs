// Chernobog & Titania (3/10/22)
// The Wailing Isle - Tavern Alley

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_name("an alleyway");
    set_short("an alleyway");
    set_long("%^CRST%^%^RESET%^%^C243%^This alley doesn't go very far, pinned between two run down buildings and capped at the end by the %^C250%^rising cliffs%^C243%^ sloping upwards. There's a pile of %^C101%^wooden boxes%^C243%^ stacked up against the %^C151%^f%^C144%^a%^C244%^d%^C151%^ed yell%^C144%^o%^C151%^w b%^C144%^u%^C151%^ildi%^C144%^n%^C151%^g%^RESET%^%^C243%^, mostly in disrepair and caving in on themselves. A couple %^C245%^odd scratches%^C243%^ catch your eye, dug into the %^C151%^y%^C144%^e%^C151%^ll%^C144%^o%^C151%^w st%^C144%^u%^C151%^cco%^RESET%^%^C243%^. The opposite building seems to be covered in a line of %^C059%^water stains%^C243%^ left over from various denizens ducking in here to relieve themselves.%^CRST%^\n");
    set_smell("default","%^CRST%^%^RESET%^%^C151%^It smells %^C144%^r%^C150%^an%^C144%^k%^RESET%^%^C151%^ back here, a mixture of %^C150%^piss%^C151%^ and %^C144%^garbage%^C151%^.%^CRST%^");
    set_listen("default","%^CRST%^%^RESET%^%^C143%^The busy sounds from the street are %^C246%^muffled%^C143%^ here.%^CRST%^");
    set_items(([
        "cliffs" : "%^CRST%^%^RESET%^%^C250%^The cliffs rise up here in a steep slope, only interrupted by the residential tier above.%^CRST%^",
        "boxes" : "%^CRST%^%^RESET%^%^C058%^Aged %^C102%^wooden boxes%^C058%^ rest here in a heap, soaked and %^C064%^growing%^C058%^ things in the %^C059%^shade%^C058%^ between buildings.%^CRST%^",
        "stains" : "%^CRST%^%^RESET%^%^C102%^Circular spots in the %^C151%^stucco%^C102%^ have been discolored by %^C149%^m%^C150%^oi%^C149%^st%^C150%^ur%^C149%^e%^RESET%^%^C102%^.%^CRST%^",
        ]));
    set_exits(([
        "street" : ROOMS"marketsquare",
        "stairs" : ROOMS"pawn",
        ]));
    set_invis_exits(({ "stairs" }));
}

void init(){
    ::init();
    add_action("look_fun", "look");
    add_action("search_fun", "search");
}

int look_fun(string str){
    object player;
    player = this_player();
    
    if(!str) return 0;
    if(str != "scratches") return 0;
    
    tell_object(player, "%^RESET%^%^CRST%^%^C194%^There are quite a few odd scratches in the stucco, that almost seem intentional.%^CRST%^");
    if(player->is_class("thief") || player->is_class("bard")) tell_object(player, "%^RESET%^%^CRST%^%^C196%^You can pick out a couple words in the cant, \"boxes\" and \"stairs\".");
    return 1;
}

int search_fun(string str){
    if(!str) return 0;
    if(str != "boxes") return 0;
    
    tell_object(this_player(), "%^RESET%^%^CRST%^%^C059%^Stepping to the back, it appears the boxes almost entirely conceal a hidden set of %^C245%^stairs %^C059%^leading below the building.%^CRST%^");
    return 1;
}

