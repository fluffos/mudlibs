#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Dwarven Shield");
    set_short("%^BOLD%^%^BLACK%^Dwarven%^RESET%^%^BOLD%^RED%^ Shield%^RESET%^");
    set_long("This is a shield that is used by dwarven hunters. "
      "It has pictures of yettis and bears on it. Its in "
      "great shape, and it looks well made.");
    set_id( ({ "shield" , "dwarven shield" }) );
    set_ac(3);
    set_mass(11);
    set_curr_value("gold", 40);
    set_type("shield");
    set_limbs( ({ "torso", "left arm", "right arm" }) );
}

int query_auto_load()

{                    
    if (this_player()->query_level() > 12) return 1;
    if (wizardp(this_player())) return 1;
    return 0;
}                             
