#include <std.h>
#include <amun.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"dagger", "lux dagger", "lux"}));
    set_name("Lux Dagger");
    set_short("%^BOLD%^%^YELLOW%^Lux %^BLACK%^Dagger%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This %^BOLD%^%^YELLOW%^Lux %^BLACK%^Dagger was blessed by the %^WHITE%^%^God %^BLACK%^who made it and was given to the Last Saints to rid the world of evil.%^RESET%^");
    set_mass(20);
    set_curr_value("gold", 120);
    set_wc(1);
    set_type("knife");
    set_decay_rate(500);
    set("skill level", 125);
    set_hands(1);
//    set_hit( (: this_object(),"weapon_hit" :) );  
}
int weapon_hit()
{
    int result, chance;
    object atkr, tp;
    atkr = this_player()->query_current_attacker();
    tp = this_player();
    if(random(100) < 30) {
	message("info", tp->query_cap_name()+"'s 
%^BOLD%^%^YELLOW%^Lux %^BLACK%^Dagger%^BLACK%^ rips into thier opponent taking out thier %^RED%^evil%^BLACK%^.%^RESET%^", environment(tp), ({tp, atkr }) );
      message("info", "Your %^BOLD%^%^YELLOW%^Lux %^BLACK%^Dagger%^BLACK%^ rips into "+atkr->query_cap_name()+"taking out thier %^RED%^evil%^BLACK%^.%^RESET%^", tp, );
      message("info", tp->query_cap_name()+"'s 
%^BOLD%^%^YELLOW%^Lux %^BLACK%^Dagger%^BLACK%^ rips into you taking out your %^RED%^evil%^BLACK%^.%^RESET%^!", atkr, );
      result=(100 - random(25));
      tp->heal(result);
      return result;
    }
}
int query_auto_load(){ 
        if (this_player()->query_guild()=="last saints") return 1; 
}
