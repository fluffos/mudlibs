// ju.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("黄菊花", ({ "yellow mum" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一枝美丽的黄菊花。\n");
		set("unit", "枝");
		set("value", 100);
	}
}
