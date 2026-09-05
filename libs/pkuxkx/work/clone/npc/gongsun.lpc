
#include <ansi.h>
inherit NPC;
int ask_job();
int ask_finish();
int ask_daoluan();
int ask_jobfail();
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
	set("max_qi", 40000);
	set("max_jing", 50000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 1000);
	set("combat_exp", 600000000);
	set("attitude", "friendly");
	set_skill("literate", 2000);
	set_skill("force", 1600);
	set_skill("dodge", 1600);
	set_skill("parry", 1600);
	set_skill("strike", 1600);
	set_skill("luoxuan-jiuying",1600);
	set_skill("bingchuan-xinfa", 1600);
	set_skill("taiyi-zhang", 1600);
	map_skill("dodge", "luoxuan-jiuying");
	map_skill("force", "bingchuan-xinfa");
	prepare_skill("strike","taiyi-zhang");
	set("inquiry", ([
			"job" : (: ask_job :),
			"fail" : (: ask_jobfail :),
			"放弃" : (: ask_jobfail :),
			"finish" : (: ask_finish :),
			"复命" : (: ask_finish :),
	        "阴阳倒乱刃" : (: ask_daoluan() :),
		    "daoluan" : (: ask_daoluan() :),
       	]) );
	set("per",40);
	set("job_id","公孙止");
	set("job_eid","gongsun");
	set("no_get",1);
	setup();
    carry_object("/d/jueqinggu/npc/obj/cloth-1")->wear();

}

//任务npc不死
void unconcious()
{
	die();
}

void die()
{
	set("eff_qi",this_object()->query("max_qi"));
	set("qi",this_object()->query("max_qi"));
	set("eff_jing",this_object()->query("max_jing"));
	set("jing",this_object()->query("max_jing"));
	return;
}

//倒乱刃任务相关
int ask_daoluan()
{
	object me=this_player();
	if (me->query("int")<21 || me->query("zyhb") || me->query("hubo"))
	{
		command("say 你这么愚笨不堪，焉能学习我家绝学！");
		return 1;
	}
	if (me->query("daoluan-learn"))
	{
		command("say 我不是把『阴阳倒乱刃』传给你了吗？你自己忘了可与我没啥关系了！");
		return 1;
	}
	if (!me->query_temp("daoluancanask"))
	{
		command("? " + me->query("id"));
		command("say 『阴阳倒乱刃』是什么玩意？用来切菜的？");
		return 1;
	}
	else
	{
		command("say 看你在我这里辛苦了好久，我就把阴阳倒乱刃传授于你。但是，倒乱刃的绝招可另需机缘才可获得。");
		me->set_skill("yinyang-daoluan",10);
		tell_object(me,"你学会了『阴阳倒乱刃』\n");
		CHANNEL_D->do_channel(this_object(), "jh", HIW + "听说" + me->query("name") +HIW "习得了绝情谷的绝技——『阴阳倒乱刃』!", -1);
		me->set("daoluan-learn",1);
		return 1;
	}
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
		tell_object(me,"这位"+respect+"，不是已经给过你任务了么？\n");
		me->start_busy(2+random(2));
		return 1;
	}
	if(me->query(JOB+"/on_job"))
	{
		tell_object(me,"这位"+respect+"，上次交给你的任务还没有完成么？\n");
		me->start_busy(2+random(2));
		return 1;
	}
	if(!wizardp(me) && time() - query("last_give_time") < 10)
	{
		tell_object(me,"刚刚已经有人前去了，多谢"+respect+"好意。\n");
		me->start_busy(2+random(2));
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
//	write("他在"+TASK_D->place_belong(where)+"的"+where->query("short"));
	ANTIROBOT_D->mxpantirobot_ex(me,"在"+TASK_D->place_belong(where)+"的"+where->query("short"));
	return 1;
}

