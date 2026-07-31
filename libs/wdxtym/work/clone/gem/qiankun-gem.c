#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIB "蓝晶石" NOR, ({ "qiankun gem" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB "一块蓝色的水晶。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_teal", 1);
		set("can_be_inlay",([
		"name":"蓝晶石",
		"skill":"qiankun-danuoyi",
		])
		);
	}
	set_amount(1);
	setup();
}
