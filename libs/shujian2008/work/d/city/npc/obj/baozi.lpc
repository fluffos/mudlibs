// dumpling.c 包子
// lklv 2001.9.28 update

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("包子", ({"bao zi", "baozi", "dumpling"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的肉包子。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
