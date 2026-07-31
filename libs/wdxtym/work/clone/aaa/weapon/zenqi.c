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
	set_name(YEL"500攻击丹"NOR, ({"gon li"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
            set("no_sell",1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","这是一颗加500攻击的丹药"NOR"。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->add("gain/damage",500);
	write(YEL"你增加了500点攻击力!"NOR"\n");
	add_amount(-1);
	return 1;
}