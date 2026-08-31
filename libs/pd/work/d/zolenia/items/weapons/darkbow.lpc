#include <std.h>
#include <zolenia.h>
inherit WEAPON;

int weapon_hit();
void create() {::create();;
     set_name("dark bow");;
     set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k b%^RESET%^o%^BLACK%^%^BOLD%^w%^RESET%^");;
     set_long("This bow has been carved very precisely from a black wood.  It curves at the top and bottom and when held straight ahead, looks like it's smirking.");;
     set_id( ({"bow", "dark bow", "black bow"}) );;
     set_hands(1);;
     set_weight(10);
     set_wc(9);;
     set_curr_value("gold", 200+random(35));;
     set_type("ranged");;
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
