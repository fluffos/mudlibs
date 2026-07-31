inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("馒头", ({"dumpling"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个不算太硬的馒头。\n");
		set("unit", "个");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
