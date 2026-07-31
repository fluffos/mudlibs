#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIC"天灵丹"NOR, ({"tianling dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 10);
        set("no_sell",1);
		set("unit", "颗");
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);		
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("long","这是一颗天灵丹，可以增加一小时的双倍时间(对师门任务、闭关室和练功房有效)。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;

	me->apply_condition("db_exp", 360+me->query_condition("db_exp"));

	write(YEL"你服下一颗"HIC"天灵丹"YEL"，顿觉神清气爽、思维敏捷!"NOR"\n");
	add_amount(-1);
	return 1;
}

