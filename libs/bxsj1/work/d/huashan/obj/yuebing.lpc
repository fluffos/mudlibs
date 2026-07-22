// ITEM: /d/huashan/obj/yuebing.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("冰糖月饼", ({"bingtang yuebing", "yuebing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块令人垂涎欲滴的冰糖月饼。\n");
		set("unit", "块");
		set("value", 250);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
