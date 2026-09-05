// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("醉枣", ({"zuizao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一包又大又圆，色泽鲜亮的醉枣，散发着淡淡的酒香\n");
		set("unit", "包");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
} 
                     
