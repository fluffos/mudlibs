#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("juggernaut aegis");
  set_short("%^BOLD%^%^BLACK%^Th%^GREEN%^e %^BLACK%^J%^GREEN%^u%^BLACK%^gg%^GREEN%^e%^BLACK%^rn%^GREEN%^au%^BLACK%^t's %^GREEN%^Ae%^BLACK%^g%^GREEN%^i%^BLACK%^s%^RESET%^");
    set_long("The Juggernaut's Aegis is a large, dark shield.  The insignias of the "
	"sects of Umulos are etched into it with some brilliant green crystal.");
    set_id( ({ "aegis" , "shield", "aegis" }) );
    set_ac(3);
    set_mass(100);
    set_type("shield");
    set_limbs( ({ "torso", "left arm", "right arm" }) );
}
int query_auto_load() {
   if (this_player()->query_level() > 13) return 1;
}


