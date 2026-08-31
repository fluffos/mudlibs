#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Fire Gauntlets");
    set_short("%^RED%^F%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^e%^RESET%^ "
    "%^RED%^G%^YELLOW%^a%^RESET%^%^RED%^u%^YELLOW%^n%^RESET%^%^RED%^t"
    "%^YELLOW%^l%^RESET%^%^RED%^e%^YELLOW%^t%^RESET%^%^RED%^s%^RESET%^");
    set_long("These Gauntlets were forged from the fire they glow "
    "with a beat red, there were made by the Evil Pyromancer for the "
    "General.");
    set_id( ({ "gauntlets" , "fire gauntlets" }) );
    set_ac(19);
    set_wear("%^RED%^Your hands seem to heat up.");
    set_remove("%^RED%^You hands no longer seem hot.");
    set_mass(10);
    set_value(450);
    set_type("gloves");
    set_limbs( ({ "right hand","left hand"}) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
