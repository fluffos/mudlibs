// cdiamond.c 钻石碎粒

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HBRED "金丹宝箱·碎片" NOR, ({ "sjssa3 sp" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "集齐4片『金丹宝箱·碎片』即可合成1个金丹宝箱！"NOR"\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "片");
		set("can_be_enchased", "/SJSSS3/BOX/box1");
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
