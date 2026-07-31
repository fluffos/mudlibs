#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload()
{
	return query_amount() + "";
}

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
	set_name(HIY"洗点丹"NOR, ( {"xidian dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value", 100);
		set("yuanbao", 1500);
		set("no_sell",1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","洗点道具，使用后可以去武庙洗点师那里洗点。\n");
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

	if (me->query("zjvip/xiaobaizuishuai"))
		return notify_fail("你使用过洗点丹，但是还没有洗点，无需重复使用。\n");

	me->set("zjvip/xiaobaizuishuai",1);
	write(YEL"你使用了一颗"HIY"洗点丹"YEL"，你现在可以去武庙找洗点师洗点了!"NOR"\n");

	add_amount(-1);
	return 1;
}