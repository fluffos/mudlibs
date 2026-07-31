// rose.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"红玫瑰"NOR, ({ "red rose" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一枝艳丽的红玫瑰花。\n");
		set("unit", "枝");
		set("value", 100);
	}
}
