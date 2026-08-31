#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("helmet");
   set_short("A spiked helmet");
   set_long("This helmet is made out of a strong steel and his spikes "
            "jutting out of the top");
   set_id(({"steel helmet", "helmet", "spiked helmet"}));
   set_ac(4);
   set_mass(18);
   set_curr_value("gold", 52);
   set_type("helmet");
   set_limbs(({"head"}));
 }
int query_auto_load() { if (this_player()->query_level() >= 13) return 1; }
