#include <std.h>
inherit STONE;
void create()
{
    ::create();
    set_name("skull");
    set_short("%^BOLD%^%^BLACK%^H%^GREEN%^u%^BLACK%^m%^GREEN%^a%^BLACK%^n S%^GREEN%^k%^BLACK%^u%^GREEN%^l%^BLACK%^l%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This skull was taken from a great war, it is now enchanted with "
"%^BOLD%^%^BLACK%^unknown magical power, if you wish to open this power you must <crack> "
"%^BOLD%^%^BLACK%^skull.");
    set_id( ({ "skull", "human skull" }) );
    set_mass(2);
    set_value(10);
    set_action("crack");
    set_remove_mess("%^BOLD%^%^BLACK%^The Skull crumbles to dust.%^RESET%^");
    set_levels(({"spinning", "falling", "floating", "rising", "levitating",
"circling" }));
    set_use_mess("%^BOLD%^%^BLACK%^You smash the skull with you fist, opening a crack, strange "
"%^BOLD%^%^BLACK%^vapors fill the air, you feel the rush of magical power flow into you.");
}
