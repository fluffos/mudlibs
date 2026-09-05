// 土豆 Zine 6 Sep 2010
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL "土豆" NOR, ({"tu dou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块新鲜的土豆。\n");
		set("unit", "块");
		set("value", 1);
		set("food_supply", 50);
	}
}