// peach.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("桃子", ({"peach", "tao", "taozi"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个水灵灵的桃子。\n");
		set("unit", "个");
		set("value", 0);
		set("food_remaining", 2);
		set("food_supply", 10);
	}
}
