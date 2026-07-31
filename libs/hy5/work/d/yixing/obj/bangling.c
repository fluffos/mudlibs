// /d/yixing/obj/bangling.c
// Last Modified by winder on Jul. 12 2002


#include <ansi.h>

inherit ITEM;



void create()
{
	set_name("帮令", ({ "bang ling", "ling" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块帮会中常用的帮令。\n");
		set("value", 0);
		set("material", "wood");
		set("partyname", HIC"长乐帮"NOR);
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");
	}
	setup();
}

