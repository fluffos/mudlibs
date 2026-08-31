#include <std.h>
#include <ether.h>
inherit ETHERWEP;
//pyro && kumi
void create() {
 ::create();
 set_name("star");
 set_short("%^BOLD%^%^BLACK%^N%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^j%^BOLD%^%^BLACK%^a%^ %^RESET%^S%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^");
 set_long("%^BOLD%^%^BLACK%^This Ninja Star would be quite deadly in the hands of a skilled assassin.%^RESET%^");
 set_weight(10);
 set_id( ({ "star", "Ninja star"}) );
 set_curr_value("gold", 20);
 set_wc(4);
 set_type("projectile");
} 
int query_auto_load() {
 if (this_player()->query_level() > 35) return 1;
 return 0; 
}
int farse(string str) {
  if (!str || present(str, this_player()) != this_object()) return 0;
write("This weapon was only made to be thrown!");
return 1;
}
void init() {
    ::init();
    add_action("farse", "wield");
}
