#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "cane", "wolfs head cane", "silver cane" }));
   set_name("cane");
   set_short("a silver headed cane");
   set_long("The walking cane has a silver wolf's head at the top of the cane. "
     "This would be a deadly item in battle.");
   set_weight(7);
    set_curr_value("gold", 25);
   set_type("blunt");
}

int query_auto_load() { if (this_player()->query_level() >= 16) return 1; }
