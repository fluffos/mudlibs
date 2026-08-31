#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sabre", "saber", "hooked saber", "hooked sabre"}));
set_name("saber");
set_short("hooked saber");
set_long("A slender saber with an abnormal curvature at the tip that forms a hook.  It is made of a lightweight blue iron and wrapped at the hilt with worn leather.");
set_weight(12);
set("skill level", 100);
set_value(100);
set_wc(17);
set_ac(0);
set_type("blade");
set_hands(1);
set_hit((:this_object(),"weapon_hit":));
}

int query_auto_load() {
if(this_player()->query_level() < 30) return 0;
return 1; }
