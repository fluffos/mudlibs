#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("robes");
    set_short("%^BOLD%^%^WHITE%^lea%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^her glo%^RESET%^%^ORANGE%^v%^BOLD%^%^WHITE%^es%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^These leather gloves seem to be surrounded by a magical force.");
    set_id( ({ "gloves" , "leather gloves" }) );
    set_ac(4);
    set_mass(3);
    set_value(39);
    set_type("gloves");
    set_limbs( ({ "right hand","left hand" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
