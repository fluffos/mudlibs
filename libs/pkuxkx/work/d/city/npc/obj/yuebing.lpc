// yuebing.c 月饼

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("月饼", ({"yuebing", "bing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "双黄白莲蓉--荣华出品，必属精品。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
