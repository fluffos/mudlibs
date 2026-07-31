
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIY "年兽召唤卡" NOR, ({ "nianshou card" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一张精美的金色卡片，上面画着一个年兽的图案。\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "张");
	}
	set_amount(1);
	setup();
}
