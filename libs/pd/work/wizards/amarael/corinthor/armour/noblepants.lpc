#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("tunic");
     set_short("fine tunic");
     set_long("This tunic is made of high quality, finely spun cloth with a nice green colour to it. It looks nice.");
     set_id(({"tunic", "fine tunic"}));
     set_ac(1);
     set_weight(3);
     set_curr_value("gold", 10+random(5));
     set_type("pants");
     set_limbs(({"left leg", "right leg"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