int ask_jobfail()
{
    int reward,preward;
	object me = this_player();
	string msg;

	if(!me->query(this_object()->query("job_eid")+"/on_job"))
	{
		//command("say 你又没有任务，如何轻言放弃！\n");
		tell_object(me,"你又没有任务，如何轻言放弃！\n");
		me->start_busy(2+random(2));
		return 1;
	}
	if (me->query_temp(this_object()->query("job_eid")+"/pic_job"))
	me->add(this_object()->query("job_eid")+"/pic_fail",1);
	msg = CYN"$n叹了口气，说道：「好吧，这也是有些难为你了。」\n";
	msg += "$n记了些什么，对$N挥了挥手，示意让$N退下。\n"NOR;
	message_vision(msg, me, this_object());
    reward=-2000;
    preward=-8000;
    reward = REWARD_D->add_exp(me,reward);
    me->add("exp/"+this_object()->query("job_eid"),reward);
    preward = REWARD_D->add_pot(me,preward);
    me->add("pot/"+this_object()->query("job_eid"),preward);
	tell_object(me,HIW"由于放弃任务，你被扣了经验" + chinese_number(-reward) + "点，潜能" + chinese_number(-preward) + "点！\n"NOR);
	if(me->query("combat_exp") < 2000)
		me->set("combat_exp", 2000);
	if ( objectp(me->query_temp(this_object()->query("job_eid")+"/target_ob") ) )
	{
		me->remove_killer(me->query_temp(this_object()->query("job_eid")+"/target_ob"));
		destruct(me->query_temp(this_object()->query("job_eid")+"/target_ob"));
	}
	me->delete_temp(this_object()->query("job_eid"));
	me->delete(this_object()->query("job_eid")+"/on_job");
	me->set(this_object()->query("job_eid")+"/last_fail", time());
	return 1;
}

