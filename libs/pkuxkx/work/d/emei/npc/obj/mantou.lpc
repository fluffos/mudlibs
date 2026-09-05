// mantou.c 馒头

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("馒头", ({"mantou"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个硬邦邦的大馒头，看得使人掉胃口。\n");
		set("unit", "个");
		set("value", 40);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
