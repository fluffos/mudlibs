#include <std.h>
#include <rain.h>
inherit ARMOUR;

create() {
   ::create();
   set_name("spiked gloves");
   set_short("A pair of spiked gloves");
   set_ac(3);
   set_weight(10);
   set_type("gloves");
   set_id(({"gloves", "spiked gloves"}));
   set_curr_value("gold", 80);
   set_limbs(({"right hand", "left hand"}));
   set_long("These are strong gloves with spikes sticking out of "
            "the gloves");
}
int query_auto_load() { if (this_player()->query_level() >= 13) return 1; } 
