#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
create() {
::create();
set_id(({"axe", "cleaver", "rusty cleaver"}));
set_name("cleaver");
set_short("A rusty cleaver");
set_long("This old chopping tool still looks like it has some use to it.");
set_weight(50);
set_curr_value("gold",100);
set_wc(6);
set_hands(1);
set_type("axe");
set_wield("You are now ready to slice, dice, and mince!");
set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("%^BOLD%^%^BLACK%^You give a mighty grunt and slam the cleaver deeply into your target");
say((string)this_player()->query_cap_name()+" grunts and slashes out with the cleaver!");
result=(20 + random(this_player()->query_stats("strength"))/2);
return result;
}
}
int query_auto_load() {
  if(this_player()->query_level() < 30) return 0;
  return 1;
}
