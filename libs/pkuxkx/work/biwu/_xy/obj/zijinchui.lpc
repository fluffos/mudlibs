// Created by zine 25 aug 2010

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;


void create()
{
	set_name("八楞紫金锤", ({ "zijin chui", "chui", "hammer" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("unit", "柄");
			set("long", "一柄金光闪闪的大锤。\n");
			set("value", 1);
			set("material", "steel");		
			init_hammer(105);
		}
	setup();
}