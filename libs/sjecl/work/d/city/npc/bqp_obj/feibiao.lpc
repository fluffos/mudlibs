#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("金钱镖", ({ "jinqian biao", "feibiao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "袋");
		set("long", "这是一袋精雕细琢的");
		set("base_value", 1000);
		set("base_unit", "把");
                set("base_weight", 20);		
	}
	set_amount(20);
       init_throwing(20);
}
