#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("thick leather boots");
        set_id( ({ "boots", "leather boots", "thick leather boots" }) );
        set_short("%^RESET%^%^ORANGE%^thick leather boots%^RESET%^");
        set_long("These boots were crafted from the thick "
        "hide of a large animal native to the Lost Island. "
	"They was tailored by an expert Dwarven tailor. Though "
	"they look almost primative, they probably provide "
	"some pretty good armor.");
        set_ac(7);
        set("value", 220);
        set_limbs( ({ "right foot", "left foot" }) );
        set_weight(24);
        set_type("boots");
	set_remove("You pull the %^ORANGE%^thick leather boots%^RESET%^ off "
	 "your feet and consider putting them right back "
	 "on given the odor of your feet.");
}
int query_auto_load() { return 1; }
