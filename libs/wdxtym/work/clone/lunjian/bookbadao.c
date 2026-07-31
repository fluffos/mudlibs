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
	set_name(HIR"【霸 刀 传】"NOR, ({"badao book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 900000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","关于开天仙经武林中没有太多的记载，只知道是一种近乎邪恶的刀法，杀伤力巨大，一般人士闻而避之。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+name()+"。\n");

		

			
		if(me->query_skill("badao") > 359)
			return notify_fail("你开天仙经等级太高了已经无法提升了。\n");
		else {
	me->set_skill("badao", me->query_skill("badao",1) + 180);
	write(YEL"你学会了开天仙经。。。"NOR"\n");
	write(YEL"开天仙经为兵器类刀法武功，学习开天仙经需要专心一致，心无旁骛！"NOR"\n");
	
	add_amount(-1);
	return 1;
		}
}