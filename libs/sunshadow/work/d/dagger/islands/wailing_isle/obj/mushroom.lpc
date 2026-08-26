// Chernobog (12/1/21)
// Magic Mushroom

#include <std.h>
#include "../defs.h"
inherit OBJECT;

void create(){
	::create();
	set_id(({"mushroom", "shroom", "magic mushroom"}));
	set_name("mushroom");
	set_short("%^RESET%^%^CRST%^%^C144%^spotted %^C255%^m%^C196%^u%^C255%^s%^C250%^h%^C196%^ro%^C255%^o%^C196%^m%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C144%^A bright %^C196%^red cap %^C144%^with %^C255%^white spots %^C144%^tops the stalk of this %^C255%^m%^C196%^u%^C255%^s%^C250%^h%^C196%^ro%^C255%^o%^C196%^m%^C144%^. It has an %^C058%^earthy scent %^C144%^to it, like loam, and feels slightly spongy to the touch.%^CRST%^");
	set_weight(1);
	set_value(500);
    set_lore("%^RESET%^%^CYAN%^These particular mushrooms are valued by several mystics who claim they are a key to unlocking the powers of the mind, of granting visions, of learning the secret truths of the universe. Others value them for less lofty reasons.%^RESET%^");
    set_property("lore difficulty", 30);
}

void init(){
    ::init();
    add_action("eat_fun","eat");
}

int eat_fun(string str){
    object tripping, player;
    
    if(!str) return 0;
    if(str != "mushroom") return 0;
    
    player = this_player();
    if(player->query_property("tripping")){
        tell_object(player, "%^RESET%^%^CRST%^%^C144%^Whoa... you feel one is enough for now.%^CRST%^");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C144%^You swallow the foul tasting fungus.%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C144%^"+player->query_cap_name()+" %^RESET%^%^CRST%^%^C144%^eats a strange spotted %^C255%^m%^C196%^u%^C255%^s%^C250%^h%^C196%^ro%^C255%^o%^C196%^m%^C144%^.%^CRST%^", player);
    tripping = new(OBJ"tripping_obj");
    tripping->move(player);
    this_object()->remove();
    return 1;
}

