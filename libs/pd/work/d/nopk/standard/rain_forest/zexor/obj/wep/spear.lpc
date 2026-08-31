#include <std.h>
#include <zexor.h>
inherit WEAPON;
int weapon_hit(object atk);

create() {
   ::create();
   set_name("spear");
   set_short("a long wooden spear");
   set_long("This spear is crafted out of a strong wood to be used "
       "by amazons to jab their prey.");
   set_wc(10);
   set_type("projectile");
   set_weight(10);
   set_value(345);
   set_hands(2);
   set_id(({"spear", "wooden spear", "amazon spear", "weapon"}));
set_hit((:weapon_hit:));
}

int query_auto_load() { if(this_player()->query_level() >=25) return 1; }

int weapon_hit(object atk) {
int result;
object ob, env;
   ob = environment(this_object());
   env = environment(ob);
if(random(100) > 75) {
write("You jab your opponent sharply in the gut.");
   tell_object(env, this_player()->query_cap_name()+" jabs "+atk->query_cap_name()+" sharply in the gut.");
result = (random(50))+((this_player()->query_level()));
return result;
   }
}
