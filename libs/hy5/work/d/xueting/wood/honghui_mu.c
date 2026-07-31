// 红桧木 honghui_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"红桧木"NOR, ({ "honghui mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一块品质优良的黄桧木，用于制作高档家具或烧制无烟炭。\n");
		set("unit", "块");
		set("value", 5000);
	}
}