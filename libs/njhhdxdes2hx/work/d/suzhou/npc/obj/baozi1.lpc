//OBJECT:/d/suzhou/npc/obj/baozi1.c 
//by dwolf
//97.11.4                 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(MAG"水晶包子"NOR, ({ "shuijing baozi", "baozi" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个玲珑剔透的包子。\n");
		set("unit", "个");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
	setup();
}

