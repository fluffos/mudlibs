#include <std.h>

inherit STONE;

void create()
{
    ::create();
    set_name("Orb");
    set_short("%^BOLD%^%^ORANGE%^Orb%^RESET%^");
    set_long("%^RESET%^%^GREEN%^An orb of magic energies. To release those energies you must <clutch orb>.%^RESET%^");
    set_id( ({ "orb", "magic orb" }) );
    set_mass(1);
    set_value(0);
    set_action("clutch");
    set_remove_mess("%^RESET%^%^ORANGE%^The %^BOLD%^%^ORANGE%^orb%^RESET%^%^ORANGE%^ fades out of this world.%^RESET%^");
    set_levels(({"whirling", "falling", "floating", "circling", "hovering", "fading" }));
    set_use_mess("%^RESET%^%^ORANGE%^You clutch the %^BOLD%^%^YELLOW%^orb%^RESET%^%^ORANGE%^ in the palm of your hand.%^RESET%^");

}
