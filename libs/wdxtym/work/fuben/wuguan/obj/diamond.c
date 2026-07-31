// diamond.c 钻石

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIW "普通钻石" NOR, ({ "diamond" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "一粒精光闪闪的钻石。"NOR"\n");
		set("base_value", 50000);
		set("base_weight", 1);
		set("base_unit", "粒");
		set("can_be_enchased", __DIR__"fdiamond");
		set("enchased_need", 3);
		set("magic/type", "lighting");
		set("magic/power", 100);
	}
	set_amount(1);
	setup();
}
