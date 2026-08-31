#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("vest");
   set_short("%^BOLD%^%^BLACK%^black chainmail vest%^RESET%^");
   set_long("The chainmail vest is made out of some strange, dark black "
     "metal very similar to steel. The metal rings are bound much closer "
     "together than on normal chainmail, making the armour unusually strong.");
   set_weight(23);
   set_id(({ "chainmail vest", "vest", "black chainmail vest" }));
   set_ac(6);
   set_type("vest");
   set_value(372);
   set_limbs(({ "torso" }));
}

int query_auto_load() { if (this_player()->query_level() >= 27) return 3; }
