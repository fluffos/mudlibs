#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("loincloth");
   set_short("a leopard skin loincloth");
   set_id(({ "cloth", "loincloth" }));
   set_long("The loincloth has been tied together very crudely. It is "
      "of the skin of a leopard. The bottom has been torn up a bit.");
   set_weight(12);
    set_curr_value("gold", 5);
   set_type("pants");
   set_limbs(({ "torso" }));
   set_ac(1);
}

int query_auto_load() {
   if (this_player()->query_level() > 13) return 1;
}
