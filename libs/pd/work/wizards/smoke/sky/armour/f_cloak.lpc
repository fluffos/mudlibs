#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("frayed cloak");
        set_id( ({ "cloak", "frayed cloak" }) );
        set_short("%^BOLD%^%^BLACK%^frayed cloak%^RESET%^");
        set_long("This cloak has seen some battles. It's "
        "tattered and frayed from various weapons attacking "
	"it's wearer. It's a dull black color, probably "
	"faded from all it's time in the sun.");
        set_ac(3);
        set("value", 170);
        set_limbs( ({ "head", "right arm", "left arm" }) );
        set_weight(36);
        set_type("cloak");
	set_remove("You remove your %^BOLD%^%^BLACK%^frayed cloak%^RESET%^ and "
	 "carefully fold it up and put it away, cautious not to rip it "
	 "any more than it already has.");
        }
int query_auto_load() { return 1; }
