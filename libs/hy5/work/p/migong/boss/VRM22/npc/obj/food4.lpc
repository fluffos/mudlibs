// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIB"水之果冻"NOR, ({ "guo dong", "guodong" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"当地特产，一块水之果冻。\n"NOR);
		set("unit", "块");
		set("value", 1000);
		set("food_remaining", 22);
		set("food_supply", 120);
		set("material", "bone");
	}
	setup();
}
