#include <std.h>

inherit STONE;

void create()
{
    ::create();
    set_name("acid orb");
    set_short("%^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^c%^BOLD%^i%^RESET%^%^GREEN%^d%^BOLD%^i%^RESET%^%^GREEN%^c %^BOLD%^O%^RESET%^%^GREEN%^r%^BOLD%^b%^RESET%^");
    set_long("%^GREEN%^This orb is a sphere of %^BOLD%^boiling acid%^RESET%^%^GREEN%^, without leaving its sphere shape.  It is "
             "very strange, and it makes your skin tingle.  You feel the urge to crack it. "
             "It is Definately a Creation of Forsaken.");
    set_id( ({ "orb", "acid orb", "stonecheck" }) );
    set_mass(1);
    set_value(0);
    set_action("crack");
    set_remove_mess("The Acid orb you are holding begins to smoke, then disappears completely, it's magical energies exhausted.");
    set_levels(({"calm", "quivering", "bubbling", "brewing", "fizzing", "boiling" }));
    set_use_mess("%^GREEN%^You crack the orb, your bones shiver, your skin burns, you grin and feel the rush.%^RESET%^");
}
