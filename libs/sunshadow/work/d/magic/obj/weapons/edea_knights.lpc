//Edea Weapon Spell

#include <std.h>

inherit "/d/magic/obj/weapons/godwpns_knights";

void create(){
    ::create();
    set_name("sword of angelic radiance");
    set_short("%^RESET%^%^CRST%^%^C144%^glimmering sword of %^C189%^ra%^C195%^d%^C189%^ia%^C195%^n%^C189%^ce%^CRST%^");
    set_id(({ "blade", "sword", "darksteel blade", "weapon" }));
    set_long("%^RESET%^%^CRST%^%^C144%^It is hard to even look at this weapon, as the %^C111%^steel %^C144%^reflects every %^C220%^r%^C226%^a%^C220%^y %^C214%^of l%^C220%^i%^C226%^g%^C220%^h%^C214%^t%^RESET%^%^C144%^, surrounding itself in a prismatic %^C189%^ra%^C195%^d%^C189%^ia%^C195%^n%^C189%^ce%^RESET%^%^C144%^. An intricate crosspiece of angelic wings rests below the blade, before a pragmatic %^C058%^leather bound %^RESET%^%^C144%^grip finishes it off. It may be beautiful, but this sword is meant to be -used-.%^CRST%^");
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
        tell_object(owner, "%^RESET%^%^CRST%^%^C144%^A flash of %^C255%^light %^C144%^from the sword distracts "+targetname+"%^RESET%^%^CRST%^%^C144%^ as you lunge forward with the %^C189%^bl%^C195%^a%^C189%^de%^RESET%^%^C144%^!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C144%^A flash of %^C255%^light %^C144%^from the sword distracts you as "+ownername+"%^RESET%^%^CRST%^%^C144%^ lunges forward with the %^C189%^bl%^C195%^a%^C189%^de%^RESET%^%^C144%^!%^CRST%^");
        tell_room(environment(ETO), "%^RESET%^%^CRST%^%^C144%^A flash of %^C255%^light %^C144%^from the sword distracts "+targetname+"%^RESET%^%^CRST%^%^C144%^ as "+ownername+"%^RESET%^%^CRST%^%^C144%^ lunges forward with the %^C189%^bl%^C195%^a%^C189%^de%^RESET%^%^C144%^!%^CRST%^", ({owner, target}));
        return (random(4) + 8);
    }
}

