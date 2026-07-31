// 
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"牛排"NOR, ({ "niu pai", "niupai" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块烤得香喷喷的牛排。\n");
		set("unit", "块");
		set("value", 800);
		set("food_remaining", 16);
		set("food_supply", 80);
		set("material", "bone");
	}
	setup();
}
