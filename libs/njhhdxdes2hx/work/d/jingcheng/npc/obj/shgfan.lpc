// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"砂锅饭"NOR, ({"shaguo fan", "fan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的砂锅饭。\n");
		set("unit", "碗");
		set("value", 600);
		set("food_remaining", 7);
		set("food_supply", 10);
	}
}
