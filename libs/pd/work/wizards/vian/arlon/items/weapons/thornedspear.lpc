#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {
::create();
     set_name("a thorned spear");
     set_short("a thorned spear");
     set_long("This spear is crafted from wood and hardened to not break.  It is covered with very sharp thorns, which are also hardened.");
     set_id( ({"spear", "thorned spear", "thornedspear"}) );
     set_hands(1);
     set_wc(2);
     set_weight(5);
     set_curr_value("gold", 30+random(35));
     set_type("projectile");
     set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 15) {write("A couple thorns from your spear break off in the target!");;
say((string)"A couple thorns from "+this_player()->query_cap_name()+"'s spear break off in their enemy.");;
result=(random(10))+((this_player()->query_level())*1);;
return result;;
}
}
int query_auto_load() { return 1; }

