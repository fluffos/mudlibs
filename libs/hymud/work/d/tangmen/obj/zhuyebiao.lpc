// zhuyebiao.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("竹叶镖", ({"zhuyebiao", "tmbiao" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这是一把形如竹叶的飞镖。\n");
		set("unit", "些");
                set("base_value", 1);
		set("material", "steel");
                set("base_unit", "枚");
		set("base_weight", 10); 
	}	
        set_amount(999);
        init_throwing(180);
        setup();
}


