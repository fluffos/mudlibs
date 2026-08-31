#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Monk holy robes");
    set_short("%^BOLD%^%^WHITE%^M%^BLUE%^o%^YELLOW%^n%^WHITE%^k "
     "%^BLUE%^h%^YELLOW%^o%^WHITE%^l%^BLUE%^y "
     "%^YELLOW%^r%^WHITE%^o%^BLUE%^b%^YELLOW%^e%^WHITE%^s %^RESET%^");
    set_long("These robes once belonged to a wise and old Arch Monk. "
     "They have been passed down from monk to monk for ages.");
    set_id( ({ "robes" , "monk holy robes" }) );
    set_ac(16);
    set_wear("%^BOLD%^%^WHITE%^You feel the protection of passed monks enter your body.");   
    set_remove("%^YELLOW%^You feel the protection leave you.");
    set_mass(30);
    set_value(0);
    set_type("body armour");
    set_limbs( ({ "head","torso","right arm","left arm","left leg","right leg" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