int do_reward(object me)
{
	string msg;
	int reward,preward,rreward,cost_time,times,exp,finish;
	object gem, material;
	string *gems=({"gu","yu","jiao","jia"});
	int id_mf,i;
	mapping skills = me->query_skills();
	string* sname,extra_msg="";
	string skill;
	int ixi;
	string channel_msg,system_msg = me->query("name")+"在"+this_object()->query("job_id")+"任务中获得奖励";
	times=me->query("jobs/completed/"+this_object()->query("job_eid"));
	if (times>5000) times=5000;
	if (times<1000) times/=100;
	else times=10+(times-1000)/250;
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
	if (reward > 34000)
	{
		reward = 34000+random(1000);
	}
	reward = reward * SPEWEEK_D->query_xiaofeng_bonus()/100;//whuan特殊周效果
	//reward*=this_object()->MyProBonus(me);
	write(HIW"你被奖励了：\n");
	// 大幅度降低经验奖励，增加潜能奖励。by lordstar 2017/8/24
	reward /= 20;	
	
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
	reward *= 15+random(6);
	//加大随机性@yhzzyahoo  
	// 大幅度增加潜能奖励。by lordstar 2017/8/24
	preward = random(reward)/5 + 9*reward/10;

	write("\t"+chinese_number(preward)+"点潜能；\n");
	system_msg += preward+"点潜能，";
	channel_msg += chinese_number(preward)+"点潜能、";
	me->add("potential", preward);
	me->add("pot/"+this_object()->query("job_eid"), preward);

    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/pot",preward);

	rreward = 200 + random(preward)/10;
	write("\t"+chinese_number(rreward)+"点江湖声望。\n");
	system_msg += rreward+"点江湖声望";
	channel_msg += chinese_number(rreward)+"点江湖声望";
	me->add("repute", rreward);

    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/repute",rreward);
	if (finish>=3)	me->add("jobs/completed/"+this_object()->query("job_eid"), 1);        //任务平衡系统，统计所有任务完成的次数  by boost  2008.09.19
	write("你已经完成了"+chinese_number(me->query("jobs/completed/"+this_object()->query("job_eid")))+"次"
		+me->query_temp(this_object()->query("job_eid")+"/job")+"的工作。\n"NOR);
	if (!me->query("gongsun/transfer"))
	{
		me->set("gongsun/transfer",1);
		me->set("gongsun/credit",15*me->query("jobs/completed/gongsun"));
	}
	me->add("gongsun/credit",(random(3)+4)*finish);
	write("你现在在绝情谷的威望达到"+chinese_number(me->query("gongsun/credit"))+"点。\n");
	command("say 少量银两存入你的账户，聊表心意。");
// 提高任务奖励。by lordstar 20171016
  	me->add("balance",20000+random(15000));
	
	system_msg += "经验"+reward+"点，"+"潜能"+preward+"点，"+"声望"+rreward+"点。";
	CHANNEL_D->do_channel(this_object(), "sys_misc", system_msg);
	if(wizardp(me) || !random(5+me->query_kar()/2) && sizeof(skills)>10 &&  finish>=3)
	{
		command("say 武功本身并无善恶，端在人之为用。行善则武功愈强愈善，肆恶则愈强愈恶。");
		message_vision(YEL"$N指点了$n几招，$n只觉脑中豁然开朗！\n"NOR, this_object(), me);
    
    for(ixi=0;ixi<5;ixi++)
    {
      sname = keys(skills);
      i = random(sizeof(sname));
      skill = sname[i];
      
      if ( !intp(skills[skill]) )
      {
      	skill="force"; 
      	continue;
      } //多层技能的不奖励等级
      
      if(me->query_skill(skill,1)<=10) 
      {
      	skill="force"; 
      	continue;
      } //10级以下不奖励功夫

      if(me->query_skill(skill,1)<=80 &&
      	 random(100)<=40 )
      {
      	skill="force"; 
      	continue;
      } //降低80级以下功夫被奖励的机会
                
      if(skill == "tianmo-jieti") 
      {
      	skill="force"; 
      	continue;
      };//不奖励天魔解体
      
      if(skill == "business") 
      {
      	skill="force"; 
      	continue;
      };//不奖励经商之道
      if (SKILL_D(skill)->professional())
	  {
		  skill="force";
		  continue;
	  };//不奖励专业技能
      break;
    }
    
    //降低奖励特殊内功的几率，增加偷师难度 
    if(SKILL_D(skill)->valid_enable("force") && random(5))
			skill = "force";
		write(HIC"你的「"+CHINESE_D->chinese(skill)+"」进步了！\n"NOR);
		/*if ( hard )
		{
		  system_msg += "，二级"+skill;
		  channel_msg += "，二级"+CHINESE_D->chinese(skill);
		  me->set_skill(skill, me->query_skill(skill, 1)+2);
		}
		else */
	//	{
		  system_msg += "，一级"+skill;
		  channel_msg += "，一级"+CHINESE_D->chinese(skill);
		  me->set_skill(skill, me->query_skill(skill, 1)+1);
	//	}
		channel_msg += "！\n";
/*        if(random(20))
        {
    		CHANNEL_D->do_channel(this_object(), "rw", channel_msg);
        } */

	    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/skill",1);
		
	}
	else 
		channel_msg += "！";
	if ( preward>8000 && !random(5) &&!wizardp(me) )  CHANNEL_D->do_channel(this_object(), "rw", channel_msg);
	if (me->query("jobs/completed/gongsun")*me->query("kar")>random(10000)+18000+random(10000)&&!me->query("daoluan_learn"))
	{
			me->set_temp("daoluancanask",1);
			tell_object(me,HIC"你心念一动，也许此时公孙止会告知你『阴阳倒乱刃』的秘密。\n"NOR);
	}

	 if (finish>=3)
	 {
	 	 id_mf=(int)me->query_temp("apply/magic");
// 提高任务奖励。by lordstar 20171016
		 i=3-(int)id_mf/1000;
		 if (i<1)
		 {
			 i=1;
		 }
		 id_mf=(int)id_mf/5;
		if (random(i)==0)
		{
			gem=new("/obj/gem/gem");
			id_mf += 6000;
			i = id_mf + random(4000);
			if (i>10000) i=10000;
			gem->set_level(id_mf,i,gems[random(sizeof(gems))]);
			gem->move(me);
			write("\n公孙止给你一颗"+gem->name()+"作为额外奖励！\n");  
		}
	}
	
//增加无常造化丹药材掉落。by lordstar 20171102
//  取消掉落。by lordstar 20171106
/*  if (random(10000)>9970 && !me->query("hsz_auto"))
  {
	  material=new("/obj/remedy/drug/wuchang-material");
	  if (objectp(material))
	  {
		  material->set("owner", me->query("id"));
		  material->move(me);
		  tell_object(me, this_object()->name()+"又送你一份罕见的珍贵药材作为额外馈赠。\n");
	  }
  }
*/  
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
		me->start_busy(2+random(2));
		return 1;
	}
	ANTIROBOT_D->same_as_fullme(me);
	if (me->query("rank_info/respect"))
		rank=me->query("rank_info/respect");
	else
		rank="兄弟";
	command("tell "+me->query("id")+" 我知道了。"+rank+"，干的不错。");
	if (!me->query("biography/jobs/gongsun"))
	me->set("biography/jobs/gongsun",time());//个人传记记录第一次完成任务时间ZINE
	if (me->query_temp(JOB+"/finish")>=3)
	GEM_D->drop(this_object(),me);	
	do_reward(me);
	
	return 1;
}
/*void die()
{
	object killer=get_damage_origin_object();
	log_file("user/gongsun_killer",sprintf("%s于%s杀死公孙止。\n",killer->query("id"),ctime(time())));
	::die();
}*/