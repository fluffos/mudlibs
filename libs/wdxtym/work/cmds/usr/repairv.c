// repairv.c					  
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	mixed  msg;
	int consistence;
	int cost;

	if (! arg)
		return notify_fail("你要修理什么东西？\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (!me->query("zjvip/times"))
		return notify_fail("非会员不能随身修理装备！\n");

	if (! objectp(ob = present(arg, me)))
		return notify_fail("你身上好像没有这样东西。\n");

	if (undefinedp(consistence = ob->query("consistence")))
		return notify_fail(ob->name() + "似乎不需要在这里修理吧？\n");

	if (consistence >= 100)
		return notify_fail(ob->name() + "现在完好无损，修理做什么？\n");

	if (! undefinedp(msg = ob->query("no_repair")))
	{
		if (stringp(msg))
			write(msg);
		else
			write("这东西无法修理。\n");
		return 1;
	}

	cost = ob->query("magic/power")+ob->query("point")+ob->level_now(1)*30;
	if(cost<80) cost = 80;
	cost *= 1000;
	cost = (100 - consistence)*cost/100;

	if (MONEY_D->player_pay(me, cost) != 1)
		return notify_fail("你身上的钱不足"+MONEY_D->price_str(cost)+"来修理这件装备。\n");

	ob->set("consistence", 100);
	me->start_busy(1);

	tell_object(me, YEL "你花费"+MONEY_D->price_str(cost)+"修理好了"+ob->name()+NOR"。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: 

这个指令可以让会员随身修理装备。

HELP
    );
    return 1;
}
