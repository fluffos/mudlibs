#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Gloves");
    set_short("%^ORANGE%^Bone %^RED%^Gloves%^RESET%^");
    set_long("These Gloves are made from the bones of the great "
             "fire Dragon the drows slaughtered");
    set_id( ({ "gloves" , "bone gloves" }) );
    set_ac(15);
    set_wear("%^ORANGE%^The Bones surround your hands.");
    set_remove("%^RED%^The Bones release there grip.");
    set_mass(14);
    set_value(40);
    set_type("gloves");
    set_limbs( ({ "first hand","second hand","third hand","fourth hand", }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
