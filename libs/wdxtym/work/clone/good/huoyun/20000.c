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
	set_name(HIY"2万修为卡"NOR, ({"20000 jy"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
            set("no_sell",1);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","这是1个修为卡，打开试试"NOR"。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->add("combat_exp",20000);
	write(YEL"你增加了20000点修为值!"NOR"\n");
	add_amount(-1);
	return 1;
}