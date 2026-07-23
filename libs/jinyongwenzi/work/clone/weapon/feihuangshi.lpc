#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("飞蝗石", ({ "feihuang shi", "shi", "feihuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把大小均匀的飞蝗石。\n");
		set("base_value", 500);
		set("base_unit", "颗");
                set("base_weight", 30);		
	}
	set_amount(50);
       init_throwing(10);
}
