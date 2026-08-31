#include <std.h>
#include <zolenia.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();;
     set_name("dark blade");;
     set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k b%^RESET%^l%^BLACK%^%^BOLD%^ade%^RESET%^");;
     set_long("The dark blade appears to be made completely from darkness.  It sucks the light from its immediate surroundings.");;
     set_id( ({"blade", "sword", "dark blade"}) );;
     set_hands(1);;
     set_wc(10);;
     set_ac(2);;
     set_curr_value("gold", 200+random(35));;
     set_type("blade");;
     set_hit((:weapon_hit:));;
     set_weight(16);
}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("The %^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k b%^RESET%^l%^BLACK%^%^BOLD%^ade%^RESET%^ sucks the light from your opponent as it hits, moving it through the hilt and to your hands.");;
say((string)""+this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k b%^RESET%^l%^BLACK%^%^BOLD%^ade%^RESET%^ brightens for a moment.");;
result=(random(30))+((this_player()->query_level())*2);;
this_player()->add_hp(result);;
return result;;
}
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 29);
}

