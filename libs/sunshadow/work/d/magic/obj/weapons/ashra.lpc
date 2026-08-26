//Ashra Weapon Spell

#include <std.h>

inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("shadowy sickle");
    set_short("%^RESET%^%^CRST%^%^C091%^vicious %^C103%^shadow-%^C244%^e%^C246%^d%^C248%^g%^C250%^e%^C252%^d %^RESET%^%^C091%^sickle%^CRST%^");
    set_id(({ "weapon", "sickle", "shadow-edged sickle" }));
    set_long("%^RESET%^%^CRST%^%^C091%^A wicked curve of %^C245%^m%^C247%^e%^C249%^t%^C247%^a%^C245%^l %^RESET%^%^C091%^extends from a simple handle bound in supple %^C245%^bl%^C243%^a%^C245%^ck%^C243%^e%^C245%^ne%^C243%^d %^C058%^leather%^RESET%^%^C091%^. The edge of the crescent sickle fades away into %^C103%^shadow%^RESET%^%^C091%^, hidden from view by darkness that seems to trail behind for a moment with every movement. The very air itself seems to part with a %^C059%^ve%^C243%^lv%^C059%^et%^C243%^y w%^C059%^hi%^C243%^sp%^C059%^er %^RESET%^%^C091%^with each culling slash.%^CRST%^");
    set_damage_type("slashing");
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
        tell_object(owner, "%^RESET%^%^CRST%^%^C091%^The edge of the %^C255%^s%^C253%^i%^C251%^c%^C249%^k%^C247%^l%^C245%^e %^C243%^wh%^C059%^is%^C243%^pe%^C059%^rs %^RESET%^%^C091%^as you slice into "+targetname+"%^RESET%^%^CRST%^%^C091%^.%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C091%^The edge of the %^C255%^s%^C253%^i%^C251%^c%^C249%^k%^C247%^l%^C245%^e %^C243%^wh%^C059%^is%^C243%^pe%^C059%^rs %^RESET%^%^C091%^as "+ownername+"%^RESET%^%^CRST%^%^C091%^ slices into you.%^CRST%^");
        tell_room(environment(ETO), "%^RESET%^%^CRST%^%^C091%^The edge of the %^C255%^s%^C253%^i%^C251%^c%^C249%^k%^C247%^l%^C245%^e %^C243%^wh%^C059%^is%^C243%^pe%^C059%^rs %^RESET%^%^C091%^as "+ownername+"%^RESET%^%^CRST%^%^C091%^ slices into "+targetname+"%^RESET%^%^CRST%^%^C091%^.%^CRST%^", ({owner, target}));
        return (random(4) + 8);
    }
}

