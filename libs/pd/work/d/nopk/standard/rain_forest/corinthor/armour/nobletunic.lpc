#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("tunic");
     set_short("Noble's tunic");
     set_long("The Noble's have shown again their belief tight clothes mean good clothes, as this tunic is rather close-fitting, but very stylish.");
     set_id(({"tunic", "noble tunic", "nobles tunic", "noble's tunic"}));
     set_ac(1);
     set_weight(3);
     set_curr_value("gold", 11+random(5));
     set_type("tunic");
     set_limbs(({"torso"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
