// food.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("夫妻肺片", ({"piang", "fei"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一种成都地方小吃。\n");
                set("unit", "碟");
                set("value", 500);
                set("food_remaining", 10);
                set("food_supply", 100);
	}
}
