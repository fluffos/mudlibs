#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list,file;
	int i,last,times,pot;
	mapping gifts;
	object ob;

	gifts = ([
		"/clone/shizhe/book_tianfu":10,
		"/clone/shizhe/putao":10,
	]);

	last = me->query("last_day_sign");
	times = me->query("day_sign_times");
	if(time()/86400 == last/86400)
		return notify_fail("你今天已签过到了，你目前已连续签到【"+HIY+times+NOR+"】天。\n");

	if(times>=6)
	{
		tell_object(me,"你完成了一轮签到。\n");
		me->set("day_sign_times",6);
		times = 6;
	}
	if(time()/86400 - last/86400 > 1)
	{
		tell_object(me,"你昨天没有签到记录，连续记录从今天开始。\n");
		times = 0;
	}

	me->set("last_day_sign",time());
	times += 1;
	me->set("day_sign_times",times);
	pot = random(1000) + 1000 + times*500;
	me->add("potential",pot);
	me->add("combat_exp",pot);
	me->add("yuanbao",250);
	me->add("jifeng",1250);

	tell_object(me,"你连续签到"+HIY+times+NOR+"次，获得"+HIY+pot+NOR+"点修为和潜能，250灵石和1250点券。\n");
	list = keys(gifts);
	for(i=0;i<sizeof(list);i++)
	{
		file = list[i];
		if((gifts[file]+times*10) > random(100))
		{
			ob = new(file);
			tell_object(me,"你获得了"+ob->short()+"。\n");
			ob->move(me);
		}
	}
	return 1;
}

int help(object me)
{
	write(@HELP
签到
HELP
	);
	return 1;
}
