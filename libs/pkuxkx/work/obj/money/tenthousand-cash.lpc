#pragma save_binary
#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(WHT"一万两银票"NOR, ({"tenthousand-cash", "tenthousand-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "tenthousand-cash");
		set("long", "一张面额值一万两银子的银票。\n");
		set("unit", "叠");
		set("base_value", 1000000);
		set("base_unit", "张");
		set("base_weight", 5);
	}
	set_amount(1);
}

