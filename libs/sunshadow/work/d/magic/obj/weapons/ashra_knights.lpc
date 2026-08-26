//Ashra Weapon Spell

#include <std.h>

inherit "/d/magic/obj/weapons/godwpns_knights";

void create(){
    ::create();
    set_name("blade of hungry darkness");
    set_short("%^RESET%^%^CRST%^%^C103%^da%^C097%^r%^C103%^kste%^C097%^e%^C103%^l %^RESET%^%^C091%^blade covered in %^C059%^ba%^C243%^rb%^C059%^s%^RESET%^%^CRST%^");
    set_id(({ "blade", "sword", "darksteel blade", "weapon" }));
    set_long("%^RESET%^%^CRST%^%^C103%^Da%^C097%^r%^C103%^kste%^C097%^e%^C103%^l %^RESET%^%^C091%^has been wrought into this sword, the tell-tale %^C097%^purple tarnish %^C091%^along its edges giving away its secrets. Juts of steel rise out from the blade at random intervals in %^C059%^sh%^C243%^ar%^C059%^pe%^C243%^ne%^C059%^d b%^C243%^ar%^C059%^bs%^RESET%^%^C091%^. Clearly, this weapon is intended to %^C196%^rip %^C091%^and %^C124%^shred %^RESET%^%^C091%^anyone standing in your way.%^CRST%^");
    set_value(0);
    set_damage_type("slashing");
    set_hit((: TO, "hit_func" :));
}

int hit_func(object target){
    object owner;
    string targetname, ownername;
    
    owner = environment(this_object());
    targetname = target->query_cap_name();
    ownername = owner->query_cap_name();
    target = owner->query_current_attacker();
    
    if(!objectp(owner)) return 1;
    if(!objectp(target)) return 1;

    if(!random(10)){
        tell_object(owner, "%^RESET%^%^CRST%^%^C091%^The barbs of your sword catch "+targetname+", %^C196%^tearing %^C091%^and %^C124%^ripping %^RESET%^%^C091%^free!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C091%^The barbs of "+ownername+"%^RESET%^%^CRST%^%^C091%^'s sword catches you, %^C196%^tearing %^C091%^and %^C124%^ripping %^RESET%^%^C091%^free!%^CRST%^");
        tell_room(environment(ETO), "%^RESET%^%^CRST%^%^C091%^The barbs of "+ownername+"%^RESET%^%^CRST%^%^C091%^'s sword catch "+targetname+"%^RESET%^%^CRST%^%^C091%^, %^C196%^tearing %^C091%^and %^C124%^ripping %^RESET%^%^C091%^free!%^CRST%^", ({owner, target}));
        return (random(4) + 8);
    }
}

