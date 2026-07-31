//OBJECT:/d/suzhou/npc/obj/tangy.c 
//by dwolf
//97.11.4                 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"汤圆"NOR, ({ "tangyuan" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗香喷喷，甜甜的汤圆。\n");
		set("unit", "碗");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
	setup();
}

