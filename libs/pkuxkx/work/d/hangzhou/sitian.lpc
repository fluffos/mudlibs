///d/hangzhou/sitian.c司天监 Zine 转自应天府
inherit ROOM;
#include <ansi.h>
#include <localtime.h>
string look_machine();
int jiancha_jieguo(object me, string arg);
void create()
{
        set("short", "司天监");
        set("long",
"这里司天监的衙门。一座巨大的仪器矗立在院子正中，这就是著名的浑天\n仪(machine)。\n"

        );
        set("item_desc", ([
		"machine" : (:look_machine:),
	    ]));
        set("exits", ([
		"east" : __DIR__"guandaon1",
        ]));
        set("objects", ([(__DIR__"obj/huntian") : 1,
        ]));
        set("outdoors", "yingtianfu");
        set("rate",150);
        setup();
        call_out("gettime",1);

}

string look_machine()
{
    return HIY"一架巨大的天文仪器，你可以计算(jisuan),兑换(duihuan),降等(jiangdeng),甄别(zhenbie)。上面隐隐有着一排篆体数字："+chinese_number(this_object()->query("rate"))+"。\n"NOR;
}
void init()
{
    add_action("do_duihuan", "duihuan");
	add_action("do_jiangdeng", "jiangdeng");
	add_action("do_zhenbie", "zhenbie");

}
int do_duihuan(string arg)
{
    object me=this_player();
    int factor,times;
    if (me->is_busy() || me->is_fighting())
    return notify_fail("你正忙着呢！\n");
    if (!arg)
    return notify_fail("请用duihuan 浑天仪 <经验数>来选择转化成修行经验的实战经验。\n");
    if (me->query("combat_exp")<1000000)
    return notify_fail("你的实战经验太少了，还是以后再来吧。\n");
    if (me->query("exp_dep")>me->query("combat_exp")/2)
    return notify_fail("你的修行经验太多了，快去用掉一点吧。\n");
    if (sscanf(arg, "浑天仪 %d", times) == 1)
    {
        if (times<10000)
        return notify_fail("一次兑换的实战经验至少一万点。\n");
        if (times>me->query("combat_exp")/10)
        return notify_fail("一次不能兑换超过本身一成的实战经验。\n");
        factor=factor+(int)this_object()->query("rate");
        factor=times/100*factor;
        message_vision(HIY"$N开始仔细操弄浑天仪，口中念念有词……\n"NOR,me);
        me->add_busy(2);
        me->add("combat_exp",-times);
		me->add("transferred_exp",times);
        me->add("exp_dep",factor);
        tell_object(me,"你消耗了"+chinese_number(times)+"点实战经验，转化为"+chinese_number(factor)+"点修行经验。\n");
        return 1;
    }
    else
    {
        return notify_fail("请用duihuan 浑天仪 <经验数>来选择转化成修行经验的实战经验。\n");
    }
}

int do_jiangdeng(string arg)
{
    object me=this_player();
    int factor,times;
	int i,loop_time,random_p;
    if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
    if (!arg)
		return notify_fail("请用jiangdeng <经验数>用来确定降等使用消耗的修行经验。\n");
    if (me->query("exp_dep")<1000000)
		return notify_fail("你的修行经验不够，没法降等。\n");
	if (me->query("newjobs/completed/shenni")<=30)
	{
		return notify_fail("才这么点神尼等级就来降等？做梦！\n");
	}
    if (sscanf(arg, "%d", times) == 1)
    {
		if ((me->query("exp_dep")<times))
		{
			return notify_fail("你的修行经验没有你输入的多，看清楚再输入正确值。\n");
		}
        if (times<10000)
			return notify_fail("一次降等使用的修行经验至少一万点。\n");
        if (times>me->query("combat_exp")/10)
			return notify_fail("一次不能使用超过本身一成的修行经验。\n");
        factor=(int)this_object()->query("rate");
        me->add("exp_dep",-times);
		loop_time=(int)times/10000;
        message_vision(HIY"$N开始仔细操弄浑天仪，口中念念有词:'神尼保佑,降等成功~~~'\n"NOR,me);

		if (loop_time)
		{
			for (i=0;i<loop_time;i++ )
			{
				random_p=random(factor);
				if (random_p<15)
				{
					me->add_busy(2);
					me->add("newjobs/completed/shenni",-1);
					tell_object(me,"你消耗了"+chinese_number(times)+"点修行经验，成功对神尼等级实行降等。\n");
					return 1;
				}
			}
		}
        me->add_busy(2);
        return notify_fail("很遗憾你没有降等成功。\n");
    }
    else
    {
        return notify_fail("请用jiangdeng <经验数>用来确定降等使用消耗的实战经验。\n");
    }

}

