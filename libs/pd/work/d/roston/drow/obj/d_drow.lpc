#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Spider Armour");
    set_short("%^BOLD%^%^BLUE%^S%^BLACK%^p%^BLUE%^i%^BLACK%^d%^BLUE%^e%^BLACK%^r%^BLUE%^ A%^BLACK%^r%^BLUE%^m%^BLACK%^o%^BLUE%^u%^BLACK%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This armour was weaved from the "
    "%^BOLD%^%^WHITE%^un-known %^BLUE%^Blueish %^BOLD%^%^WHITE%^spider, hidden in the "
    "%^BOLD%^%^WHITE%^caves on the drow island.");
    set_id( ({ "spider armour", "armour", "spiderarmour" }) );
    set_wear("%^BOLD%^%^BLUE%^The spider webbs stick to your body.%^RESET%^");
    set_remove("%^BOLD%^%^BLACK%^You rip the webbs off your body.%^RESET%^");
   set_ac(12);
    set_mass(10);
    set_curr_value("gold", 270);
    set_type("body armour");
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg"}) );
}
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 if (this_player()->query_level() < 50) return 0;
 return 1;
}
