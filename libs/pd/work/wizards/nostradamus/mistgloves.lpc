#include <std.h>
inherit ARMOUR;

void create() {
::create();

   set_name("gloves");
   set_short("Mist Gloves");
   set_long("These gloves were created by ancient elven mages."
    "  They are made from the morning mist.  They are damp and"
    " cold to your senses.  They look as though they would not"
    " stay on you hands.");
   set_id(({"gloves", "mist gloves"}));
   set_ac(15);
   set_mass(10);
   set_value(10000);
   set_type("armour");
   set_limbs(({"right hand", "left hand"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
