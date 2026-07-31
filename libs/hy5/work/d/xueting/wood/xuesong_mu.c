// 雪松木 xuesong_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"雪松木"NOR, ({ "xuesong mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一块产自北方很雪松木，用于制作平常家具或烧制焦炭。\n");
		set("unit", "块");
		set("value", 2000);
	}
}