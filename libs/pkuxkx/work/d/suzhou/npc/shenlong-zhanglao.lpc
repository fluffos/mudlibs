// 胡一刀任务的镜像 Zine 23/05/2013
// 测试需要修改的地方142-146 行测试，152-153正式cd,154-158临时cd，211-221 行失败不扣经验
inherit NPC;
#define MAX_WAIT_TIME 600
#include <ansi.h>
#include <title.h>
#include <cooldown.h>
#include "/d/suzhou/npc/permit_list.h"
int ask_job();
int ask_cancel();
int ask_times();
int ask_pfm();
int ask_finish();
int give_reward(object me);
string *quest_fail_msg = ({
    CYN"看了看你，然后又失望地摇了摇头，什么也不说。\n"NOR,
    CYN"看起来很是生气，但似乎又发作不出来，只是轻轻哼了一声。\n"NOR,
    CYN"惊奇地问：”什么，连这个都没做好？？！！！”\n"NOR,
    CYN"沮丧地望着你，并不说话，但明显很失望。\n"NOR,
    CYN"叹了口气：“本来对你期望甚高，怎知你却如此辜负于我的苦心...”\n"NOR,
    CYN"摇了摇头：“我本不应该让你去的......”\n"NOR,
    CYN"冷哼一声：“怎的你竟是如此不中用？！！”\n"NOR,
    CYN"拍拍你的肩膀：“不要灰心，我知道你尽力了...”\n"NOR,
    CYN"对着你摇了摇头，说：“连这点事都做不好.....下去吧。”\n"NOR,
    CYN"看上去很不高兴，皱了皱眉头对你说：“下去歇着吧。”，嘴\nNOR"
    CYN"里嘟囔着：“真是没用。。。。”\n"NOR,
    CYN"疑惑地看着你：“怎么回事？怎么你。。。”\n"NOR,
    CYN"失望地看看你，慢慢地转过头去，跟别人说话去了。\n"NOR,
    CYN"嚷道：真是个饭桶！\n"NOR,
    CYN"一晃脑袋，叹息道：也罢，也罢，我本不该让你做这件事的。\n"NOR,
});



void create()
{
	set_name("神龙长老", ({"shenlong zhanglao", "zhanglao"}));
	set("gender", "男性");
	set("age", 55);
	set("long","这人是神龙教潜伏在江南地区的长老。\n");
	set("attitude", "friendly");
	set("no_get", "你当真不怕神龙教来找你麻烦吗？\n");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 17);
	set("qi", 3000);
	set("max_qi", 30000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 1000);
	set("combat_exp", 19000000);
	set("score", 200000);
	 
	set_skill("force", 350);
        set_skill("yangsheshu", 210);
        set_skill("zhaosheshu", 210);
        set_skill("shenlong-xinfa", 370);
        set_skill("dodge", 380);
        set_skill("yixingbu", 360);
        set_skill("strike", 360);
        set_skill("huagu-mianzhang", 360);
        set_skill("parry", 380);
        set_skill("literate", 280);
        set_skill("dagger", 350);
        set_skill("whip", 350);
        set_skill("shenlong-bian", 350);
        set_skill("dulong-bi", 350);

        map_skill("force", "shenlong-xinfa");
        map_skill("dodge", "yixingbu");
        map_skill("whip", "shenlong-bian");
        map_skill("dagger", "dulong-bi");
        map_skill("strike", "huagu-mianzhang");
        map_skill("hand", "shenlong-bian");
        prepare_skill("strike", "huagu-mianzhang");
	set("inquiry",([
		"job":     (: ask_job :),
		"训练教内弟子":  (: ask_job :),
		"失败":    (: ask_cancel :),
		"fail":  (: ask_cancel :),
		"次数":    (: ask_times :),
		"times":   (: ask_times :),
		"finish":     (: ask_finish :),
		"完成":  (: ask_finish :),
		//"绝招" :   (: ask_pfm :),
	   ]));
	set("job_id","神龙长老");
	set("job_eid","shenlong_zhanglao");
	set("shen_type",1);
	set("shen",0);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	//add_action("do_answer","answer");
}

int ask_times()
{
	command("say 到目前为止，你共完成了"+this_player()->query("shenlong_zhanglao/times")+"次任务！");
	return 1;
}


/*int ask_pfm()
{
	if (this_player()->query_skill("hujia-daofa",1)<250)
		{
			tell_object(this_player(),HIY"胡一刀给你讲了讲【刀影连环】的诀窍，不过你听了半天也不明白他在说什么。\n"NOR);
			return 1;
		}
	this_player()->set("daoying",1);
	tell_object(this_player(),HIY"胡一刀给你讲了讲【刀影连环】的诀窍。\n"NOR);
	return 1;
}
*/

void unconcious()
{
	die();
}

void die()
{
	this_object()->set("eff_qi",this_object()->query("max_qi"));
	this_object()->set("qi",this_object()->query("max_qi"));
	this_object()->set("eff_jing",this_object()->query("max_jing"));
	this_object()->set("jing",this_object()->query("max_jing"));
	return;
}

