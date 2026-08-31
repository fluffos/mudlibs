#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("gloves");
   set_short("Gloves of the Hunter");
   set_id(({ "gloves", "hunter gloves" }));
   set_long("These gloves are made for the hands of an artrell.  They are made of a hardened resin material that is ultra light.");
   set_weight(8);
   set("value", 500);
   set_type("gauntlets");
   set_limbs(({ "first hand", "second hand", "third hand", "fourth hand" }));
   set_ac(5);
   set_fingers(2);
}
int query_auto_load() {
   if (this_player()->query_race() == "artrell" &&
 this_player()->query_level() > 20) return 1;
}
