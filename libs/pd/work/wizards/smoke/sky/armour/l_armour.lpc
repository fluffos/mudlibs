#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("thick leather armour");
        set_id( ({ "armour", "leather armour", "thick leather armour" }) );
        set_short("%^RESET%^%^ORANGE%^thick leather armour%^RESET%^");
        set_long("This armour was crafted from the thick "
        "hide of a large animal native to the Lost Island. "
	"They was tailored by an expert Dwarven tailor. Though "
	"it looks almost primative, it probably provides "
	"some pretty good armor.");
        set_ac(12);
        set("value", 265);
        set_limbs( ({ "right arm", "left arm", "torso" }) );
        set_weight(96);
        set_type("armour");
	set_remove("You pull the %^ORANGE%^thick leather armour%^RESET%^ over "
	 "your head and suddenly feel more defenseless.");
        }
int query_auto_load() { return 1; }
