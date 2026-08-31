#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Spider Armour");
    set_short("%^BOLD%^%^BLUE%^S%^BLACK%^p%^BLUE%^i%^BLACK%^d"
    "%^BLUE%^e%^BLACK%^r %^BLUE%^A%^BLACK%^r%^BLUE%^m%^BLACK%^o"
    "%^BLUE%^u%^BLACK%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This armour was weaved from the "
    "un-known %^BLUE%^Blueish %^BLACK%^spider, hidden in the "
    "caves in the drow island.");
    set_id( ({ "armour" , "spiderarmour","spider armour" }) );
    set_wear("%^BOLD%^%^BLUE%^The spider weps stick to your body.");
    set_remove("%^BOLD%^%^BLACK%^You rip the weps of your body.");
    set_ac(25);
    set_mass(10);
    set_value(500);
    set_type("body armour");
    set_limbs( ({ "torso","head","left leg","right leg","right arm","left arm" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
