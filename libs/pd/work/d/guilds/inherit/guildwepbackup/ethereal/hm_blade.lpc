#include <std.h>
#include <ether.h>
inherit ETHERWEP;


void create() {
 ::create();
    set_id(({"virtuoso", "blade"}));
    set_name("Viruoso");
    set_short("%^GREEN%^Vi%^BOLD%^r%^RESET%^%^BOLD%^tu%^GREEN%^o%^RESET%^%^GREEN%^so%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A fine looking blade. The hilt is made of the purest pearls and the blade is made of an unknown metal alloy. It glows with a holy aura.%^RESET%^");
    set_mass(15);
    set_curr_value("gold", 100);
    set_wc(7);
    set_type("blade");
    set_hands(1);
    set_hit( (: this_object(),"weapon_hit" :) );
}

int weapon_hit()
{
    int result, chance;
    object atkr, tp;
    atkr = this_player()->query_current_attacker();
    tp = this_player();
    if(random(100) < 30) {
      message("info", tp->query_cap_name()+"'s sword plunges deep into "+atkr->query_cap_name()+"'s chest.",
environment(tp), ({tp, atkr }) );
      message("info", "Your sword plunges deep into
"+atkr->query_cap_name()+".", tp, );
      message("info", tp->query_cap_name()+"'s sword plunges DEEP into your chest!", atkr, );
      result=(100 - random(25));
      tp->heal(result);
      result = (((tp->query_skill("blade")) * tp->query_stats("strength"))/35);
      return result;
    }
}
