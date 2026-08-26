//Edea Weapon Spell

#include <std.h>

inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("luminous torch");
    set_short("%^RESET%^%^CRST%^%^C144%^radiant %^C255%^iv%^C252%^o%^C255%^r%^C252%^y %^RESET%^%^C214%^t%^C220%^o%^C226%^r%^C220%^c%^C214%^h%^CRST%^");
    set_id(({ "weapon", "torch", "ivory torch" }));
    set_long("%^RESET%^%^CRST%^%^C144%^An %^C255%^iv%^C252%^o%^C255%^r%^C252%^y %^C255%^han%^C252%^d%^C255%^l%^C252%^e %^RESET%^%^C144%^has been carved with gentle sworls running the length of it, twisting gently as it flares widely at the top. A %^C214%^lu%^C220%^mi%^C226%^nes%^C220%^ce%^C214%^nt %^C220%^o%^C226%^r%^C220%^b %^RESET%^%^C144%^hovers above, radiating a %^C220%^warm glow %^C144%^and driving nearby %^C103%^shadows %^RESET%^%^C144%^back. It doesn't appear attached, but remains in place no matter how hard you smite your enemies with it.%^CRST%^");
    set_damage_type("blundeoning");
    set_value(0);
    set_size(1);
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
        tell_object(owner, "%^RESET%^%^CRST%^%^C144%^The %^C220%^o%^C226%^r%^C220%^b %^RESET%^%^C144%^of your torch flares %^C249%^b%^C252%^r%^C255%^ight%^C252%^l%^C249%^y %^RESET%^%^C144%^just before slamming into "+targetname+"!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C144%^The %^C220%^o%^C226%^r%^C220%^b %^RESET%^%^C144%^of "+ownername+"%^RESET%^%^CRST%^%^C144%^'s torch flares %^C249%^b%^C252%^r%^C255%^ight%^C252%^l%^C249%^y %^RESET%^%^C144%^just before slamming into you!%^CRST%^");
        tell_room(environment(ETO), "%^RESET%^%^CRST%^%^C144%^The %^C220%^o%^C226%^r%^C220%^b %^RESET%^%^C144%^of "+ownername+"%^RESET%^%^CRST%^%^C144%^'s torch flares %^C249%^b%^C252%^r%^C255%^ight%^C252%^l%^C249%^y %^RESET%^%^C144%^just before slamming into "+targetname+"%^RESET%^%^CRST%^%^C144%^!%^CRST%^", ({owner, target}));
        return (random(4) + 8);
    }
}

