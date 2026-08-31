#include <std.h>
#include <ether.h>
inherit ETHERWEP;

create() {
    ::create();
    set_id(({"falcate", "cutlass", "knife"}));
    set_name("Falcate Cutlass");
    set_short("%^BOLD%^%^BLACK%^Fa%^RESET%^%^BLUE%^lc%^BOLD%^a%^CYAN%^t%^WHITE%^e C%^CYAN%^u%^BLUE%^t%^RESET%^%^BLUE%^la%^BOLD%^%^BLACK%^ss%^RESET%^");
    set_long("%^CYAN%^This cutlass resembles the shape of a crescent moon. Its silver blade streches"
         " 5 inches long, finishing at an extremely sharp tip. It seems like a very powerful knife.%^RESET%^" );
    set_weight(20);
    set_curr_value("gold",200);
    set_wc(13);
    set_ac(1);
    set_type("knife");
    set_hands(1);
    set("skill level", 230);
    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 84) {
        write("You hook your dagger around your opponent's neck, immobilizing them for the moment.");
        say("You gasp in astonishment as "+this_player()->query_cap_name()+" skillfully hooks "
            "their dagger around "+this_player()->query_cap_name()+
            "'s neck, immobilizing them temporalily."); 
this_player()->add_sp(50);
result=(random(50)+(this_player()->query_stats("dexterity")*2));
atk->set_paralyzed(random(3));
return result;
}

return 0;
}

int query_auto_load() {
  if (this_player()->query_level()>49) return 1;
  return 0;
}
