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
	set_name(HIG"飞行宠物（老鹰）"NOR, ({"laoyin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 100);
            set("no_sell",1);
			set("no_give",1);
			set("no_get",1);
		set("unit", "只");
		set("base_unit", "只");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","这是一只老魔驯养的老鹰，通人性\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->set("feixing","老鹰");
	write(YEL"你让老鹰带着你飞行!"NOR"\n");

        
	add_amount(-1);
	return 1;
}