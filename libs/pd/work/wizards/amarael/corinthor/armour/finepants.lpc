#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("pants");
     set_short("Fine pants");
     set_long("These pants are quite nice and have been made with fine cloth. Anyone could be proud to wear these pants.");
     set_id(({"pants", "fine pants"}));
     set_ac(1);
     set_weight(3);
     set_curr_value("gold", 8+random(5));
     set_type("pants");
     set_limbs(({"left leg", "right leg"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 3) return 1;
    return 0;
}
