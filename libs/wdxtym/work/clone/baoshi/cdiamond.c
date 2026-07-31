// cdiamond.c 钻石碎粒

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIW "钻石碎粒" NOR, ({ "chipped diamond" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "一粒精光闪闪的如米粒般大小的钻石碎粒。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "粒");
		set("can_be_enchased", __DIR__"diamond");
		set("enchased_need", 3);
		set("magic/type", "lighting");
		set("magic/power", 50);
	}
	set_amount(1);
	setup();
}
