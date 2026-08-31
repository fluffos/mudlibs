#include <std.h>
#include <zolenia.h>
inherit WEAPON;

int weapon_hit();
void create() {::create();;
     set_name("dark toy sword");;
     set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k t%^RESET%^o%^BLACK%^%^BOLD%^y sword%^RESET%^");;
     set_long("This sword has been carved very precisely from a black wood.  It has a fairly sharp edge, though, and can probably fare decently well.");;
     set_id( ({"sword", "toy sword", "dark toy sword"}) );;
     set_hands(1);;
     set_wc(6);;
     set_ac(1);;
     set_curr_value("gold", 50+random(35));;
     set_type("blade");;
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 15);
}
