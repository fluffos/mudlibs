// ya.c 火踵神仙鸭

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "火踵神仙鸭" NOR, ({"shenxian ya", "ya"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "火踵神仙鸭鸭肉鲜嫩无比，汤汁乳白似奶，味道鲜美，
富营养，而且还有开胃生津、滋阴补虚的妙效。\n");
		set("unit", "只");
		set("value", 250);
		set("food_remaining", 3);
		set("food_supply", 70);
	}
}