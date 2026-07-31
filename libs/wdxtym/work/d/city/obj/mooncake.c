// mooncake.c 月饼

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("中秋月饼", ({"cake", "mooncake"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的中秋月饼。\n");
		set("unit", "个");
		set("value", 50000);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
}

