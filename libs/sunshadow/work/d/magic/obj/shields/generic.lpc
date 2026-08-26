//Generic

#include <std.h>

inherit "/d/magic/obj/shields/divine_shield_inherit";

void create(){
    ::create();
    set_name("simple circular shield");
    set_short("%^RESET%^%^CRST%^%^C250%^simple circular shield%^CRST%^");
    set_id(({"circular shield", "shield", "simple circular shield", "simple shield"}));
    set_long("%^RESET%^%^CRST%^%^C144%^Comprised of a simple circle of metal, the shield is lightweight and a faint gray in color. A leather strap on the back allows it to be worn.%^CRST%^");
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
        tell_room(room, "%^RESET%^%^CRST%^%^C250%^"+ownername+"%^RESET%^%^CRST%^%^C144%^ brings their shield across, bashing "+targetname+"%^RESET%^%^CRST%^%^C250%^ with it.%^CRST%^", ({owner, target}));
        tell_object(owner, "%^RESET%^%^CRST%^%^C250%^You bring your shield across, bashing "+targetname+"%^RESET%^%^CRST%^%^C250%^ with it.%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C250%^"+ownername+"%^RESET%^%^CRST%^%^C250%^ brings their shield across, bashing you with it.%^CRST%^");
        return 0;
    }
    return damage;
}

