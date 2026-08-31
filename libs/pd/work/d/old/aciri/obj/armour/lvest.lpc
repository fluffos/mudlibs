#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("vest");
   set_short("a studded leather vest");
   set_long("The thick, toughened leather vest has metal studs "
     "around the seems of the vest and down the center.");
   set_weight(5);
   set_id(({ "leather vest", "vest" }));
   set_ac(3);
   set_type("vest");
   set_value(172);
   set_limbs(({ "torso" }));
}

int query_auto_load() { if (this_player()->query_level() >= 17) return
3; }
