#include <std.h>
inherit ARMOUR;

void create() {
::create();
   set_name("boots");
   set_short("Mist Boots");
   set_long("These boots were created by ancient elven mages.  "
    "They are made from the morning mist.  They are damp and "
    "cold to your senses.  They look as though you could pass "
    "your hands right through them.");
   set_id(({"boots", "mist boots"}));
   set_ac(15);
   set_mass(20);
   set_value(10000);
   set_type("armour");
   set_limbs(({"left foot", "right foot"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
