// Chernobog (4/12/22)
// Garrote Wire

#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit OBJECT;

int DELAY = 120;

void create() {
    ::create();
    set_name("garrote wire");
    set_id(({"garrote", "wire", "garrote wire"}));
    set_short("%^RESET%^%^CRST%^%^C101%^thin %^C244%^w%^C248%^i%^C244%^r%^C059%^e%^RESET%^%^C101%^ garrote%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C101%^A long loop of %^C244%^w%^C248%^i%^C244%^r%^C059%^e%^RESET%^%^C101%^ extends from a %^C136%^wooden handle%^C101%^, with a handful of the %^C244%^thin m%^C246%^e%^C248%^t%^C246%^a%^C244%^l cord%^RESET%^%^C101%^ protruding from the end. It has lots of tiny %^C124%^b%^C196%^ar%^C124%^b%^C196%^s %^RESET%^%^C101%^that catch within the handle, allowing the wire to be pulled and the loop tightened without permitting it to loosen. This could easily be used to %^C144%^<garrote> %^C101%^someone.%^CRST%^");
    set_lore("%^RESET%^%^CYAN%^A dirty tool for dirty jobs. Taking many forms, the garrote has found a home in the hands of rogues who need to deal with a mage quickly and quietly.%^RESET%^");
    set_property("lore difficulty",30);
    set_weight(2);
    set_value(5000);
}

void init() {
    ::init();
    add_action("garrote_fun","garrote");
}

int garrote_fun(string str){
    string playername, targetname;
    object player, target, room, garrote;
    int difficulty;
    
    player = this_player();
    room = environment(player);
    
    if(!objectp(player)) return 1;
    if(!objectp(room)) return 1;
    if(!str) return notify_fail("Garrote who?\n");
    if(player->query_property("shapeshifted")){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You can't use the garrote wire while shapeshifted.%^CRST%^");
        return 1;
    }
    if (userp(player) && !FEATS_D->usable_feat(player, "tools of the trade")){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You lack the training to use this effectively.%^CRST%^");
        return 1;
    }
    if(player->query_bound() || player->query_unconscious() || player->query_paralyzed()){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You cannot move to do that.%^CRST%^");
        return 1;
    }
    if(!(target = present(str, room))){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^That target is not here!%^CRST%^");
        return 1;
    }
    if(!player->kill_ob(target, 0)) return 1;
    if(target->query_property("strangled")){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^They are already being strangled!%^CRST%^");
        return 1;
    }
    if(this_player()->cooldown("garrote use")){
        tell_object(player, "%^RESET%^%^CRST%^%^059%^You cannot garrote someone so soon!%^CRST%^");
        return 1;
    }
    
    playername = player->query_cap_name();
    targetname = target->query_cap_name();
    
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^You loop the %^C059%^g%^C244%^a%^C248%^rro%^C244%^t%^C059%^e%^RESET%^%^C101%^ around "+targetname+"%^RESET%^%^CRST%^%^C101%^'s neck, pulling the wire tight and locking it in place...%^CRST%^");
    tell_object(target, "%^RESET%^%^CRST%^%^C101%^"+playername+"%^RESET%^%^CRST%^%^C101%^ loops a %^C059%^g%^C244%^a%^C248%^rro%^C244%^t%^C059%^e%^RESET%^%^C101%^ around your neck, pulling the wire tight and locking it in place...%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C101%^"+playername+"%^RESET%^%^CRST%^%^C101%^ loops a %^C059%^g%^C244%^a%^C248%^rro%^C244%^t%^C059%^e%^RESET%^%^C101%^ around "+targetname+"%^RESET%^%^CRST%^%^C101%^'s neck, pulling the wire tight and locking it in place...%^CRST%^", ({ player, target }));
    
    difficulty = 15 + player->query_skill("stealth");
    if(SAVING_THROW_D->reflex_save(target, difficulty)){
        tell_object(target, "%^RESET%^%^CRST%^%^C144%^You manage to free yourself of the garrote, breaking it and tossing it aside!%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C144%^"+targetname+"%^RESET%^%^CRST%^%^C144%^ manages to free themself of the garrote, breaking it and tossing it aside!%^CRST%^", target);
    }
    else{
        tell_object(target, "%^RESET%^%^CRST%^%^C196%^You start to choke as the %^C244%^w%^C248%^i%^C244%^r%^C059%^e%^RESET%^%^C196%^ sinks into your throat!%^CRST%^");
        tell_room(room, "%^RESET%^%^CRST%^%^C196%^"+targetname+"%^RESET%^%^CRST%^%^C196%^ starts to choke as the %^C244%^w%^C248%^i%^C244%^r%^C059%^e%^RESET%^%^C196%^ sinks into their throat!%^CRST%^", target);
        garrote = new(OBJ"garrote_obj");
        garrote->move(target);
    }
    
    player->set_paralyzed(1, "%^RESET%^%^CRST%^%^C160%^You are busy garroting someone!%^CRST%^");
    player->add_cooldown("garrote use", DELAY);
    this_object()->remove();
    return 1;
}

