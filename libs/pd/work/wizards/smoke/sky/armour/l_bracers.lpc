#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("thick leather bracers");
        set_id( ({ "bracers", "leather bracers", "thick leather bracers" }) );
        set_short("%^RESET%^%^ORANGE%^thick leather bracers%^RESET%^");
        set_long("These bracers were crafted from the thick "
        "hide of a large animal native to the Lost Island. "
	"They was tailored by an expert Dwarven tailor. Though "
	"it looks almost primative, it probably provides "
	"some pretty good armor.");
        set_ac(3);
        set("value", 125);
        set_limbs( ({ "right arm", "left arm" }) );
        set_weight(22);
        set_type("bracers");
	set_remove("You crack your wrists as the %^ORANGE%^thick leather bracers%^RESET%^ "
	 "come free from your arms.");
        }
int query_auto_load() { return 1; }
