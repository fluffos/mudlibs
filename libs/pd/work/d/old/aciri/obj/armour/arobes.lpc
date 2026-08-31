#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("robes");
   set_short("Artrexian robes");
   set_long("Long, bronze-coloured robes with four arms are what the "
     "Arterxian robes consist of. This robe was made to fit the "
     "body of an artrell.");
   set_weight(4);
   set_id(({ "robes", "robe", "artrexian robes" }));
   set_ac(4);
   set_type("robe");
   set_value(207);
   set_limbs(({ "torso", "first arm", "second arm",
     "third arm", "fourth arm", "left leg", "right leg" }));
}

int query_auto_load() {
   if (this_player()->query_race() == "artrell") return 3;
}
