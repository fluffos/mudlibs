#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("javelin");
   set_short("a sleek javelin");
   set_long("The entire wooden length of the javelin is very sleek, "
     "leaving no chance for splinters. The metallic point on the tip "
     "of the javelin is slightly hooked, so it will gore the target, "
     "and still allow the attacker to pull the javelin back.");
   set_weight(7);
   set_id(({ "javelin", "sleek javelin" }));
   set_wc(9);
   set_type("projectile");
   set_value(174);
}

int query_auto_load() {
   if (this_player()->query_skill("projectile") >= 30) return 3;
}
