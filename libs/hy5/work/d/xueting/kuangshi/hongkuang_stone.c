// 红矿石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"红矿石"NOR, ({ "hongkuang stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出红铁的矿石。三颗这样的矿石可以冶炼出一块红铁。\n");
		set("unit", "颗");
		set("value", 2000);
	}
}