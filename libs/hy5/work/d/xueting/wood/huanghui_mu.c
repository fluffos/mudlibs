// 黄桧木 huanghui_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"黄桧木"NOR, ({ "huanghui mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一块品质不错的黄桧木，用于制作家具或烧制黑炭。\n");
		set("unit", "块");
		set("value", 3000);
	}
}