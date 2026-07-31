// 金丝楠木 nan_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"金丝楠木"NOR, ({ "na mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一块极品金丝楠木，用于制作高档家具或烧制白炭。\n");
		set("unit", "块");
		set("value", 10000);
	}
}