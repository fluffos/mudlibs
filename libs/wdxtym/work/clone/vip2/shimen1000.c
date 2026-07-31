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
	set_name(YEL"师门1000次数卡"NOR, ({"1000shimen"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 2000);
        set("no_sell",1);
		set("item_origin", 1);
		set("unit", "张");
		set("base_unit", "张");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","使用可减少师门已做次数1000"NOR"。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	
	if(me->query("shimen/today")< 1001)
	{
		tell_object(me,"请将师门任务已做次数>1001次再使用。"NOR"\n");
		return 1;
	}
	
	me->add("shimen/today",-1000);
	write(YEL"你的已做师门次数记录减少了1000次，可以继续做师门了!"NOR"\n");
	add_amount(-1);
	return 1;
}