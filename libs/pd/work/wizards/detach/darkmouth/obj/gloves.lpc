#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Black Gloves");
    set_short("%^BOLD%^%^BLACK%^Black Gloves%^RESET%^");
    set_long("These Gloves are made from a very cheap leather, found "
      "somewhere deep in the caverns.");
    set_id( ({ "gloves" , "black gloves" }) );
    set_ac(2);
    set_mass(11);
    set_curr_value("gold",50+random(40));
    set_type("gloves");
    set_limbs( ({ "right hand","left hand"}) );
}

int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}
