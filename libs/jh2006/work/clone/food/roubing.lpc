// roubing.c 大王肉饼

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大王肉饼", ({"rou bing", "roubing"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一张烤成金黄色的香喷喷的肉饼。\n");
		set("unit", "张");
		set("value", 200);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
