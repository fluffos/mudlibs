
#include <ansi.h>
inherit NPC;
int ask_job();
int ask_finish();
#include <cooldown.h>
#include "/d/luoyang/npc/reward.h"
#define JOB "gongsun"
void create()
{
    set_name("公孙止",({"gongsun zhi","gongsun","zhi"}));
	set("title",HBWHT+RED+"绝情"+HIB+"谷主"+NOR);
	set("shen_type", 1);
	set("long","他是绝情谷谷主，身穿宝蓝缎子长袍，面目英俊，举止潇洒，上唇与颏下留有微髭。\n");
	set("str", 50);
	set("int",50);
	set("dex",50);
	set("con",50);
	set("gender", "男性");
	set("age", 45);
	set("combat_exp", 60000000);
	set("attitude", "friendly");
	set("inquiry", ([
			"job" : (: ask_job :),
			"fail" : (: ask_fail :),
			"放弃" : (: ask_fail :),
			"finish" : (: ask_finish :),
			"复命" : (: ask_finish :),
       	]) );
	set("per",40);
	set("job_id","公孙止");
	set("job_eid","gongsun");
	set("no_get",1);
	setup();
    carry_object("/d/jueqinggu/npc/obj/cloth-1")->wear();

}
int ask_job()
{
	object where,target,me=this_player();
	string msg="",respect = RANK_D->query_respect(me);
	int pin=random(1000000);
	if (time()-me->query_temp("askjob")-me->query_temp("askjobtimes")<=0)
	{
		me->add_temp("askjobtimes",1);
		tell_object(me,"过"+(me->query_temp("askjob")-time()+me->query_temp("askjobtimes"))+"秒再来问吧。\n");
		return 1;
	}
	else
	{
		me->set_temp("askjob",time());
		me->delete_temp("askjobtimes");
	}
	if(me->is_fighting())
	{
		command("say 你先打完架吧。");
		return 1;
	}
	if(me->query_temp(JOB+"/job"))
	{
		command("say 这位"+respect+"，不是已经给过你任务了么？");
		return 1;
	}
	if(me->query(JOB+"/on_job"))
	{
		command("say 这位"+respect+"，上次交给你的任务还没有完成么？");
		return 1;
	}
	if(!wizardp(me) && time() - query("last_give_time") < 10)
	{
		command("say 刚刚已经有人去接应谷里弟子了，多谢"+respect+"好意。");
		return 1;
	}
	if(IfInCoolDown(me,1))
	return 1;
	if(me->query("level") < 30)
	{
		command("say "+respect+"，谷里弟子不见踪影，恐怕必有一番恶战，你还是等武功有成再来吧。");
		return 1;
	}
	set("last_give_time", time());
	while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
		  where->query("hsz_no_task"))
	{
		where = MAP_D->random_place();
	}
	me->set_temp(JOB+"/pin",pin);
	target=new("/d/jueqinggu/npc/target");
	target->move(where);
	target->owner(me);
	if (!target) 
	{
		command("say 刚刚已经有人去接应谷里弟子了，多谢"+respect+"好意。");
		return 1;
	}
	me->set_temp("task_stat/"+JOB+"/gongsun_starttime",time());
	me->set(JOB+"/on_job", 1);
	me->set_temp(JOB+"/job","接应弟子");
	me->set(JOB+"/last_job", time());
	me->set_temp(JOB+"/where",where);
	message_vision("$N神色凝重地向$n说了一番话。\n",this_object(),me);
	command("tell "+me->query("id")+" 我谷中弟子外出办事，久无音讯传回，恐有不测。你去此处查看一番。");
	ANTIROBOT_D->mxpantirobot_ex(me,"在"+TASK_D->place_belong(where)+"的"+where->query("short"));
	return 1;
}
int do_reward(object me)
{
	string msg;
	int reward, cost_time,times,exp,finish;
	string channel_msg,system_msg = me->query("name")+"在"+this_object()->query("job_id")+"任务中获得奖励";
	times=me->query("jobs/completed/"+this_object()->query("job_eid"));
	if (times>5000) times=5000;
	if (times<1000) times/=100;
	else times=10+(times-1000)/280;
	exp=me->query("combat_exp");
	if (exp>800000000) exp=800000000;
	if (exp<200000000) exp/=40000000;
	else exp=5+(exp-200000000)/150000000;
	channel_msg = me->query("name")+"完成公孙止任务，被奖励了";
	reward = 10000+500*(times+exp*2+10);
	finish=me->query_temp(this_object()->query("job_eid")+"/finish");
	if (finish==1) reward/=2;
	if (finish==2) reward=reward*2/3;
	if (finish>=3) reward=reward*6/5;
	reward += me->query_temp(this_object()->query("job_eid")+"/bonus");
	reward = reward *2/3 + random(reward/3);
	if (me->query("special_skill/lucky") && me->query("age")>=18)
	reward = reward + reward/10; //有lucky的玩家奖励多10%
	reward = reward * SPEWEEK_D->query_xiaofeng_bonus()/100;//whuan特殊周效果
	//reward*=this_object()->MyProBonus(me);
	write(HIW"你被奖励了：\n");
	reward = REWARD_D->add_exp(me,reward);
	write("\t"+chinese_number(reward)+"点经验；\n");
	system_msg += reward+"点经验，";
	channel_msg += chinese_number(reward)+"点经验、";
	me->add("exp/"+this_object()->query("job_eid"), reward);

	//加入任务统计系统 by icer
	cost_time = time()-me->query_temp("task_stat/"+this_object()->query("job_eid")+"/"+this_object()->query("job_eid")+"_starttime");
    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/complete_times",1);
    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/cost_time",cost_time);
    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/exp",reward);
    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/expratio",to_float(reward)/me->query("combat_exp"));

	//萧峰奖励以经验奖励为基数，所以只在经验奖励中加入reward_d管理，如果以后不以经验奖励为基数了，还需要在潜能和声望奖励中加入reward_d管理
	reward = random(reward)/2 + reward/5;
	write("\t"+chinese_number(reward)+"点潜能；\n");
	system_msg += reward+"点潜能，";
	channel_msg += chinese_number(reward)+"点潜能、";
	me->add("potential", reward);
	me->add("pot/"+this_object()->query("job_eid"), reward);

    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/pot",reward);

	reward = 200 + random(reward)/1000*100;
	write("\t"+chinese_number(reward)+"点江湖声望。\n");
	system_msg += reward+"点江湖声望";
	channel_msg += chinese_number(reward)+"点江湖声望";
	me->add("repute", reward);

    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/repute",reward);
	me->add("jobs/completed/"+this_object()->query("job_eid"), 1);        //任务平衡系统，统计所有任务完成的次数  by boost  2008.09.19
	write("你已经完成了"+chinese_number(me->query("jobs/completed/"+this_object()->query("job_eid")))+"次"
		+me->query_temp(this_object()->query("job_eid")+"/job")+"的工作。\n"NOR);
	command("say 少量银两存入你的账户，聊表心意。");
  	me->add("balance",15000+random(10000));
	system_msg += "。";
	CHANNEL_D->do_channel(this_object(), "sys_misc", system_msg);
	me->delete_temp(this_object()->query("job_eid"));
	me->delete(this_object()->query("job_eid")+"/on_job");
	return 1;
}
string gem_drop_msg(object me,object item)
{
	return query("name")+"拿出了一"+item->query("unit")+item->name()+"交给了"+me->name()+"，作为酬谢。\n";
}
int ask_finish()
{
	object me = this_player();
	string rank;
	if( !me->query_temp(JOB+"/finish") || 
		  me->query_temp(JOB+"/fail") || 
		  !me->query(JOB+"/on_job") )
	{
		command("tell "+me->query("id")+" 你完成了吗？");
		return 1;
	}
	ANTIROBOT_D->same_as_fullme(me);
	if (me->query("rank_info/respect"))
		rank=me->query("rank_info/respect");
	else
		rank="兄弟";
	command("say 我知道了。"+rank+"，干的不错。");
	if (!me->query("biography/jobs/gongsun"))
	me->set("biography/jobs/gongsun",time());//个人传记记录第一次完成任务时间ZINE
	if (me->query_temp(JOB+"/finish")>=3)
	GEM_D->drop(this_object(),me);	
	do_reward(me);
	
	return 1;
}
void die()
{
	::die();
}