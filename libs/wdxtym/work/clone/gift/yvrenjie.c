
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
	set_name("灵石礼包", ({"yuanma libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "里面有十万灵石！\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4;
	object gong,bagua,jian;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");


	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	write(YEL"恭喜您：你是个笨蛋，请看日期。"NOR"\n");
	
	
	
	
	add_amount(-1);
	me->save();

	return 1;
}
