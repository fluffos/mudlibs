// shan.c 红焖青鳝

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("红焖青鳝", ({"qingshan", "shan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘香气扑鼻的红焖青鳝。\n");
		set("unit", "盘");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
