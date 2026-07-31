//降龙十八掌pfm龙翔九天

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "龙珠石" NOR, ({ "xiang gem" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "一块红色的宝石。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_teal", 1);
		set("can_be_inlay",([
		"name":"龙珠石",
		"skill":"dragon-strike-xiang",
		])
		);
	}
	set_amount(1);
	setup();
}
