#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("robes");
     set_short("White robes");
     set_long("Plain robes of a white colour.");
     set_id(({"robes", "white robes"}));
     set_ac(1);
     set_weight(1);
     set_curr_value("gold", 8+random(13));
     set_type("robes");
     set_limbs(({"torso", "head", "left leg", "right leg", "left arm", "right arm"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}

