#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("leatherbelt");
    set_short("Leather Belt");
    set_long("This crude strip of leather was turned into an even cruder belt.");
    set_id( ({ "belt" , "leather belt" }) );
    set_ac(1);
    set_mass(15);
    set_curr_value("gold",50+random(40));
    set_type("belt");
    set_limbs( ({ "torso"}) );
}
int query_auto_load() { if (this_player()->query_level() < 20) return 0;
 return 1;
}
