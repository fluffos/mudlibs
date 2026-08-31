#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("bow");
   set_short("a wire bow");
   set_long("The bow has a wooden back and is strung with wire. This "
     "is a bow for true archers.");
   set_weight(3);
   set_id(({ "bow", "wire bow" }));
   set_wc(7);
   set_type("blunt");
   set_value(193);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 3;
}
