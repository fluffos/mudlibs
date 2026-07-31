// 紫矿石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"紫矿石"NOR, ({ "zikuang stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出紫铁的矿石。三颗这样的矿石可以冶炼出一块紫铁。\n");
		set("unit", "颗");
		set("value", 1000);
	}
}