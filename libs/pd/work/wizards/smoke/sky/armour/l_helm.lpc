#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("thick leather helm");
        set_id( ({ "helm", "leather helm", "thick leather helm" }) );
        set_short("%^RESET%^%^ORANGE%^thick leather helm%^RESET%^");
        set_long("This helm was crafted from the thick "
        "hide of a large animal native to the Lost Island. "
	"They was tailored by an expert Dwarven tailor. Though "
	"it looks almost primative, it probably provides "
	"some pretty good armor.");
        set_ac(8);
        set("value", 180);
        set_limbs( ({ "head" }) );
        set_weight(45);
        set_type("helmet");
	set_remove("You remove your %^ORANGE%^thick leather helm%^RESET%^ and "
	 "you feel the breeze against the back of your head again.");
        }
int query_auto_load() { return 1; }
