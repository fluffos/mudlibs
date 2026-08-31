#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("platemail");
     set_short("Royal platemail");
     set_long("The Royal armour of Corinthor, it is worn by the King of the forest. It has been studded with many sapphires, rubies and emeralds in wonderful patterns.");
     set_id(({"platemail", "royal platemail"}));
     set_ac(4);
     set_weight(20);
     set_curr_value("gold", 25+random(5));
     set_type("body armour");
     set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 6) return 1;
    return 0;
}

