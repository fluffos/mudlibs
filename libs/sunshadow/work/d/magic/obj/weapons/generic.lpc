//Generic Spell Weapon

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create(){
    ::create();
    set_name("Divine Baton");
    set_short("%^RESET%^%^CRST%^%^C245%^softly %^C045%^g%^C051%^low%^C045%^i%^C051%^ng %^C245%^baton of pure %^C039%^energy%^CRST%^");
    set_id(({"divine baton", "baton", "weapon"}));
    set_long("%^RESET%^%^CRST%^%^C245%^A softly glowing bluish energy seems to comprise this simple baton. It occasionally pulses, offering a faint brightness that quickly dims.%^CRST%^");
    set_value(0);
    set_damage_type("bludgeoning");
    set_hit((:TO,"hit_func":));
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
        tell_object(owner, "%^RESET%^%^CRST%^%^C245%^Your baton flashes brightly as it connects with "+targetname+"%^RESET%^%^CRST%^%^C245%^!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C245%^"+ownername+"%^RESET%^%^CRST%^%^C245%^'s baton flashes brightly as it connects with you!%^CRST%^");
        tell_room(environment(ETO), "%^RESET%^%^CRST%^%^C245%^"+ownername+"%^RESET%^%^CRST%^%^C245%^'s baton flashes brightly as it connects with "+targetname+"%^RESET%^%^CRST%^%^C245%^!%^CRST%^", ({owner, target}));
        return (random(4) + 8);
    }
}

