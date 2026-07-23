// buzhan.c 三不粘

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "三不粘" NOR, ({"sanbuzhan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "三不粘似糕非糕，似粥非粥，入口绵软柔润。滋味香甜。\n");
		set("unit", "盘");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 35);
	}
}