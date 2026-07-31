// ruzhu.c 片皮乳猪

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "片皮乳猪" NOR, ({"ruzhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
         set("long", "乳猪皮色被烤得金黄，小刀轻轻一切，夹点大蒜，
蘸点酱，味道真是美极了。\n");
		set("unit", "只");
		set("value", 400);
		set("food_remaining", 5);
		set("food_supply", 200);
	}
}