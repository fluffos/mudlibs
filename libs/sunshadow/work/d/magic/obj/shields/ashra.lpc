//Ashra

#include <std.h>

inherit "/d/magic/obj/shields/divine_shield_inherit";

void create(){
    ::create();
    set_name("tarnished silver shield");
    set_short("%^RESET%^%^CRST%^%^C091%^tarnished %^C243%^s%^C245%^i%^C247%^lv%^C245%^e%^C243%^r %^RESET%^%^C091%^shield%^CRST%^");
    set_id(({"silver shield", "shield", "tarnished silver shield"}));
    set_long("%^RESET%^%^CRST%^%^C091%^This circular shield is fashioned from %^C243%^s%^C245%^i%^C247%^lv%^C245%^e%^C243%^r%^RESET%^%^C091%^, though you would be hard pressed to realize it. A strange %^C059%^bl%^C243%^ac%^C059%^k t%^C243%^ar%^C059%^ni%^C243%^sh %^RESET%^%^C091%^coats every detail, obscuring the naturally luminous metal and leaving it corrupted and dark. The image of a %^C255%^ma%^C252%^s%^C255%^k %^RESET%^%^C091%^protrudes from the shield is bas relief, cracked with more of the inky tarnish dripping from the fractures.%^CRST%^");
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
        tell_room(room, "%^RESET%^%^CRST%^%^C091%^The %^C103%^shadows%^RESET%^%^C091%^ around "+ownername+"%^RESET%^%^CRST%^%^C091%^'s shield seem to coalesce, slowing "+targetname+"%^RESET%^%^CRST%^%^C091%^'s strike and absorbing the blow.%^CRST%^", ({owner, target}));
        tell_object(owner, "%^RESET%^%^CRST%^%^C091%^The %^C103%^shadows%^RESET%^%^C091%^ around your shield seem to coalesce, slowing "+targetname+"%^RESET%^%^CRST%^%^C091%^'s strike and absorbing the blow.%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C091%^The %^C103%^shadows%^RESET%^%^C091%^ around "+ownername+"%^RESET%^%^CRST%^%^C091%^'s shield seem to coalesce, slowing your strike and absorbing the blow.%^CRST%^");
        return 0;
    }
    return damage;
}

