// 血刀宝石

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "红水晶" NOR, ({ "Ruby gem" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "一块血红色的水晶。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_teal", 1);
		set("yuanbao", 500);
		set("can_be_inlay",([
		"name":"红水晶",
		"skill":"xuehai-mogong",
		])
		);
	}
	set_amount(1);
	setup();
}
