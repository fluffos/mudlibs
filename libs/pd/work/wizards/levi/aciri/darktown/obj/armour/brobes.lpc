#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("robes");
   set_short("%^RESET%^%^BLUE%^midnight blue robes%^RESET%^");
   set_long("The robe is a dark midnight blue, very nearly black. "
     "This robe is made of a very soft, silky material. The material "
     "is far too thin to provide any real protection, but is no doubt "
     "enchanted for protection.");
   set_weight(4);
   set_id(({ "robe", "robes", "midnight blue robes", "midnight robes" }));
   set_ac(4);
   set_type("robe");
   set_value(194);
   set_limbs(({ "left foot", "right foot" }));
}

int query_auto_load() { if (this_player()->query_level() >= 21) return 3; }
