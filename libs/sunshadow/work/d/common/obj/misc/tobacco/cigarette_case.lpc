// Chernobog (2/28/22)
// Updated Cigarette Case

#include <std.h>
#include <move.h>
inherit OBJECT;

int charges;

void create(){
    ::create();
    set_id(({"cigarette case","case"}));
    set_name("cigarette case");
    set_short("%^RESET%^%^CRST%^%^C130%^small %^C244%^s%^C247%^i%^C250%^lv%^C247%^e%^C244%^r %^C130%^case%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C130%^This small case is shaped from %^C247%^lu%^C250%^m%^C253%^in%^C250%^o%^C247%^us %^C244%^s%^C247%^i%^C250%^lv%^C247%^e%^C244%^r%^RESET%^%^C130%^, the polished surface displaying %^C243%^f%^C059%^in%^C243%^e e%^C059%^tc%^C243%^hi%^C059%^ng%^C243%^s %^RESET%^%^C130%^of %^C040%^v%^C046%^in%^C040%^e%^C046%^s %^RESET%^%^C130%^and %^C204%^blooming %^C196%^r%^C124%^o%^C196%^se%^C124%^s %^RESET%^%^C130%^along its periphery. A simple catch opens the case in order for you to %^C136%^<retrieve> %^C130%^,%^C136%^<load>%^C130%^, or %^C136%^<count> %^RESET%^%^C130%^your cigarettes.%^CRST%^");
    set_weight(2);
    set_value(5000);
    set_property("repairtype",({ "jeweller" }));
    charges = 5;
}

void init(){
    ::init();
    add_action("retrieve_fun", "retrieve");
    add_action("load_fun", "load");
    add_action("count_fun", "count");
}

int retrieve_fun(string str){
    object player, cigarette;
    player = this_player();
    
    if(!str) return 0;
    if(str != "cigarette") return 0;
    
    if(charges < 1){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The cigarette case seems to be empty.%^CRST%^");
        return 1;
    }
    
    cigarette = new("/d/common/obj/misc/tobacco/cigarette");
    if((int)(cigarette->move(player)) != MOVE_OK){
        cigarette->remove();
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You have nowhere to put that!%^CRST%^");
        return 1;
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C058%^You retrieve a cigarette from your case before snapping it shut.%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C058%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ retrieves a cigarette from "+player->query_possessive()+" case before snapping it shut.%^CRST%^", player);
    cigarette->move(player);
    charges--;
    return 1;
}

int load_fun(string str){
    object cigarette, player;
    player = this_player();
    
    if(!str) return 0;
    if(str != "cigarette") return 0;
    
    if(charges > 9){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^There is no room for any more cigarettes in the case.%^CRST%^");
        return 1;
    }
    if(!objectp(cigarette = present(str, player))){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't have a cigarette to load into the case.%^CRST%^");
        return 1;
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C058%^You load a cigarette into the case.");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C058%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ loads a cigarette into "+player->query_possessive()+" case.%^CRST%^", player);
    cigarette->remove();
    charges++;
    return 1;
}

int count_fun(string str){
    object player;
    player = this_player();
    
    if(!str) return 0;
    if(str != "cigarettes") return 0;
    
    if(charges){
        tell_object(player, "%^RESET%^%^CRST%^%^C058%^You have %^C136%^"+charges+"%^RESET%^%^CRST%^%^C058%^ cigarettes left in the case.%^CRST%^");
        return 1;
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C059%^The cigarette case is empty.%^CRST%^");
    return 1;
}

