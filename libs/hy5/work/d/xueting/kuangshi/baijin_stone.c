// 白金石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"白金石"NOR, ({ "baijin stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出白金的矿石。三颗这样的矿石可以冶炼出一块白金。\n");
		set("unit", "颗");
		set("value", 10000);
	}
}