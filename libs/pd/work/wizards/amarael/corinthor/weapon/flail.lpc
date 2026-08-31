#include <std.h>
inherit WEAPON;

void create() {
   ::create();
     set_name("flail");
     set_short("A flail");
     set_id(({"flail"}));
     set_long("This flail has just a single spiked head on the end of a strong chain. It'd hurt to be hit by that.");
     set_wc(3);
     set_type("flail");
     set_curr_value("gold", random(6)+12);
     set_mass(12);
}

int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
