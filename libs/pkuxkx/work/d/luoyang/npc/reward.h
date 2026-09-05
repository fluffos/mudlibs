//加强一点额外宝石等级 fix by yhzzyahoo@15.7.23 再加强一些@15.8.3
//为教训模式做点准备by yhzzyahoo
#include <ansi.h>

int ask_fail()
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
    reward=-8000;
    preward=-3000;
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

int give_reward(object me)
{
	string msg;
	object letter,xiliandan;
	string *slo=({"goodman","u&me2","ambition","clever"});
	string *gems=({"gu","yu","jiao","jia"});
	object gem,material;
	int reward, i, cost_time, hard, j;
	int id_mf;
	string respect = RANK_D->query_respect(me);
	mapping skills = me->query_skills();
	string* sname,extra_msg="";
	string skill;
	string job_type = me->query_temp(this_object()->query("job_eid")+"/job_type");
	string channel_msg,system_msg = me->query("name")+"在"+this_object()->query("job_id")+"任务中获得奖励";
	extra_msg=me->query_temp(this_object()->query("job_eid")+"/job");
	channel_msg = me->query("name")+extra_msg+"，被奖励了";

	if(!random(30)||wizardp(me))
		CHANNEL_D->do_channel(this_object(), "bd", slo[random(sizeof(slo))]+" "+me->query("id"), 1);
	reward = 6000+me->query_temp(this_object()->query("job_eid")+"/job_level")*2000;
	reward += me->query_skill("force");
	reward += me->query_skill("dodge");
	reward += me->query_skill("parry");
	reward += me->query_skill("literate", 1) * 2;
	reward += me->query_temp(this_object()->query("job_eid")+"/bonus");
	
//    if(me->query("combat_exp") > 300000000)
//		reward = reward / 3;
	reward = reward / 2 + random(reward);
	if (me->query("special_skill/lucky") && me->query("age")>=18)
	reward = reward + reward/10; //有lucky的玩家奖励多10%
	if (me->query_combatgrade() < 40) //经验小于3.2M做萧峰额外奖励10%，配合cut护卫及引导玩家早去尝试多种任务 by Zine 10 Nov 2010
	reward=reward*11/10;
	if (me->query_temp("extrajob/xf"))
	{
		me->delete_temp("extrajob/xf");
		reward=reward*2;
	}
	
	if ( me->query_temp("xiaofeng/hard") )
	{
	  hard=1;
	  reward=reward*130/100;
	  me->delete_temp("xiaofeng/hard");
	}
	if ( me->query_temp("xiaofeng/job_type")=="教" )
	{
	  reward=reward*130/100;
	  me->delete_temp("xiaofeng/jiao_type");
	}
	log_file("user/hanszlog",ctime(time())+":"+me->query("id")+"韩世忠任务步骤1:"+reward+"\n");				
	if (me->query("hsz_auto"))
	{
		reward *=3;
		reward >>=2;
	}
	else
	{
	if ((me->query_temp("hansz/finish_degree")<1)&&(this_object()->query("job_eid")=="hansz"))
		{
		reward *=4;
		reward /=5;
		}
		/*else
		{if (me->query_temp("hansz/finish_degree")==1)
		{
			reward += reward /20;
		}
		}*/
	}
	log_file("user/hanszlog",ctime(time())+":"+me->query("id")+"韩世忠任务步骤2:"+reward+"\n");				

	reward = reward * SPEWEEK_D->query_xiaofeng_bonus()/100;//whuan特殊周效果

	if (me->query(this_object()->query("job_eid")+"/pic_fail")>=2)
	reward/=me->query(this_object()->query("job_eid")+"/pic_fail");
	reward*=this_object()->MyProBonus(me);
	write(HIW"你被奖励了：\n");
	reward = REWARD_D->add_exp(me,reward);
	write("\t"+chinese_number(reward)+"点经验；\n");
	system_msg += reward+"点经验，";
	/*if (this_object()->query("job_eid")=="hansz")
	log_file("user/new_job_test",sprintf("%s%d%s\n",me->query("id"),reward,"于"+ctime(time())+"at"+this_object()->query("job_eid")));*/
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
	if ( hard )
	  reward=reward*130/100;
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
	if (job_type)
	{
		me->add(this_object()->query("job_eid")+"/"+job_type, 1);
		write("你已经完成了"+chinese_number(me->query(this_object()->query("job_eid")+"/"+job_type))+"次"
		+me->query_temp(this_object()->query("job_eid")+"/job")+"的工作。\n"NOR);
	}
	else
	write("你已经完成了"+chinese_number(me->query("jobs/completed/"+this_object()->query("job_eid")))+"次"
		+me->query_temp(this_object()->query("job_eid")+"/job")+"的工作。\n"NOR);
  if (this_object()->query("job_eid")=="xiaofeng")
	{
	  j=4;
	}
	else
	{
		j=2;
	}
	if (me->query("hsz_auto"))
	{
		j=1;
	}
	if(wizardp(me) || !random(2+me->query_kar()/j) && sizeof(skills)>10)
	{
		command("say 武功本身并无善恶，端在人之为用。行善则武功愈强愈善，肆恶则愈强愈恶。");
		message_vision(YEL"$N指点了$n几招，$n只觉脑中豁然开朗！\n"NOR, this_object(), me);
    
    for(int ixi=0;ixi<5;ixi++)
    {
      sname = keys(skills);
      i = random(sizeof(sname));
      skill = sname[i];
      
      if ( !intp(skills[skill]) )
      {
      	skill="force"; 
      	continue;
      } //多层技能的不奖励等级
      
/*      if(me->query_skill(skill,1)<=10) 
      {
      	skill="force"; 
      	continue;
      } //10级以下不奖励功夫
*/
      if(me->query_skill(skill,1)<80)
      {
      	skill="force"; 
      	continue;
      } //不奖励80级以下功夫 by lordstar 20180326

      if(skill == "yunu-xinfa" && me->query("family/family_name")!="古墓派" 
		&& me->query_skill(skill,1)>=105 ) 
      {
        skill="force"; 
        continue;
      }//非古墓派最多奖励玉女心法到105     2018年3月26日caijue               
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
    if(SKILL_D(skill)->valid_enable("force") && random(3))
			skill = "force";
		write(HIC"你的「"+CHINESE_D->chinese(skill)+"」进步了！\n"NOR);
		if ( hard )
		{
		  system_msg += "，二级"+skill;
		  channel_msg += "，二级"+CHINESE_D->chinese(skill);
		  me->set_skill(skill, me->query_skill(skill, 1)+2);
		}
		else 
		{
		  system_msg += "，一级"+skill;
		  channel_msg += "，一级"+CHINESE_D->chinese(skill);
		  me->set_skill(skill, me->query_skill(skill, 1)+1);
		}
		channel_msg += "！\n";
        if(random(30))
        {
    		CHANNEL_D->do_channel(this_object(), "rw", channel_msg);
        }

	    COMBAT_D->add("task_stat/"+this_object()->query("job_eid")+"/skill",1);
		
	}
  else
  {
  	command("say 我也筹集了一些银两，已经嘱人存入你的帐户。");
  	command("say 虽然不多，但是略表心意。");
// 提高任务奖励。by lordstar 20171016
  	me->add("balance",28000+random(15000));
  }
	system_msg += "。";
	CHANNEL_D->do_channel(this_object(), "sys_misc", system_msg);
	me->delete_temp(this_object()->query("job_eid"));
	me->delete(this_object()->query("job_eid")+"/on_job");

    if ((int)me->query("jobs/completed/"+this_object()->query("job_eid"))%80==79)
        {
            letter=new("/d/changjiang/obj/letter");
            letter->set("owner",me->query("id"));
            letter->move(me);
            tell_object(me,this_object()->name()+"身上掉下了一封信，你赶忙捡了起来。\n");
        }
  if (this_object()->query("job_eid")=="xiaofeng" && me->query("hsz_auto")==0)
  {
	  if (random(10000)>9993 )
	  {
		xiliandan= new("/d/changjiang/obj/special-ob.lpc");
		xiliandan->move(me);
		CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成萧峰任务，获得特质洗炼丹一颗。");
	  }
	 id_mf=(int)me->query_temp("apply/magic");
// 提高任务奖励。by lordstar 20171016
	 i=2-(int)id_mf/2000;

	 if (i<1)
	 {
		 i=1;
	 }
	 id_mf=(int)id_mf/5;
	if (random(i)==0)
	{
		gem=new("/obj/gem/gem");
		id_mf += 7500;
		i = id_mf + random(2500);
		if (i>10000) i=10000;
		gem->set_level(id_mf,i,gems[random(sizeof(gems))]);
		gem->move(me);
		write("\n萧峰给你一颗"+gem->name()+"作为额外奖励！\n");  
	}

//增加无常造化丹药材掉落。by lordstar 20171102
	if (random(10000)>9989) // && !me->query("hsz_auto"))
	{
	  material=new("/obj/remedy/drug/wuchang-material");
	  if (objectp(material))
	  {
		  material->set("owner", me->query("id"));
		  material->move(me);
		  tell_object(me, this_object()->name()+"又送你一份罕见的珍贵药材作为额外馈赠。\n");
	  }
	}
  }
	return 1;
}

