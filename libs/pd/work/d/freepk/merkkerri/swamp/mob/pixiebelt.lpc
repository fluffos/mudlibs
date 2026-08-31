#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
set_name("belt");
   set_short("%^RESET%^%^GREEN%^p%^RESET%^ixie %^GREEN%^b%^RESET%^elt");
   set_id(({ "belt", "pixie belt" }));
   set_long("A beautiful belt made of delicate seaweed from the swamp.  A golden buckle with several small runes fastens the belt.");
   set_weight(8);
   set_curr_value("gold", 90);
   set_type("belt");
   set_limbs(({ "torso" }));
   set_ac(1);
   
}
int query_auto_load() {
   if (this_player()->query_level() > 20) return 1;
}
