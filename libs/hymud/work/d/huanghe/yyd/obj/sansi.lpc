// sansi.c 扣三丝

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("扣三丝", ({"kousansi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "火腿喻“金”，鸡脯肉喻“银”，三丝紧扣盆中，状如小山，寓意合家团圆，吉祥如意。\n");
		set("unit", "盆");
		set("value", 80);
		set("food_remaining", 1);
		set("food_supply", 45);
	}
}