int ask_job()
{
	object me=this_player(),ob=this_object();
	object where,killer;
	if(!userp(me))
	return 0;
	if (!wizardp(me)&&member_array(me->query("id"),volunteer_list())==-1)
	{
		command("say 现在任务正在测试中，你可以找Zine报名参与。");
		return 1;
	}
	if ( me->query_combatgrade() < 40)
	{
		message_vision("$N笑道：这件事可没你想的那么简单，你好好练功吧!\n",ob);
		return 1;
	}
	/*if(IfInCoolDown(me,2))
	return 1;*/
	if (time()-me->query("shenlong_zhanglao/last_asked")<180)
	{
		command("say 测试也耐心点，3分钟还不到，又来？");
		return 1;
	}
	if (me->query("antirobot/deactivity") > 2) 
	message("vision",HIR"神龙长老瞄了你一眼说：“怎么又是你！我看你是机器人吧。”\n"NOR,me);
	me->set("shenlong_zhanglao/last_asked",time());
	me->set("shenlong_zhanglao/on_job",1);
	while (!objectp(where) || 
			!where->isroom()||
			TASK_D->place_belong(where)=="不明区域"||
			TASK_D->place_belong(where)=="未知区域"||
			base_name(where) == "/adm/daemons/taskd")
	where = TASK_D->random_place();
	killer=new(__DIR__"killer1");
	killer->move(where);
	for (int i=0;i<3;i++)
		killer->random_move();
   
	if (!killer)	//killer在移动期间晕倒或被房间call die了
	{
		message_vision("$N对$n说道：『我这里暂时没有什么弟子需要你帮忙训练的』\n",ob,me);
		return 1;
	}
	killer->do_copy(me);
	me->set_temp("shenlong_zhanglao/where",TASK_D->place_belong(where));
	me->set_temp("shenlong_zhanglao/killer",killer->query("name"));
	me->set_temp("shenlong_zhanglao/target_ob",killer); //加一个判断   
	me->set_temp("shenlong_zhanglao/target_id",killer->query("id"));
	message_vision("$N说道：『我派弟子"+killer->query("nickname")+killer->query("name")+"("+killer->query("id")
	+")在"+TASK_D->place_belong(where)+"等待训练,$n可否帮忙训练(drill)他！』\n",ob,me);
	command("push "+me->query("id"));
	return 1;   
}
int ask_cancel()
{
	int reward,preward;
	object me=this_player();
	object ob=this_object();
	
	if ( me->query("shenlong_zhanglao/on_job")==0)
	{
		message_vision("$N皱眉道：你又没有要任务，放弃什么？\n",ob);
		return 1;
	}
	if( (int)me->query("shenlong_zhanglao/last_asked") + 300 >= time() )
	{
		message_vision("$N说道：你才刚刚说要帮忙，现在又要放弃，烦不烦？\n",ob);
		return 1;
	}
	tell_object(me,ob->query("name")+quest_fail_msg[random(sizeof(quest_fail_msg))]);
	command("slash "+me->query("id"));
	me->delete("shenlong_zhanglao/ob_job");
	me->delete("shenlong_zhanglao/done");
	if ( objectp(me->query_temp("shenlong_zhanglao/target_ob") ) )
	destruct(me->query_temp("shenlong_zhanglao/target_ob"));
	/*
	reward=-5000;
	preward=-1000;
	reward = REWARD_D->add_exp(me,reward);
	me->add("exp/shenlong_zhanglao",reward);
	preward = REWARD_D->add_pot(me,preward);
	tell_object(me,HIW"由于放弃任务，你被扣了经验" + chinese_number(-reward) + "点，潜能" + chinese_number(-preward) + "点！\n"NOR);
	me->add("pot/shenlong_zhanglao",preward);
	if(me->query("combat_exp") < 2000) 
	me->set("combat_exp", 2000);
	me->set("shenlong_zhanglao/last_job_status","fail");*/ //测试期不扣经验
	me->delete("shenlong_zhanglao/on_job");
	return 1; 
}
int give_reward(object me)
{
	string msg,qid;
	string maze_map,inside,dataname;
	object newmap,letter;
	int deactivity_rate;//antirobot
	int reward,preward,rreward;//exp奖励
	int sk,lvl;//胡家刀法的等级,奖励的等级（碎片1，地图8）
	int index; //超过250级别，每250级加50%奖励，即0-250 100%，251-500 150%,501-705 200%, 705+ 250%
	int cost_time;//完成任务所需时间
	if (!me->query("biography/jobs/shenlong_zhanglao"))
	me->set("biography/jobs/shenlong_zhanglao",time());//个人传记记录第一次完成任务时间ZINE
	//sk=me->query_skill("hujia-daofa",1);
	lvl=me->query_temp("shenlong_zhanglao/finish");
	index=me->query("shenlong_zhanglao/times")/250;
	if (index>=3) index=3; //最高不超过3
	if (wizardp(me)) tell_object(me,"your index is "+index+".\n");
	reward  = (int)me->query_skill("force",1);
	reward += (int)me->query_skill("dodge",1);
	reward += (int)me->query_skill("parry",1);
	reward += pow(me->query("combat_exp")/100.0,1.0/3)*10;
//奖励封顶，到经验400m左右不随经验上调奖励 by seagate@pkuxkx
	if ( reward>6000 )
		reward=6000;
	reward = 1000*lvl + reward + random(reward);
	reward = reward*2/3;//因为不用亲自战斗，奖励是胡一刀2/3
	if (lvl!=8) 
	reward = reward/2*lvl;
	else
	{
		reward += reward/2*index; 
		reward = reward+random(reward/10);//额外奖励	
	}
	preward = reward/2+random(reward)/2;
	rreward = (100+random(100))*lvl+75*index*lvl;
  //特殊周效果
	reward  = reward  * SPEWEEK_D->query_huyidao_bonus()/100;
	preward = preward * SPEWEEK_D->query_huyidao_bonus()/100;    
	rreward = rreward * SPEWEEK_D->query_huyidao_bonus()/100;
	reward = REWARD_D->add_exp(me,reward);
	log_file("user/new_job_test",sprintf("%s%d%s\n",me->query("id"),reward,"于"+ctime(time())+"at"+this_object()->query("job_id")));
	me->add("exp/shenlong_zhanglao",reward);
	preward = REWARD_D->add_pot(me,preward);
	me->add("pot/shenlong_zhanglao",preward);
	rreward = REWARD_D->add_rep(me,rreward);
	msg=me->query("name")+"在神龙长老任务中获得经验奖励"+reward+"，潜能奖励"+preward+"，声望奖励"+rreward+"。";
	
	if (lvl==8)
	{
		/*me->set_skill("hujia-daofa",sk+1);
		if (!random(30))
		{
		command("chat* praise "+me->query("id"));
		command("chat "+RANK_D->query_respect(me)+"如此辛苦帮我寻回藏宝图，我就将我祖传的胡家刀法传授一二！");
		}
		write(HIC"\n你的「胡家刀法」进步了！\n"NOR);*/
		me->set("shenlong_zhanglao/last_job_status","success");
		me->add("shenlong_zhanglao/times",1);
		me->add("jobs/completed/hushenlong_zhanglao", 1);        //任务平衡系统，统计所有任务完成的次数  by boost  2008.09.19
	}
	MONEY_D->pay_player(me, (10000+random(1000))*lvl);
	message_vision("$N给了$n一些钱财。\n",this_object(),me);
	command("say "+RANK_D->query_respect(me)+"辛苦了，这些是你的辛苦费。");
	command("kiss2 "+me->query("id"));
	me->delete_temp("shenlong_zhanglao");
	me->delete("shenlong_zhanglao/on_job");
	me->delete("shenlong_zhanglao/done");
	CHANNEL_D->do_channel(this_object(), "sys_misc", msg);
	tell_object(me,HBWHT+HIB"你的经验提高了" + chinese_number(reward) + "点，你的潜能提高了" + chinese_number(preward) + "点，你的江湖声望提高了" + chinese_number(rreward) + "点！\n"NOR);
  //加入任务统计系统 by icer
	if (me->query_temp("task_stat/shenlong_zhanglao/last_asked")!=me->query("shenlong_zhanglao/last_asked"))
	{
	me->set_temp("task_stat/shenlong_zhanglao/last_asked",me->query("shenlong_zhanglao/last_asked"));
	cost_time = time()-me->query("shenlong_zhanglao/last_asked");
	} 
	else cost_time = 0;	//一次提交多个map只计时一次
	COMBAT_D->add("task_stat/shenlong_zhanglao/complete_times",1);
	COMBAT_D->add("task_stat/shenlong_zhanglao/cost_time",cost_time);
	COMBAT_D->add("task_stat/shenlong_zhanglao/exp",reward);
	COMBAT_D->add("task_stat/shenlong_zhanglao/pot",preward);
	COMBAT_D->add("task_stat/shenlong_zhanglao/repute",rreward);
	COMBAT_D->add("task_stat/shenlong_zhanglao/expratio",to_float(reward)/me->query("combat_exp"));
	if (lvl==8)
	//COMBAT_D->add("task_stat/shenlong_zhanglao/skill",1);
	if ( (int)me->query("jobs/completed/hushenlong_zhanglao")%40==39 && lvl==8 )
	{
		letter=new("/d/changjiang/obj/letter");
		letter->set("owner",me->query("id"));
		letter->move(me);
		tell_object(me,this_object()->name()+"身上掉下了一封信，你赶忙捡了起来。\n");
	}
	return 1;
}
int ask_finish()
{
	object me=this_player();
	if(!me->query("shenlong_zhanglao/on_job")) 
	{
		command("say 我并没有给你任务啊，你是不是昨天没睡好，记错了？");
		return 1;
	}
	if (!me->query_temp("shenlong_zhanglao/finish"))
	{
		command("say 你连一个弟子都没教好，也好意思回来？");
		return 1;
	}
	if ( objectp(me->query_temp("shenlong_zhanglao/target_ob") ) )
	destruct(me->query_temp("shenlong_zhanglao/target_ob"));
	return give_reward(me);
}