//food: shaobing
//wuqi

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烧饼", ({"shao bing", "bing"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个热烘烘的面饼，上面洒着些葱花和芝麻。\n");
		set("unit", "个");
		set("value", 1);
		set("food_remaining", 3);
		set("food_supply", 5);
	}
}