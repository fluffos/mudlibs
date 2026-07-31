// 乌金石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB"乌金石"NOR, ({ "wujin stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出乌金的矿石。三颗这样的矿石可以冶炼出一块乌金。\n");
		set("unit", "颗");
		set("value", 10000);
	}
}