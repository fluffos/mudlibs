// 万夫长
// create by zine 
#include <ansi.h>
#include <localtime.h>
inherit NPC;
int ask_code();
int ask_reward();
void create()
{
	set_name("万夫长", ({"wanfu zhang","zhang","wanfu"}));
	set("long", "他是铁木真帐下一名万夫长。\n");
	set("gender", "男性");
	set("age", 45);
    set("combat_exp", 10000000);
    set_skill("unarmed", 500);
    set_skill("force", 500);
    set_skill("dodge", 500);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
    set("uni_target",1);
	set("shen_type", 1);
	set("per",15);
    set("inquiry", ([
                "马贼":   (: ask_code() :),
                "robber":   (: ask_code() :),
				"领奖":   (: ask_reward() :),
				"reward":   (: ask_reward() :),
           
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth20")->wear();
}
int record_abnormal(object me,int exp)
{
	mapping record=me->query("statistic/menggu_mazei/gain_exp/");
    mixed record_items=keys(record);
	for (int i=0;i<sizeof(record_items);i++)
	{
		log_file("wiz/abnormal_mazei_"+me->query("id"),"exp:"+record_items[i]+record[record_items[i]]+"\t");
	}
	return 1;
}
int record_abnormal_money(object me,int money)
{
	mapping record=me->query("statistic/menggu_mazei/gain_money/");
    mixed record_items=keys(record);
	for (int i=0;i<sizeof(record_items);i++)
	{
		log_file("wiz/abnormal_mazei_"+me->query("id"),"money:"+record_items[i]+record[record_items[i]]+"\t");
	}
	return 1;
}
int ask_reward()
{
	object record,me=this_player(),ob=this_object(),jiudai;
	mixed* timeinfos=localtime(time());
    int day=timeinfos[LT_WDAY],exp,money;
	string abnormal_reward,today=sprintf("%d-%d-%d", timeinfos[5], timeinfos[4]+1, timeinfos[3]);
	if (day!=6&&!ob->query("permit_reward"))
	{
		command("say 只有每周六或者特殊情况才能集中来领赏，你到时候再来排队吧。");
		return 1;
	}
	if (today=me->query("statistic/menggu_mazei/last_reward"))
	{
		command("say 你今天已经领赏过了，当我这是卖菜的？别捣乱了。");
		return 1;
	}
	if (time()-ob->query("last_reward")<60)
	{
		if (time()-ob->query("last_reward")<10)
		{
			jiudai=new("/d/city/obj/jiudai");
			ob->set("water",0);
			jiudai->move(ob);
			command("say 你稍等等，今天人太多了，让我喝口水再说。");
			command("drink jiudai");
			destruct(jiudai);
		}
		else
		{
			command("say 让我歇一会。");
		}
		return 1;
	}
	ob->set("last_reward",time());
	record=load_object("/d/menggu/zeiwo");
	record->restore();
	exp=record->query("reward_for_exp/"+me->query("id")+"/points");
	money=record->query("reward_for_others/"+me->query("id")+"/points");
	if (exp<=0&&money<=0)
	{
		command("say 你一个马贼毛都没碰着，也来领奖？");
		return 1;
	}
	if (money)
	{
		message_vision("$N搬出了$n的犒赏，并直接转入了$n在月记的帐号。\n",ob,me);
		me->add("balance",money);
		tell_object(me,"你的奖赏一共是"+MONEY_D->money_str(money)+"\n");
		record->add("reward_for_others/"+me->query("id")+"/points",-money);
		record->save();
	}
	if (exp)
	{
		message_vision("$N开始大声宣读$n大战马贼的功绩。\n",ob,me);
		me->add("combat_exp",exp);
		tell_object(me,"你共获得"+chinese_number(exp)+"点经验奖励。\n");
		record->add("reward_for_exp/"+me->query("id")+"/points",-exp);
		record->save();
	}
	if (exp>10000000)
	{
		abnormal_reward=ctime(time())+me->query("name")+"("+me->query("id")+")在每月杀马贼活动中获得经验奖励"+exp+"(>10000000)点。\n";
		log_file("wiz/mazei_abnormal",sprintf("%s",abnormal_reward));
		if (me->query("statistic/menggu_mazei/gain_exp/"))
		record_abnormal(me,exp);
	}
	else
	{
		me->delete("statistic/menggu_mazei/gain_exp/");
	}
	if (money>10000000)
	{
		abnormal_reward=ctime(time())+me->query("name")+"("+me->query("id")+")在每月杀马贼活动中获得金钱奖励"+MONEY_D->money_str(money)+"(>1000金)。\n";
		log_file("wiz/mazei_abnormal",sprintf("%s",abnormal_reward));
		if (me->query("statistic/menggu_mazei/gain_money/"))
		record_abnormal_money(me,money);
	}
	else
	{
		me->delete("statistic/menggu_mazei/gain_money/");
	}
	me->set("statistic/menggu_mazei/last_reward",sprintf("%d-%d-%d", timeinfos[5], timeinfos[4]+1, timeinfos[3]));
	return 1;
}

int ask_code()
{
	object me=this_player(),manager,*mazei=({});
	string msg="近期，马贼在";
	int i,flag=0;
	if (time()-me->query_temp("menggu_ask_robbers")<30)
	{
		command("say 你不是刚问过吗？别没完没了的！");
		return 1;
	}
	if (!me->query("shediaoquest/jdfm"))
	{
		command("say 你不是成吉思汗信任的人，帮不了我什么忙。");
		tell_object(me,HIY+"需要完成『金刀驸马』才能接到这个任务！\n"+NOR);
		return 1;
	}
	me->set_temp("menggu_ask_robbers",time());
	if (!manager=find_object("/d/menggu/xiboliya"))
	{
		manager=load_object("/d/menggu/xiboliya");
	}
	if (!manager->query("mazei"))
	{
		command("say 马贼？什么马贼！");
		return 1;
	}
	mazei=manager->query("mazei");
	for (i=0;i<sizeof(mazei);i++)
	{
		if (!objectp(mazei[i]))
		continue;
		if (!environment(mazei[i]))
		continue;
		if (environment(mazei[i])->query("short"))
		{
			msg+=environment(mazei[i])->query("short")+" ";
			flag=1;
		}
	}
	if (flag==0)
	{
		manager->delete("mazei");
		manager->init_robbers();
		command("say 马贼？马贼在哪？我也不知道！");
		return 1;
	}
	msg+="等地出没。”\n";
	message_vision("$N道：“"+msg,this_object());
	return 1;
}