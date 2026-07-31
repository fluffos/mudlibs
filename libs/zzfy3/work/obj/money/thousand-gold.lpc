// thousand-gold.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIY "一千两金票" NOR, ({"thousand-gold", "thousand-gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "thousand-cash");
		set("long", "一张面额值一千两金子的金票。\n");
		set("unit", "叠");
		set("base_value", 10000000);
		set("base_unit", "张");
		set("base_weight", 3);
	}
	set_amount(1);
}

