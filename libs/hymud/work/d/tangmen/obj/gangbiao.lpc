// gangbiao.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("钢镖", ({"gangbiao", "tmbiao" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这是一把普通的钢镖。\n");
		set("unit", "些");
                set("base_value", 1);
		set("material", "steel");
                set("base_unit", "枚");
		set("base_weight", 10); 
	}	
        set_amount(999);
        init_throwing(145);
        setup();
}


