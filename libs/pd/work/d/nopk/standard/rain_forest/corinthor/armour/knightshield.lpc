#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("shield");
     set_short("Knight's Shield");
     set_long("The Knight's shield has the shap of a kite with an elongated point going down. The face of the shield features two unicorns facing each other, rearing up on their hand legs. The symbol of the Elven court.");
     set_id(({"shield", "knights shield", "knight's shield"}));
     set_ac(2);
     set_weight(15);
     set_curr_value("gold", 12+random(5));
     set_type("bracers");
     set_limbs(({"left arm", "torso"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
