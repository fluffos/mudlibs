#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("thick leather gloves");
        set_id( ({ "gloves", "leather gloves", "thick leather gloves" }) );
        set_short("%^RESET%^%^ORANGE%^thick leather gloves%^RESET%^");
        set_long("These gloves were crafted from the thick "
        "hide of a large animal native to the Lost Island. "
	"They was tailored by an expert Dwarven tailor. Though "
	"they look almost primative, they probably provide "
	"some pretty good armor. These gloves were designed "
	"for races with only four fingers.");
        set_ac(4);
        set("value", 180);
        set_limbs( ({ "right hand", "left hand" }) );
        set_weight(14);
        set_type("gloves");
        set_fingers(4);
	set_remove("You pull the %^ORANGE%^thick leather gloves%^RESET%^ off "
	 "and put them in your pocket.");
        }
int query_auto_load() { return 1; }
