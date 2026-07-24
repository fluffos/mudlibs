// duomingbiao.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("夺命镖", ({"duomingbiao", "tmbiao" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这是唐门的独门暗器--夺命镖，镖上闪着蓝光。\n");
		set("unit", "些");
                set("base_value", 100);
	//	set("material", "steel");
                set("base_unit", "枚");
		set("base_weight", 1); 
	}	
        set_amount(999);
        init_throwing(500);
        setup();
}


