// yuebing.c 山鸡肉

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{      
	set_name("山鸡肉", ({"shanji rou", "rou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
	 	set("long", "这是用从山上猎来的山鸡制成的野味。\n");
		set("unit", "个");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
