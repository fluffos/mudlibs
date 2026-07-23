#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("甩箭", ({ "shuaijian", "jian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "袋");
		set("long", "这是一袋精铁制成的甩箭。\n");
		set("base_value", 2000);
		set("base_unit", "支");
                set("base_weight", 50);		
	}
	set_amount(20);
       init_throwing(30);
}
