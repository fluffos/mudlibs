#include <std.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("rock");
   set_short("a rock");
   set_long("A large rock; a primitive weapon indeed.");
   set_wc(5);
   set_type("blunt");
   set_weight(12);
   set_curr_value("silver", 5);
   set_id(({ "rock", "large rock" }));
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
