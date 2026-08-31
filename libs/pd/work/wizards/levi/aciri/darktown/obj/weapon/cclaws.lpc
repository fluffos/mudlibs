#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("claws");
   set_short("cinder claws");
   set_long("Four claws of flaming cinder with a tie for the wielder's wrist. "
     "Each of the four claws emerges from the each knuckle of your hand.");
   set_weight(6);
   set_id(({ "claw", "claws", "cinder claws" }));
   set_wc(8);
   set_type("knife");
   set_value(340);
   set_wield("You strap the claws on and the cinder melts into your hand.");
   set_unwield("You pull the claws out of your knuckles and unstrap it.");
}

int query_auto_load() {
   if (this_player()->query_skill("knife") >= 45) return 0;
}
