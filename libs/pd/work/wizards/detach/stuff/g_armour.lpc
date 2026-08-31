#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Holy Cleric Armour");
    set_short("%^BOLD%^%^WHITE%^H%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
    "%^WHITE%^C%^YELLOW%^l%^WHITE%^e%^YELLOW%^r%^WHITE%^i%^YELLOW%^c "
"%^WHITE%^A%^YELLOW%^r%^WHITE%^m%^YELLOW%^o%^WHITE%^u%^YELLOW%^r%^RESET%^");
    set_long("%^YELLOW%^This armour belongs to a loyal servant "
    "of the gods. This armour has been blessed by the gods to "
    "protect who ever wears it.");
    set_id( ({ "armour" , "holy armour","holy cleric armour" }) );
    set_ac(17);
    set_mass(60);
    set_wear("%^BOLD%^%^WHITE%^The Gods say to you: %^YELLOW%^Use this well my son.");
    set_remove("%^BOLD%^%^WHITE%^You hear the Gods whisper: %^YELLOW%^Keep the faith my son");
    set_value(0);
    set_type("body armour");
    set_limbs( ({ "head","torso","right arm","left arm","left leg","right leg" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
