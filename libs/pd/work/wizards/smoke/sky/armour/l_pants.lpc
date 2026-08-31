#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("thick leather pants");
        set_id( ({ "pants", "leather pants", "thick leather pants" }) );
        set_short("%^RESET%^%^ORANGE%^thick leather pants%^RESET%^");
        set_long("These pants were crafted from the thick "
        "hide of a large animal native to the Lost Island. "
	"They was tailored by an expert Dwarven tailor. Though "
	"it looks almost primative, it probably provides "
	"some pretty good armor.");
        set_ac(2);
        set("value", 180);
        set_limbs( ({ "left leg", "right leg" }) );
        set_weight(28);
        set_type("pants");
	set_remove("You remove your %^ORANGE%^thick leather pants%^RESET%^ and "
	 "suddenly begin to blush.");
        }
int query_auto_load() { return 1; }
