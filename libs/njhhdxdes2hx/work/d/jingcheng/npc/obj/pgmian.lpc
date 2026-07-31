// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"排骨面"NOR, ({"paigu mian", "mian"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的排骨面。\n");
		set("unit", "碗");
		set("value", 700);
		set("food_remaining", 7);
		set("food_supply", 10);
	}
}
