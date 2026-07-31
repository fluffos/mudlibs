// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"花生米"NOR, ({"huansheng mi", "mi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟花生米。\n");
		set("unit", "碟");
		set("value", 500);
		set("food_remaining", 6);
		set("food_supply", 5);
	}
}
