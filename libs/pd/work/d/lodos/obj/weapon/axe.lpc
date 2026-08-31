#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "axe" }));
   set_name("halberd");
   set_short("a hand axe");
   set_long("A small hand axe. It has a single notch in it. The handle "
     "is made of oak, and its blade is sharp.");
   set_weight(7);
    set_curr_value("gold", 25);
   set_wc(2);
   set_type("axe");
}

int query_auto_load() { if (this_player()->query_level() >= 6) return 1; }
