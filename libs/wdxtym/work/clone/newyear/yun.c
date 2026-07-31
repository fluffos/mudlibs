
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIR "旺卡~运" NOR, ({ "newyear cardg" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一张精美的红色卡片，上面写着一个金色的大字［"HIY"运"NOR"］，据说集齐[狗年行大运]可以找巫师兑换神秘礼物哦。\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "张");
		set("newyear_fu", "运");
	}
	set_amount(1);
	setup();
}
