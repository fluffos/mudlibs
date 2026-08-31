#include <std.h>
inherit WEAPON;

void create() {
   ::create();
     set_name("dagger");
     set_short("A dagger");
     set_id(({"dagger"}));
     set_long("A short dagger made of steel. It is small enough to be concealed, with a tip sharp and hard enough to break flesh.");
     set_wc(3);
     set_type("knife");
     set_curr_value("gold", random(6)+12);
     set_mass(9);
}

int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
