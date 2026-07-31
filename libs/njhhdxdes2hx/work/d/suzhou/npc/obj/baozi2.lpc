//OBJECT:/d/suzhou/npc/obj/baozi2.c 
//by dwolf
//97.11.4                 

#include <ansi.h>   
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(BLK"狗肉包子"NOR, ({ "gourou baozi", "baozi" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个用狗肉做馅的包子。\n");
		set("unit", "个");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 25);
	}
	setup();
}

