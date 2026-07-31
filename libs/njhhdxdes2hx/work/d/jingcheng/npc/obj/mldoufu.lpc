// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"麻辣豆腐"NOR, ({"mala doufu", "doufu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘香喷喷的豆腐。\n");
		set("unit", "盘");
		set("value", 700);
		set("food_remaining", 6);
		set("food_supply", 10);
	}
}
