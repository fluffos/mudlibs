// xianguo.c
// By jpei

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鲜果", ({"xian guo", "fruit", "guo"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个不知名的野果，闻起来很香。\n");
		set("unit", "个");
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
