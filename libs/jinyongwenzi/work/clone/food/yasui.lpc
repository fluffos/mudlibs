// yasui.c 鸭髓

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("鸭肉", ({"ya rou", "yarou","rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一滩带着些血丝的鸭髓，好象可以入药。\n");
		set("unit", "滩");
		set("value", 200);
		set("food_remaining", 1);
		set("food_supply", 20);
	}
}
