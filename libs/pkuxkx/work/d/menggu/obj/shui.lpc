// whip
// created by zine

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("一瓢水", ({ "yipiao shui","shui"}));
    set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("unit", "瓢");
			set("long", "这是一瓢清水。\n");
			set("value", 0);
			set("material", "water");
		}
	setup();
}
