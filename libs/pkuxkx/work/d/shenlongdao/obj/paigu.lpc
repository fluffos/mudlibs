// huotui.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(YEL"黄豆"+RED"炖排骨"NOR, ({ "huang dou", "huangdou" }) );
        set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这是一碗香气扑鼻的江南名菜黄豆炖排骨。\n");
                set("unit", "碗");
		set("value", 200);
		set("food_remaining", 10);
		set("food_supply", 20);
		set("material", "meat");
	}
	setup();
}

