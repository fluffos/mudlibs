// huyidao.c
// by whuan@pkuxkx
#define MAX_WAIT_TIME 600
#include <ansi.h>;
inherit NPC;
int ask_job();
int ask_cancel();
int ask_times();
int ask_pfm();
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
	set_name("胡一刀", ({"hu yidao", "yidao", "hu"}));
	set("gender", "男性");
	set("title", HIR"辽东"HIY"大侠"NOR);
	set("age", 35);
        set("uni_target",1);
        set("uni_target", "whuan");
	set("long","这人生得当真凶恶，一张黑漆脸皮，满腮浓髯，头发却又不结辫子，蓬蓬松松的堆在头上。\n他生平只要遇到做坏事的，立时一刀杀了，所以名字叫作胡一刀。\n");
        set("attitude", "friendly");
  set("no_get", "1");
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
	 
	set_skill("force", 500);             // 基本内功
	set_skill("hujia-daofa", 550);       // 胡家刀法	
	set_skill("blade", 520);             // 基本刀法
	set_skill("hunyuan-yiqi", 520);      // 混元一气功
	set_skill("dodge", 520);             // 基本躲闪
	set_skill("shaolin-shenfa", 520);    // 胡家身法
	set_skill("parry", 520);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	set("inquiry",([
		"job":     (: ask_job :),
		"盗宝人":  (: ask_job :),
		"取消":    (: ask_cancel :),
		"cancel":  (: ask_cancel :),
		"次数":    (: ask_times :),
		"times":   (: ask_times :),
		"绝招" :   (: ask_pfm :),
	   ]));
	set("shen_type",1);set("score",50000);setup();
  carry_object("/d/city/npc/obj/gangdao")->wield();
  carry_object("/d/city/obj/cloth")->wear();
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	object killer; //杀手
	object where; //出现的地点
	int mylvl,i;
	mylvl = ((int)me->query("yidao/times")-250)/70;
	if (mylvl<=0) mylvl=0;
	if (mylvl>=5) mylvl=5;
	mylvl=mylvl*60;
	if(!userp(me))
        return 0;
  if( (int)me->query("yidao/last_asked") + MAX_WAIT_TIME - mylvl>= time() )
    {
    message_vision("$N说道：你刚刚不是要过任务么，你先下去休息吧!\n",ob);
    return 1;
    }
  if ( me->query("yidao/on_job")==1)
  	{
    message_vision("$N皱眉道：上次的任务你还没有完成任务呢!\n",ob);
    return 1;
    }
  if ( me->query("combat_exp")<=3000000)
  	{
    message_vision("$N笑道：这件事可没你想的那么简单，你好好练功吧!\n",ob);
    return 1;
    }
   killer=new(__DIR__"killer1");
   killer->do_copy(me);
   where = TASK_D->random_place();
   killer->move(where);
   for (i=0;i<3;i++)
		if (killer)  killer->random_move();
	if (!killer)	//killer在移动期间晕倒或被房间call die了
	{
		message_vision("$N对$n说道：『我这里暂时没有什么任务需要你帮忙的』\n",ob,me);
		return 1;
	}
	if (me->query("antirobot/deactivity") > 2) message("vision",HIR"胡一刀瞄了你一眼说：“怎么又是你！我看你是机器人吧。”\n"NOR,me);
				
   me->set("yidao/last_asked",time());
   me->set("yidao/on_job",1);
   me->delete_temp("yidao/done");
   me->set_temp("yidao/where",TASK_D->place_belong(where));

   me->set_temp("yidao/killer",killer->query("name"));
   me->set_temp("yidao/target_ob",killer); //加一个判断   
message_vision("$N说道：『我收到消息，听说"+TASK_D->place_belong(where)
               +"有盗宝人"+killer->query("name")+"("+killer->query("id")
               +")找到了闯王宝藏的地图,$n可否帮忙找回来！』\n",ob,me);
   command("care");
   return 1;   
}

int ask_cancel()
{
	object me=this_player();
	object ob=this_object();
  if ( me->query("yidao/on_job")==0)
  	{
    message_vision("$N皱眉道：你又没有要任务，取消什么？\n",ob);
    return 1;
    }
  if( (int)me->query("yidao/last_asked") + 300 >= time() )
    {
    message_vision("$N说道：你再去找找看啊，不要轻言放弃！\n",ob);
    return 1;
    }
   tell_object(me,ob->query("name")+quest_fail_msg[random(sizeof(quest_fail_msg))]);
   command("disapp1");
   me->delete("yidao/ob_job");
   me->delete("yidao/done");
   me->add("combat_exp",-5000);
   me->add("potential",-1000);
   if(me->query("combat_exp") < 2000) me->set("combat_exp", 2000);
   me->delete("yidao/on_job");
   return 1; 
}

int ask_times()
{
	command("say 到目前为止，你共完成了"+this_player()->query("yidao/times")+"次任务！");
	return 1;
}

