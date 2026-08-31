#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("gloves");
    set_short("%^BOLD%^%^BLACK%^Skel%^WHITE%^eto%^BLACK%^n Glov%^WHITE%^e%^BLACK%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These gloves from made from a skeleton of a giant wolf.%^RESET%^");
    set_id( ({ "gloves" , "skeleton gloves" }) );
    set_ac(3);
    set_mass(9);
    set_value(25);
    set_type("gloves");
    set_limbs( ({ "right hand","left hand" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
if(this_player()->query_level() > 45)
 return 1;
return 0;
}
