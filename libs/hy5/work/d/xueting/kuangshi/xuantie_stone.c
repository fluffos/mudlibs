// 玄铁石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"玄铁石"NOR, ({ "xuantie stone" }) );
	set_weight(5000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出玄铁的矿石。三颗这样的矿石可以冶炼出一块玄铁。\n");
		set("unit", "颗");
		set("value", 20000);
	}
}