// 杨柳木 yangliu_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"杨柳木"NOR, ({ "yangliu mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一块很普通的杨柳木，用于制作家具或烧制木炭。\n");
		set("unit", "块");
		set("value", 1000);
	}
}