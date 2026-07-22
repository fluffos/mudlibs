// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烧饼", ({"shao bing", "bing"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个微带焦黄的烧饼。\n");
		set("unit", "个");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
