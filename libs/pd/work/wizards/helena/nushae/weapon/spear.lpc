#include <std.h>

inherit WEAPON;

void create() {
  ::create();
    set_name("a coral spear");
    set_short("A coral spear");
    set_long("The spear expertly fashioned out of coral by NuShae Weaponsmiths. It is not too sharp or tough, but it will still get the job done.");
    set_id(({"spear"}));
    set_weight(4);
    set_curr_value("gold", 50-random(25));
    set_type("projectile");
    set_wc(5);
    set_hands(1);
}

int query_auto_load() {
    if (this_player()->query_level() >=10) return 1;
}
