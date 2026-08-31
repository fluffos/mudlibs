#include <std.h>

inherit STONE;

void create()
{
    ::create();
    set_name("ashes");
    set_short("%^BOLD%^%^WHITE%^A pile of ashes%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^These Ashes are from the burnt corpses of the fallen "
          "members of the %^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^"
          "S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s%^WHITE%^ clan. To use the "
          "power within the ashes you must <sprinkle> ashes.");
    set_id( ({ "ashes", "black ashes" }) );
    set_mass(1);
    set_value(0);
    set_action("sprinkle");
    set_remove_mess("The ashes dissapate in the wind.");
    set_levels(({"spinning", "falling", "floating", "rising", "levitating", "circling" }));
    set_use_mess("%^BOLD%^%^WHITE%^You sprinkle ashes on yourself and feel a rush of mana shoot into your body.");
}
