#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	int onlinetime;
	int i,last,times,pot;

	onlinetime = me->query("online_time");

	if(!arg)
	{
		str = ZJOBLONG"请输入奖励类型。\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "角色等级:uplv -l"ZJSEP"技能等级:uplv -s";
		if(wizardp(me))
		{
			str += ZJSEP+HIG"修改属性"NOR":wizlian"ZJSEP+HIG"复制物品"NOR":clone"ZJSEP+HIG"创建NPC"NOR":crnpc"ZJSEP+HIG"删除NPC"NOR":delnpc";
		}
		message("vision", str+"\n", me);
	}
	else if(arg=="-online") 
	{
		if (onlinetime<60*30)
		
return notify_fail("你的在线时间不足三十分钟，不能领取在线奖励。\n");
		if(onlinetime<60*30*2*24*3)
			me->add("shouwang",1);
		write("你获得了守望称号。\n");
		write("你累计在线"+CHINESE_D->chinese_time(me->query("online_time"))+"。\n");
		if (onlinetime>120*60*12) onlinetime = 120*60*12;
		
		write("你获得了"+onlinetime+"点修为。\n");
		write("你获得了"+onlinetime+"点潜能。\n");
		write("你获得了"+onlinetime+"个铜钱。\n");
		write("你获得了250枚灵石。\n");
		write("你获得了500张点券。\n");
		me->add("combat_exp",onlinetime);
		me->add("potential",onlinetime);
		me->add("balance",onlinetime);
	    me->add("yuanbao",250);
		me->add("jifeng",500);
		me->set("online_time",0);
	}
	else if(arg=="-daysign")
	{
	string *list,file;
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
	me->add("yuanbao",1000);
	me->add("jifeng",2000);
	tell_object(me,"你连续签到"+HIY+times+NOR+"次，获得"+HIY+pot+NOR+"点修为和潜能，1000枚灵石和2000张点券\n");
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

	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: getreward -

这个指令让你获得各种福利。

HELP
    );
    return 1;
}
