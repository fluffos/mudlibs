// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("湖州粽子", ({"huzhou zongzi","zongzi"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是著名的湖州粽子，包裹的极为精致.\n");
		set("unit", "个");
		set("value", 300);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
} 
                     
