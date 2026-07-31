
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIR "福卡~1" NOR, ({ "newyear card1" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一张精美的红色卡片，上面写着一个金色的大字［"HIY"１"NOR"］，据说集齐[2018新春快乐]可以找财神兑换红包哦。\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "张");
		set("newyear_fu", "1");
	}
	set_amount(1);
	setup();
}
