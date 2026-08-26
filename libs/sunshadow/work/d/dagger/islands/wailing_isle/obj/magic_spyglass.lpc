// Chernobog & Titania (4/7/22)
// Wailing Isle - Magic Spyglass

#include <std.h>

inherit OBJECT;

int DELAY = 1800;

void create(){
	::create();
    set_name("magic spyglass");
	set_id(({"spyglass", "magic spyglass"}));
	set_short("%^RESET%^%^CRST%^%^C101%^battered %^C220%^s%^C136%^py%^C220%^g%^C136%^la%^C220%^s%^C136%^s%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C101%^This has seen better days. It's crafted from rings of rich %^C136%^mahogany%^C101%^, each edged by a circle of %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^RESET%^%^C101%^as they merge with the next and slowly taper to a small %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^C184%^e%^C172%^y%^C178%^e%^C184%^p%^C172%^i%^C178%^e%^C184%^c%^C172%^e%^RESET%^%^C101%^. The lens at the other end is %^C059%^cl%^C248%^o%^C244%^u%^C248%^dy%^RESET%^%^C101%^, however, and there are myriad dents, scratches, and even burns along the length of the %^C220%^s%^C136%^py%^C220%^g%^C136%^la%^C220%^s%^C136%^s%^RESET%^%^C101%^.%^CRST%^");
	set_weight(2);
	set_value(0);
    set_lore("%^RESET%^%^CYAN%^This is a relic found by Captain \"Three Teeth\" Astley in the aftermath of a battle with Captain Rust over the spoils of a coordinated raid on Seneca merchant vessels. Peering through the spyglass, he could %^BOLD%^view %^RESET%^%^CYAN%^the location of notable merchants. The magic was useful, and likely the source of his later successes on the seas before his retirement.%^RESET%^");
    set_property("lore difficulty", 50);
    set_property("no alter", 1);
}

void init(){
    ::init();
    add_action("view_fun", "view");
}

int view_fun(string str){
    object player, room, target, location, *inv;
    string targetname, realname, desc;
    int i, scrypower, reputation;
    
    if(!str) return 0;
    
    player = this_player();
    room = environment(player);
    targetname = lower_case(str);
    reputation = player->query("reputation wailing isle");
    
    if(reputation < 50){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The lens remains dark, revealing nothing.%^CRST%^");
        return 1;
    }
    if(player->cooldown("magic spyglass")){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The lens remains dark, revealing nothing.%^CRST%^");
        return 1;
    }
    if((string)player->realName(targetname) != "") realname = (string)player->realName(targetname);
    else{
	    tell_object(player,"%^RESET%^%^CRST%^%^C059%^You don't know anyone named "+target+".%^CRST%^");
	    return 1;
    }
    
    target = find_player(realname);
    if(!target){
        tell_object("%^RESET%^%^CRST%^%^C059%^You cannot sense that person at the moment.%^CRST%^");
        return 1;
    }
    if(target->query_true_invis() || wizardp(target)) return 0;
    
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^You raise the %^C220%^s%^C136%^py%^C220%^g%^C136%^la%^C220%^s%^C136%^s %^RESET%^%^C101%^to your eye, peering through it.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C101%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ raises the %^C220%^s%^C136%^py%^C220%^g%^C136%^la%^C220%^s%^C136%^s %^RESET%^%^C101%^to their eye, peering through it.%^CRST%^", player);
    
    scrypower = player->query_level() + 20;
    
    if(!target->scry_check(player, scrypower )){
        tell_object(player,"%^RESET%^%^CRST%^%^C059%^The lens remains dark, revealing nothing.%^CRST%^");
        return 1;
    }
    target->long_look_room(player, scrypower);
    player->add_cooldown("magic spyglass", DELAY);
    return 1;
}