int do_zhenbie(string arg)
{
    object me=this_player();
    string arg_id;
    if (me->is_busy() || me->is_fighting())
    return notify_fail("你正忙着呢！\n");
   if (me->query("combat_exp")<1600000)
    return notify_fail("你怎么小的id，来查什么查。\n");
if( !arg || sscanf(arg, "%s", arg_id)!=1 )
		return notify_fail("乱查什么查！请用zhenbie machine或者zhenbie 你的id 来辨别是否正常。\n");
	else
	{
		if (arg_id == "machine")
		{
	        message_vision(HIY"$N翻来覆去地仔细摩挲浑天仪，左看右看……\n"NOR,me);
			call_out("jiancha_jieguo",1,me,arg_id);
		}
		else
		{
			if (arg_id == me->query("id"))
			{
				message_vision(HIY"$N一把拉动浑天仪，让浑天仪旋转了起来……\n"NOR,me);
				call_out("jiancha_jieguo",1,me,arg_id);
			}
			else
				return notify_fail("这个。。。您老人家要甄别什么东西？\n");
		}
		return 1;
	}


}

int relative_event()
{
	object *all_player,luckyone,qinqi;
	string color=GRN;
	all_player = filter_array(children(USER_OB), (: userp :));
	all_player = filter_array(all_player, (: environment :));
	all_player = filter_array(all_player, (: $1->query("relationship/target") :) );
	if(!sizeof(all_player)) return 0;
	luckyone=all_player[random(sizeof(all_player))];
	if (luckyone)
	{
		luckyone->set_temp("relative/wanted",1);
		luckyone->apply_condition("relativewanted",20+random(10));
		if (sizeof(all_player)>10)
		{
			color=HIB;
			luckyone->add_temp("relative/wanted",1);
		}
		if (sizeof(all_player)>50)
		{
			color=HIG;
			luckyone->add_temp("relative/wanted",1);
		}
		if (sizeof(all_player)>100)
		{
			color=HIY;
			while (luckyone->query("relationship/freesp"))
			{
				luckyone=all_player[random(sizeof(all_player))];
			}
			luckyone->add_temp("relative/wanted",1);
		}
		if (luckyone->query("relationship/target_basename"))
		{
			qinqi=load_object(luckyone->query("relationship/target_basename"));
			if (qinqi&&living(qinqi))
			{
				tell_object(luckyone,BLINK+color+"你的亲戚"+luckyone->query("relationship/target_name")+BLINK+color+"好像有事正急着找你呢。\n"+NOR);
				tell_object(luckyone,HIG+qinqi->query("name")+HIG+"("+qinqi->query("id")+")告诉你：快来快来，肥水不留外人田，有好事当然想着你了。\n"+NOR);
			}
        }
	}
}
void Karma_start()
{
	if (objectp(STATISTIC_D->query("Karma_Holder")))
	STATISTIC_D->query("Karma_Holder")->start();
}
int gettime()
{
    mixed* timeinfos;
    int w_day,hour,minute,rate,*Karma_weekdays=({5,6,7}),*Karma_hours=({9,11,13,15,17,19,21});
    timeinfos = localtime(time());
	w_day=timeinfos[LT_WDAY];
    hour = timeinfos[LT_HOUR];
    minute = timeinfos[LT_MIN];
    if (random(minute)>25&&!random(3))
	{
		relative_event();
	}
	if (member_array(w_day,Karma_weekdays)!=-1&&member_array(hour,Karma_hours)!=-1&&minute>0&&minute<11)
	{
		Karma_start();
	}
    if (hour==7&&minute>10&&minute<21)
    {
        if (!this_object()->query("report"))
        {
            rate=120+random(41);
            set("report",1);
            set("rate",rate);
        }
		CHANNEL_D->do_channel(this_object(), "jh", HIR"大宋司天监推算，今日经验修行经验转化率：“"+chinese_number(query("rate"))+"”。\n", -1);
    }
    if (hour==23)
    delete("report");
    remove_call_out("gettime");
    call_out("gettime",600);
    return 1;
}


int jiancha_jieguo(object me, string arg)
{
	if (arg=="machine")
	{
		if (random(2))
		{
		   message_vision(HIY"这台机器一切正常，十足金属架构！但是你这么跪舔这台机器，看起来好像非人类呢！\n"NOR,me);
		}
		else
		{
		   message_vision(HIY"这台机器一切正常，十足金属架构！但是你看起来有点像正常又有点不像正常！\n"NOR,me);
		}

	}
	else
	{
 	   write(HIY"\n浑天仪转了半天停了下来！\n从里面掉出来个小丸子上面显示着几个大字：\n"NOR);

		if (me->query("hsz_auto"))
		{
		   message_vision(HIR"非正常人类！\n"NOR,me);
		}
		else
		{
		   message_vision(HIG"正常人类！\n"NOR,me);
		}

	}
return 1;
}
