// gold.c
#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(YEL"黄金"NOR, ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
		set("long", "黄澄澄的金子，人见人爱的金子，啊～～金子！\n");
		set("unit", "两");
		set("base_value", 10000 );
		set("is_money",1);
		set("base_unit", "两");
		set("base_weight", 1);
	}
	set_amount(1);
}