int accept_object(object who, object ob)
{
	//修正一次性给无数藏宝图的bug，piece是允许的
	if(!who->query("yidao/on_job") && ob->query("id")=="cangbao tu") 
		{
		command("say 我并没有给你任务啊，你无缘无故给我东西干什么？");
		return 0;
	  }
	
	if(who->query("yidao/done") != 5 && ob->query("id")=="cangbao tu") 
		{
		command("say 你这张图是什么时候的呀，还敢来骗我？");
		return 0;
	  }
	  
	if(ob->query("id")=="cangbao tu" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",8);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece1" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece2" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece3" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece4" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece5" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
		return 0;					
}

int give_reward(object me)
{
	string msg;
	int deactivity_rate;//antirobot
	int reward,preward,rreward;//exp奖励
	int sk,lvl;//胡家刀法的等级,奖励的等级（碎片1，地图8）
	int index; //超过250级别，每250级加50%奖励，即0-250 100%，251-500 150%,501-705 200%, 705+ 250%
	int cost_time;//完成任务所需时间
	//加入reward_d管理后，antirobot由reward负责
//	if (me->query("antirobot/deactivity") < 4) deactivity_rate = 100;
// 	else deactivity_rate = 3200/me->query("antirobot/deactivity")/me->query("antirobot/deactivity")/me->query("antirobot/deactivity");
	sk=me->query_skill("hujia-daofa",1);
	lvl=me->query_temp("yidao/lvl");
	index=me->query("yidao/times")/250;
	if (index>=3) index=3; //最高不超过3
	if (wizardp(me)) tell_object(me,"your index is "+index+".\n");
	reward  = (int)me->query_skill("force",1);
	reward += (int)me->query_skill("dodge",1);
	reward += (int)me->query_skill("parry",1);
	reward += pow(me->query("combat_exp")/100.0,1.0/3)*10;
	reward = 1000*lvl + reward + random(reward);
  if (lvl==1) 
     {
     reward = reward/2;
     if (reward>=5000) reward=3500+random(1888); //修正分开给比一起给还多的bug
     }
  if (lvl==8) 
  	{      	
	  reward += reward/2*index; //额外奖励	
    }
	preward = reward/2+random(reward)/2;
	rreward = (100+random(100))*lvl+75*index*lvl;
  //特殊周效果
  reward  = reward  * SPEWEEK_D->query_huyidao_bonus()/100;
  preward = preward * SPEWEEK_D->query_huyidao_bonus()/100;    
  rreward = rreward * SPEWEEK_D->query_huyidao_bonus()/100;
  //机器人参数影响
//  reward  = reward  * deactivity_rate/100;
//  preward = preward * deactivity_rate/100;    
//  rreward = rreward * deactivity_rate/100;
	reward = REWARD_D->add_exp(me,reward);
	me->add("exp/yidao",reward);
	preward = REWARD_D->add_pot(me,preward);
	me->add("pot/yidao",preward);
	rreward = REWARD_D->add_rep(me,rreward);
	msg=me->query("name")+"在胡一刀任务中获得经验奖励"+reward+"，潜能奖励"+preward+"，声望奖励"+rreward+"。";
	if (lvl==8)
		{
			me->set_skill("hujia-daofa",sk+1);
			if (!random(5))
				{command("chat* praise "+me->query("id"));
         command("chat "+RANK_D->query_respect(me)+"如此辛苦帮我寻回藏宝图，我就将我祖传的胡家刀法传授一二！");
        }
      write(HIC"\n你的「胡家刀法」进步了！\n"NOR);
			if (index>=1)
			{ 
				me->add("balance",80000+random(30000));
			  command("say "+RANK_D->query_respect(me)+"辛苦了，这里有些辛苦费已经转入你的帐户。");
			}
			me->add("yidao/times",1);
                       me->add("jobs/completed/huyidao", 1);        //任务平衡系统，统计所有任务完成的次数  by boost  2008.09.19
		}
	command("thank "+me->query("id"));
	me->delete_temp("yidao/lvl");
	me->delete("yidao/on_job");
	me->delete("yidao/done");
  CHANNEL_D->do_channel(this_object(), "sys", msg);
        tell_object(me,HIY"你的经验提高了" + chinese_number(reward) + "点，你的潜能提高了" + chinese_number(preward) + "点，你的江湖声望提高了" + chinese_number(rreward) + "点！\n"NOR);
    //加入任务统计系统 by icer
    if (me->query_temp("task_stat/yidao/last_asked")!=me->query("yidao/last_asked"))
    {
    	me->set_temp("task_stat/yidao/last_asked",me->query("yidao/last_asked"));
    	cost_time = time()-me->query("yidao/last_asked");
    } else cost_time = 0;	//一次提交多个map只计时一次
    COMBAT_D->add("task_stat/yidao/complete_times",1);
    COMBAT_D->add("task_stat/yidao/cost_time",cost_time);
    COMBAT_D->add("task_stat/yidao/exp",reward);
    COMBAT_D->add("task_stat/yidao/pot",preward);
    COMBAT_D->add("task_stat/yidao/repute",rreward);
    COMBAT_D->add("task_stat/yidao/expratio",to_float(reward)/me->query("combat_exp"));
    if (lvl==8)
    	COMBAT_D->add("task_stat/yidao/skill",1);
	return 1;
}
int ask_pfm()
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
void do_dest(object ob)
{
        if(!objectp(ob))
                return;
        destruct(ob);
}

