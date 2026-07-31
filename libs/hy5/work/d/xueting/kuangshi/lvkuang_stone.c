// 绿矿石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"绿矿石"NOR, ({ "lvkuang stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出铁的矿石。三颗这样的矿石可以冶炼出一块铁。\n");
		set("unit", "颗");
		set("value", 500);
	}
}