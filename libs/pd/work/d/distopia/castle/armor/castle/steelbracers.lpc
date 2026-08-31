#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("steelbracers");
   set_short("steel bracers");
   set_long("These steel bracers provide decent protection to the arms.");
   set_limbs(({ "left arm", "right arm" }));
   set_id(({ "bracers", "steel bracers" }));
   set_weight(6);
   set_ac(2);
   set_type("bracers");
    set_curr_value("gold", 70);
}
int query_auto_load() {
   if (this_player()->query_level() >= 24) return 1;
}
