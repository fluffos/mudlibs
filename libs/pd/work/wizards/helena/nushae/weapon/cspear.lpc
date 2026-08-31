#include <std.h>

inherit WEAPON;

void create() {
  ::create();
    set_name("a sharp coral spear");
    set_short("A sharp coral spear");
    set_long("A Sharp Spear expertly fashioned out of the hardest coral by NuShae Weaponsmiths.");
    set_id(({"spear"}));
    set_weight(5);
    set_curr_value("gold", 50-random(25));
    set_type("projectile");
    set_wc(8);
    set_hands(1);
}

int query_auto_load() {
    if (this_player()->query_level() >=15) return 1;
}
