// ITEM: /d/huashan/obj/liji.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("滑溜里脊", ({"hualiu liji", "liji"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘清香可口的滑溜里脊。\n");
		set("unit", "盘");
		set("value", 250);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
