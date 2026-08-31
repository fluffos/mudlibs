
#include <std.h>
inherit WEAPON;

void create() {
  ::create();

    set_name("bone spear");
    set_id( ({ "bone spear", "spear" }) );
    set_short("Bone spear");
    set_long("A spear carved from some large long bone. It is thin and sharp.");
    set_type("projectile");
    set_wc(10);
    set_weight(52);
    set_curr_value("gold", 34);
}





int query_auto_load()
{
    if (this_player()->query_level() > 30) return 1;
    return 0;
}
