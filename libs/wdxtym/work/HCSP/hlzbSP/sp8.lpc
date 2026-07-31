// cdiamond.c 钻石碎粒

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HBRED "帝魂腰带·碎片" NOR, ({ "hlzb8 sp" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "集齐4片『帝魂腰带·碎片』即可合成1件帝魂腰带！"NOR"\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "片");
		set("can_be_enchased", "/fuben/zb/hl/bg11");
		set("enchased_need", 4);
		set("yuanbao", 100);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("magic/type", "lighting");
		set("magic/power", 30);
	}
	set_amount(1);
	setup();
}
