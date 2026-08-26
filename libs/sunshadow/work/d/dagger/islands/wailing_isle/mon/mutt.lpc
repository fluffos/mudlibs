// Chernobog & Titania (3/2/22)
// The Wailing Isle - The Wandering Mutt

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit NPC;

int fed;

void create() {
    ::create();
    set_name("a mangy mutt");
    set_id(({"mutt", "Mutt", "dog", "mangy mutt"}));
    set_short("%^RESET%^%^CRST%^%^C250%^a m%^C101%^a%^C247%^n%^C250%^gy m%^C245%^u%^C250%^t%^C101%^t%^C250%^%^CRST%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CRST%^%^C250%^Straggly %^C255%^white hair%^C250%^ fluffs from this pup's lanky body, which shows too much of his %^C245%^ribs%^C250%^ beneath. The poor dog looks %^C243%^malnourished%^C250%^ as he pads around on his long and scrawny legs, sniffing and rooting everywhere for a %^C058%^m%^C064%^o%^C058%^rsel%^RESET%^%^C250%^ to eat. His hair is %^C243%^coarse%^C250%^ and %^C243%^heavy%^C250%^ from the island's %^C249%^salt%^RESET%^%^C250%^ and %^C249%^sand%^C250%^, and he smells as bad as he looks. Despite this, he seems like a %^C159%^friendly dog%^C250%^ and is often subject to %^C137%^t%^C131%^a%^C137%^sty tre%^C131%^a%^C137%^ts%^RESET%^%^C250%^ and %^C139%^w%^C145%^e%^C139%^lcom%^C145%^in%^C139%^g pe%^C145%^t%^C139%^s%^RESET%^%^C250%^ from the locals and visitors alike as he roams freely about the place.%^CRST%^\n");
    set_gender("male");
    set_alignment(6);
    set_race("dog");
    set_body_type("quadruped");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    set_property("no_random_treasure",1);
    set_speed(10);
}

void init(){
    object player;
    
    ::init();
    add_action("feed_fun", "feed");
    add_action("hit_fun", "hit");
    add_action("pet_fun", "pet");
    add_action("pet_fun", "pat");
    add_action("pet_fun", "scratch");
    if(userp(player = this_player())){
        if(present("jar of nasty", player)) tell_object(player, "%^RESET%^%^CRST%^%^C194%^The stray mutt sniffs at you with interest.%^CRST%^\n");
    }
}

int pet_fun(string str){
    object player, room;
    
    if(!str) return 0;
    if(str != "mutt" && str != "dog" && str != "Mutt") return 0;
    
    player = this_player();
    room = environment(player);
    
    if(fed || (player->query("reputation wailing isle") == 50)){
        tell_object(player, "%^RESET%^%^CRST%^%^C194%^You reach down to pet the mutt, and it leans in for some %^C189%^sc%^C188%^ri%^C194%^t%^C188%^ch%^C189%^es%^RESET%^%^C194%^.%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C194%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C194%^ reaches down to pet the mutt, and it leans in for some %^C189%^sc%^C188%^ri%^C194%^t%^C188%^ch%^C189%^es%^RESET%^%^C194%^.%^CRST%^", player);
        return 1;
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C245%^As you reach for the mutt, it scampers away with its tail tucked low.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C245%^As "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C245%^ reaches for the mutt, it scampers away with its tail tucked low.%^CRST%^", player);
    return 1;
}

int feed_fun(string str){
    object player, jar, room;
    int reputation, xp_reward;
    player = this_player();
    room = environment(player);
    reputation = player->query("reputation wailing isle");
    
    if(!str) return 0;
    if(str != "jar to mutt" && str != "jar to dog" && str != "jar of nasty to mutt" && str != "jar of nasty to dog" && str != "mutt" && str != "dog") return 0;
    if(!objectp(jar = present("jar of nasty", player))){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't seem to have what the mutt wants.%^CRST%^");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C106%^The mutt knocks the %^C107%^jar%^C106%^ from your hands, spilling it out onto the ground and quickly wolfing down the contents.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C106%^The mutt knocks the %^C107%^jar%^C106%^ from "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C106%^'s hands, spilling it out onto the ground and quickly wolfing down the contents.%^CRST%^", player);
    tell_room(room, "%^RESET%^%^CRST%^%^C182%^With a %^C176%^wag%^C182%^ of its tail, the mutt looks back up for more.%^CRST%^");
    jar->remove();
    
    if(reputation < 14){
        reputation = player->query("reputation wailing isle") + 1;
        tell_object(player, "\n%^RESET%^%^CRST%^%^C208%^You feel as if this is earning some reputation for you on the Wailing Isle.%^CRST%^\n");
    }
    if(reputation > 13) tell_object(player, "\n%^RESET%^%^CRST%^%^C196%^You don't feel as if this is earning any more reputation for you on the Wailing Isle.%^CRST%^\n");
    if(reputation > 49) reputation = 50;
    player->set("reputation wailing isle", reputation);
    xp_reward = exp_for_level(player->query_level() + 1) / 8;
    player->add_exp(xp_reward);
    tell_object(player, "\n%^RESET%^%^CRST%^%^C045%^You have gained "+xp_reward+" XP.%^CRST%^\n");
    
    fed = 1;
    call_out("hunger_fun", 15);
    return 1;
}

void hunger_fun(){
    if(fed = 0) return;
    tell_room(environment(this_object()), "%^RESET%^%^CRST%^%^C245%^The mutt lets out a faint whimper, wandering off to root around for more food.%^CRST%^");
    fed = 0;
    return;
}

int hit_fun(string str){
    object npc;
    npc = this_object();
    
    if(str != "mutt" && str != "Mutt" && str != "dog") return 0;
    if(npc->query_hp() > 0){
        force_me("emoteat "+this_player()->query_name()+" %^RESET%^%^CRST%^%^C250%^$M gives $N a wary look, cowering and darting away.%^CRST%^");
        return 0;
    }
    this_player()->set("reputation wailing isle", -10);
    return 0;
}

void die(){
    object room, npc;
    object* attackers;
    int i;
    
    npc = this_object();
    room = environment(npc);
    attackers = npc->query_attackers();
    
    for(i = 0; sizeof(attackers), i < sizeof(attackers); i++){
        if (!objectp(attackers[i])) continue;
        if (userp(attackers[i])) {
            attackers[i]->set("reputation wailing isle", -10);
            continue;
        }
        continue;
    }
    ::die();
}

