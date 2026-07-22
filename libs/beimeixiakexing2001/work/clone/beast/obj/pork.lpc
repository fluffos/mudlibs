//Cracked by Roath
// pork.c 猪肉
// xbc 06/21/97

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小猪耳朵", ({"zhu erduo", "zhu rou", "pork"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块小猪耳朵肉。\n");
		set("unit", "块");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
}
