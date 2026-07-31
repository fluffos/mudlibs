// /d/yixing/obj/caili.c  彩礼
// Last Modified by winder on Jul. 12 2002


#include  <ansi.h>

inherit ITEM;


void create()
{
	set_name(RED"彩礼"NOR, ({ "caili" }));
	set("weight", 20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"这是一份包装精制的彩礼，里面一定装着贵重的东西。\n");
		set("unit", "份");
		set("value", 30);
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");	    
	}

	setup();

	
}


// to avoid players from cheating
// like go by da che or let other players carry them
// like go by following another player or driven by another player

// i still think, it is better to change follow.c and sing.c files
// then will save source

