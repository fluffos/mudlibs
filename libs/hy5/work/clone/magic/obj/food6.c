// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIB"魔界果实"NOR, ({ "dark guo", "darkguo" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块魔界果实。\n");
		set("unit", "块");
		set("value", 2700);
		set("food_remaining", 30);
		set("food_supply", 500);
		set("material", "bone");
	}
	setup();
}
