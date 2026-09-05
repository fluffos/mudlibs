// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("千层糕", ({"qianceng gao", "pie"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一块千层糕，散发着一种香气，不禁使人食欲大增\n");
		set("unit", "块");
		set("value", 500);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
} 
                     
