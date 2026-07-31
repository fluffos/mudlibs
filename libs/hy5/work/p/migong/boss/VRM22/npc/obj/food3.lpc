// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"蛋糕"NOR, ({ "dan gao", "dangao" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块烤得香喷喷的牛排。\n");
		set("unit", "块");
		set("value", 700);
		set("food_remaining", 12);
		set("food_supply", 60);
		set("material", "bone");
	}
	setup();
}
