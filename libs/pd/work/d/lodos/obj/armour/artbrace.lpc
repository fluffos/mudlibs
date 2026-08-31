#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("bracers");
   set_short("raknid bracers");
   set_id(({ "raknid bracers", "bracers" }));
   set_long("Two pairs of bracers made especially for raknids. "
      "They are made of wooden splints.");
   set_weight(20);
    set_curr_value("gold", 45);
   set_type("bracers");
   set_limbs(({ "first arm", "second arm", "third arm", "fourth arm" }));
   set_ac(1);
}

int query_auto_load() {
   if (this_player()->query_race() == "raknid") return 1;
}
