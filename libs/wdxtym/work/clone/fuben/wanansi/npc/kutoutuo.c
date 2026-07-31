#include <ansi.h>;
inherit NPC;

int shilian();

void create()
{
	set_name("苦头陀", ({"ku toutuo"}));
	set("gender", "男性");
	set("age", 45);
	set("long","他就是苦头陀。\n");
	set("attitude", "peaceful");
 	set("no_death", 1);

	set("str", 38);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 250000);
	set("eff_qi", 250000);
	set("qi", 250000);

	set("neili", 19999);
	set("max_neili", 19999);
	
	set("combat_exp", 600000);

	set_temp("apply/damage", 666);
	set_temp("apply/armor", 300);
	set_temp("apply/speed", 300);

	set("chat_chance", 2);
	set("chat_msg", ({
		 "苦头陀叹道：“唉……如今魔道横行啊……”\n",
	}));

	set("inquiry", ([
		"闯万安寺" : (: shilian :),
	]));

	setup();
}

void init()
{
	set_heart_beat(1);
}

int shilian()
{
	object *t,me,env,tob;
	object slnpc,hero,slroom,*slrooms;
	mixed last,now;
	mapping fam;
	int i,baselv,k;
	now = localtime(time());
	me = this_player();

	if(me->query("last_wanan")) last = localtime(me->query("last_wanan"));
	else last = localtime(0);
	if((now[5]==last[5])&&(now[7]<=last[7])&&!me->query("wanan")){
		tell_object(me,ZJOBLONG"你本次试炼已结束，请明天再来！\n");
		return 1;
	}

	if (! pointerp(t = me->query_team())||sizeof(t)!=2)
	{
		tell_object(me,ZJOBLONG"必须是组成2人队伍才能进入！\n");
		return 1;
	}

	if (! me->is_team_leader())
	{
		tell_object(me,ZJOBLONG"还是让队长带着大家进吧！\n");
		return 1;
	}

	// 判断队伍中所有人的合法性
	env = environment(me);
	baselv = to_int(pow(to_float(me->query("combat_exp")*10),0.33333333));
	foreach (tob in t)
	{
		if(tob->query("last_wanan")) last = localtime(tob->query("last_wanan"));
		else last = localtime(0);
		if((now[5]==last[5])&&(now[7]<=last[7])&&!tob->query("wanan")){
			tell_object(me,ZJOBLONG"队伍中的"+tob->query("name")+"已经做过今天的万安寺任务了！\n");
			return 1;
		}

		if (environment(tob) != env)
		{
			tell_object(me,ZJOBLONG"现在你队伍中的人还没有到齐呢。\n");
			return 1;
		}

		if (! living(tob))
		{
			tell_object(me,ZJOBLONG"现在你队伍中还有人昏迷不醒呢。\n");
			return 1;
		}

		if (tob->is_fighting())
		{
			tell_object(me,ZJOBLONG"现在你队伍中有人正忙着打架呢。\n");
			return 1;
		}
		k = to_int(pow(to_float(tob->query("combat_exp")*10),0.33333333));
		if(baselv < k)
			baselv = k;
	}

	slrooms = children("/clone/fuben/wanansi/wanansi");
	for (i = 0; i < sizeof(slrooms); i++) {
		if(slrooms[i]->query("owner")==me->query("id"))
			slroom = slrooms[i];
	}

	if(!slroom)
	{
		slroom = new("/clone/fuben/wanansi/wanansi");
		slroom->set("owner",me->query("id"));
		if(!me->query("wanan")){
			t->set("wanan",1);
			t->set("last_wanan",time());
		}
		slroom->set("sllv",me->query("wanan")-1);
		slroom->set("baselv",baselv);
		slroom->nextlv(1);
	}
	message_vision("$N带领队伍进入万安寺宝塔。\n", me);
	t->move(slroom);
	return 1;
}
