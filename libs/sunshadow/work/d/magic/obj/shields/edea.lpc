//Edea

#include <std.h>

inherit "/d/magic/obj/shields/divine_shield_inherit";

void create(){
    ::create();
    set_name("gleaming silver shield");
    set_short("%^RESET%^%^CRST%^%^C144%^gleaming %^C247%^s%^C250%^i%^C253%^lv%^C250%^e%^C247%^r %^RESET%^%^C144%^shield%^CRST%^");
    set_id(({"silver shield", "shield", "tarnished silver shield"}));
    set_long("%^RESET%^%^CRST%^%^C144%^This circular shield is fashioned from %^C255%^lum%^C252%^in%^C255%^ou%^C252%^s %^C247%^s%^C250%^i%^C253%^lv%^C250%^e%^C247%^r%^RESET%^%^C144%^, burnished and polished to an immaculate glimmer. Every ray of light falling upon it is refracted into a prismatic gleam, bathing the surround area in radiant light. The bas relief of a smiling %^C255%^feminine visage %^C144%^graces the front of the shield.%^CRST%^");
    set_value(0);
    set_struck((:TO,"strikeme":));
}

int strikeme(int damage, object what, object target){
    object owner, room;
    string ownername, targetname;
    
    owner = environment(this_object());
    room = environment(owner);
    ownername = owner->query_cap_name();
    targetname = target->query_cap_name();
    
    if(!random(10)){
        tell_room(room, "%^RESET%^%^CRST%^%^C144%^The %^C255%^li%^C252%^g%^C255%^h%^C252%^t%^RESET%^%^C144%^ seems to catch on "+ownername+"%^RESET%^%^CRST%^%^C144%^'s shield, distracting "+targetname+"%^RESET%^%^CRST%^%^C144%^ and staggering their attack.%^CRST%^", ({owner, target}));
        tell_object(owner, "%^RESET%^%^CRST%^%^C144%^The %^C255%^li%^C252%^g%^C255%^h%^C252%^t%^RESET%^%^C144%^ seems to catch on your shield, distracting "+targetname+"%^RESET%^%^CRST%^%^C144%^ and staggering their attack.%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C144%^The %^C255%^li%^C252%^g%^C255%^h%^C252%^t%^RESET%^%^C144%^ seems to catch on "+ownername+"%^RESET%^%^CRST%^%^C144%^'s shield, distracting you and staggering your attack.%^CRST%^");
        return 0;
    }
    return damage;
}

