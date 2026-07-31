// 青铜石
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"青铜石"NOR, ({ "qingtong stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗可以炼出青铜的矿石。三颗这样的矿石可以冶炼出一块青铜。\n");
		set("unit", "颗");
		set("value", 100);
	}
}