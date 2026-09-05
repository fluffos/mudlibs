//胡一刀的盗宝人任务核心判断函数文件
//fix by yhzzyahoo @15.7.23再加强一些宝石奖励@15.8.3
int start_random();
int start_still();
int start_maze();

mapping quest_list=
(["random":
	(["desc" : "盗宝人『随机』",
	  "start": (: start_random :),
		"reward":100,
		"weight":100 ]),
  "still":
	(["desc" : "盗宝人『静止』",
	  "start": (: start_still :),
		"reward":90,
		"weight":5 ]),
	"maze":
	(["desc" : "盗宝人『迷宫』",
	  "start": (: start_maze :),
		"reward":120,
		"weight":25,
		"grade":60 ]) ]);

int start_random()
{
	object killer; //杀手
	object where; //出现的地点
	object me=this_player();
	object ob=this_object();
	int i;
	
  killer=new(__DIR__"killer1");
  killer->do_copy(me);
//过滤非法任务地点和不明区域 by segate@pkuxkx
  where = TASK_D->random_place();
  while (!objectp(where) || 
         !where->isroom()||
         TASK_D->place_belong(where)=="不明区域"||
         TASK_D->place_belong(where)=="未知区域"||
         base_name(where) == "/adm/daemons/taskd")
  {
     where = TASK_D->random_place();
  }
  
  killer->move(where);

  for (i=0;i<3;i++)
		killer->random_move();
   
	if (!killer)	//killer在移动期间晕倒或被房间call die了
	{
		message_vision("$N对$n说道：『我这里暂时没有什么任务需要你帮忙的』\n",ob,me);
		return 1;
	}
	
	me->set_temp("yidao/where",TASK_D->place_belong(where));
  me->set_temp("yidao/killer",killer->query("name"));
  me->set_temp("yidao/target_ob",killer); //加一个判断   
  me->set_temp("yidao/target_id",killer->query("id"));
  message_vision("$N说道：『我收到消息，听说"+TASK_D->place_belong(where)
               +"有盗宝人"+killer->query("name")+"("+killer->query("id")
               +")找到了闯王宝藏的地图,$n可否帮忙找回来！』\n",ob,me);
  command("care");
   
	return 0;
}

int start_still()
{
	object killer; //杀手
	object where; //出现的地点
	object me=this_player();
	object ob=this_object();
	
  killer=new(__DIR__"killer6");
  killer->do_copy(me);
//过滤非法任务地点和不明区域 by segate@pkuxkx
  where = TASK_D->random_place();
  while (!objectp(where) || 
         !where->isroom()||
         TASK_D->place_belong(where)=="不明区域"||
         TASK_D->place_belong(where)=="未知区域"||
         base_name(where) == "/adm/daemons/taskd")
  {
     where = TASK_D->random_place();
  }
  
  killer->move(where);
  killer->set("hide",1);
  killer->set("hyd/step",1);
   
	if (!killer)	//killer在移动期间晕倒或被房间call die了
	{
		message_vision("$N对$n说道：『我这里暂时没有什么任务需要你帮忙的』\n",ob,me);
		return 1;
	}
	
	me->set_temp("yidao/where",TASK_D->place_belong(where));
  me->set_temp("yidao/killer",killer->query("name"));
  me->set_temp("yidao/target_ob",killer); //加一个判断   
  me->set_temp("yidao/target_id",killer->query("id"));
//  me->set("uni_target",killer);
  if (wizardp(me))
  	tell_object(me, "盗宝人"+killer->query("name")+"("+killer->query("id")
               +")在"+TASK_D->place_belong(where)+"的"+where->query("short") );
  ANTIROBOT_D->mxpantirobot_ex(me,killer->query("name")+"在"+TASK_D->place_belong(where)+"的"+COLOR_D->uncolor(where->query("short")));
  command("care");

	return 0;
}

int start_maze()
{
	object suicong; //杀手
	object where; //出现的地点
	object me=this_player();
	object ob=this_object();
	
  suicong=new(__DIR__"suicong");
//过滤非法任务地点和不明区域 by segate@pkuxkx
  where = TASK_D->random_place();
  while (!objectp(where) || 
         !where->isroom()||
         TASK_D->place_belong(where)=="不明区域"||
         TASK_D->place_belong(where)=="未知区域"||
         base_name(where) == "/adm/daemons/taskd")
  {
     where = TASK_D->random_place();
  }
  
  suicong->move(where);
  suicong->set("hide",1);
  suicong->set("quester", me->query("id"));
  suicong->set("where", base_name(where));
   
	if (!suicong)	//killer在移动期间晕倒或被房间call die了
	{
		message_vision("$N对$n说道：『我这里暂时没有什么任务需要你帮忙的』\n",ob,me);
		return 1;
	}
	
	me->set_temp("yidao/where",TASK_D->place_belong(where));
	me->set_temp("yidao/suicong",suicong->name());
	me->set_temp("yidao/from", base_name(where));
  if (wizardp(me))
  	tell_object(me, "家丁"+suicong->name()+"在"+TASK_D->place_belong(where)+"的"+where->query("short")+"获得了关于藏宝图的消息。" );
  ANTIROBOT_D->mxpantirobot_ex(me,"找在"+TASK_D->place_belong(where)+"的"+COLOR_D->uncolor(where->query("short"))+"的"+suicong->query("name")+"。");
  tell_object(me,"获得关于盗宝人的消息。\n");
  command("care");

	return 0;
}

//任务分配函数，随机从quest_list中分配函数，同样类型任务连续失败次数越多抽中几率越大
int distribute_quest(string questid)
{
	string qid, *qkys;
	int weight, *wgts, grade, lp, randQ;
	object me=this_player(), ob=this_object();
	
  wgts=allocate(sizeof(keys(quest_list)));
	qkys=allocate(sizeof(keys(quest_list)));
	grade=me->query_combatgrade();
	lp=0;
	weight=0;

//重新领任务的，重新分配的还是同样类型的任务	
	if ( stringp(questid) &&
		   quest_list[questid] )
    return evaluate(quest_list[questid]["start"]);//返回值0表示成功，1表示失败
	
	foreach(qid in keys(quest_list))
	{
		if ( !quest_list[qid]["grade"]||
			   (intp(quest_list[qid]["grade"])&&   //当存在经验限制选项的时候，经验限制被激活
			    grade>=quest_list[qid]["grade"]) )
		{
			qkys[lp]=qid;
			wgts[lp]=quest_list[qid]["weight"]*(100+me->query("yidao/fail/"+qid)*10)/100;
			weight=weight+wgts[lp];
			lp++;
		}
	}
	
	if(!lp)
	{
		message_vision("$N皱眉道：目前没有任务可以分配给你。\n",ob);
		return 1;
	}
	
	randQ=random(weight);
	for(lp=0;lp<sizeof(wgts);lp++) 
	{
		if(randQ<wgts[lp]) {
			qid=qkys[lp];
			break;
		}
		else
			randQ=randQ-wgts[lp];
	}
	
	me->set("yidao/questid", qid);	
	return evaluate(quest_list[qid]["start"]);//返回值0表示成功，1表示失败
}

//任务失败的时候取消，并且对于该类型任务id的连续失败次数增加1次
int ask_cancel()
{
	int reward,preward;
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
  if ( objectp(me->query_temp("yidao/target_ob") ) )
  	destruct(me->query_temp("yidao/target_ob"));
 
  if ( stringp(me->query("yidao/questid")) )
    me->add("yidao/fail/"+me->query("yidao/questid"),1);
  reward=-5000;
  preward=-1000;
  reward = REWARD_D->add_exp(me,reward);
  me->add("exp/yidao",reward);
  preward = REWARD_D->add_pot(me,preward);
  tell_object(me,HIW"由于放弃任务，你被扣了经验" + chinese_number(-reward) + "点，潜能" + chinese_number(-preward) + "点！\n"NOR);
  me->add("pot/yidao",preward);
   
  if(me->query("combat_exp") < 2000) 
  	me->set("combat_exp", 2000);
  me->delete("yidao/on_job");
  return 1; 
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	int mylvl,i;

	mylvl = ((int)me->query("yidao/times")-250)/70;

	if (mylvl<=0) mylvl=0;
	if (mylvl>=5) mylvl=5;

  if ((int)me->query("yidao/times")>1600)
  {
    mylvl=mylvl-((int)me->query("yidao/times")-1600)/500;
    if (mylvl<=0) mylvl=0;
  }

  if (me->query_temp("yidaonotrobot")>0) 
  	mylvl=5;

  if(ANTIROBOT_D->stopped())
  {
    mylvl = ((int)me->query("yidao/times")-250)/70;
	  if (mylvl<=0) mylvl=0;
	  if (mylvl>=5) mylvl=5;
  }
	
	mylvl=mylvl*60;
	
	if(!userp(me))
    return 0;
  
  if( (int)me->query("yidao/last_asked") + MAX_WAIT_TIME - mylvl>= time()&&(int)me->query("yidao/last_asked")<time())
  {
    message_vision("$N说道：你刚刚不是要过任务么，你先下去休息吧!\n",ob);
    return 1;
  }
  if ( me->query("yidao/on_job")==1)
  {
    message_vision("$N皱眉道：上次的任务你还没有完成任务呢!\n",ob);
    return 1;
  }
  
  if ( me->query_combatgrade() < 40)
  {
    message_vision("$N笑道：这件事可没你想的那么简单，你好好练功吧!\n",ob);
    return 1;
  }
  
	if (me->query("antirobot/deactivity") > 2) 
		message("vision",HIR"胡一刀瞄了你一眼说：“怎么又是你！我看你是机器人吧。”\n"NOR,me);

//分配任务，如果分配失败直接返回
  if ( distribute_quest("") )
   	return 1;
				
  me->set("yidao/last_asked",time());
  me->set("yidao/on_job",1);
  me->delete_temp("yidao/done");
  me->add_temp("yidaonotrobot",-1);
  
  return 1;   
}

int ask_help()
{
  object me=this_player();
	object ob=this_object();
	object old_killer,killer; //杀手
	object where; //出现的地点
	int i;
  
  if(ANTIROBOT_D->stopped())
  {
    message_vision("$N道：我有点头晕，你迟点再来吧。\n",ob);
    return 1;
  }
  
  if ( me->query("yidao/on_job")==0)
  {
    message_vision("$N皱眉道：你又没有要任务，帮助你什么？\n",ob);
    return 1;
  }
  
  if ( me->query("yidao/done") >= 1 )
  {
    message_vision("$N皱眉道：你已经开始任务了，要啥帮助啊？\n",ob);
    return 1;
  }
  
  if (present("cangbao tu",me)||present("map piece1",me)||present("map piece2",me)||present("map piece3",me)||present("map piece4",me)||present("map piece5",me))
  {
    message_vision("$N皱眉道：你身上有宝图，不交给我，想打什么鬼主意？\n",ob);
    return 1;
  }
  
  if (me->query("huyidaoaskhelp"))
  {
    message_vision("$N皱眉道：你怎么又来了？我不是帮助过你一次，你都没有找到宝藏的线索！\n",ob);
    return 1;
  }
  
  me->delete("yidao/ob_job");
  me->delete("yidao/done");
  me->delete("yidao/on_job");
	
	if(!userp(me))
    return 0;

  if ( me->query_combatgrade() < 40)
	{
    message_vision("$N笑道：这件事可没你想的那么简单，你好好练功吧!\n",ob);
    return 1;
  }

  if ( me->query_temp("yidao/target_id") )
  {
    old_killer=find_living(me->query_temp("yidao/target_id"));
    if (old_killer&&old_killer->query("killer")==me->query("id"))
    {
      destruct(old_killer);
    }
  }

	if (me->query("antirobot/deactivity") > 2) 
		message("vision",HIR"胡一刀瞄了你一眼说：“怎么又是你！我看你是机器人吧。”\n"NOR,me);

//分配任务，如果分配失败直接返回
  if ( distribute_quest(me->query("yidao/questid")) )
   	return 1;
				
  me->set("yidao/last_asked",time());
  me->set("yidao/on_job",1);
  me->delete_temp("yidao/done");
  me->add_temp("yidaonotrobot",-1);
  me->set("huyidaoaskhelp",1);
 
  return 1;   
}

int give_reward(object me)
{
	string msg,qid;
	string maze_map,inside,dataname;
	object newmap,letter,xtshi,xiliandan,baoshi2;
	string *gems=({"gu","yu","jiao","jia"});
	object gem,material;

	int folds,nrn,id_mf;//
	int deactivity_rate;//antirobot
	int reward,preward,rreward;//exp奖励
	int sk,lvl;//胡家刀法的等级,奖励的等级（碎片1，地图8）
	int index, point, hard; //超过250级别，每250级加50%奖励，即0-250 100%，251-500 150%,501-705 200%, 705+ 250%
	int cost_time;//完成任务所需时间
	//加入reward_d管理后，antirobot由reward负责
//	if (me->query("antirobot/deactivity") < 4) deactivity_rate = 100;
// 	else deactivity_rate = 3200/me->query("antirobot/deactivity")/me->query("antirobot/deactivity")/me->query("antirobot/deactivity");
	if (!me->query("biography/jobs/huyidao"))
	{
		me->set("biography/jobs/huyidao",time());//个人传记记录第一次完成任务时间ZINE
	}
	sk=me->query_skill("hujia-daofa",1);
	lvl=me->query_temp("yidao/lvl");
	index=me->query("yidao/times")/250;
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
  
  if (lvl==1) 
  {
    reward = reward/2;
    if (reward>=3200) reward=3200+random(500); //修正分开给比一起给还多的bug,修正5001反而比4009给的少的情况，Zine 2010 Nov 11
  }
  
  if (lvl==8) 
  {      	
	  reward += reward/2*index; 
    reward = reward+random(reward/10);//额外奖励	
  }
	
	preward = reward/2+random(reward)/2;
	rreward = (100+random(100))*lvl+75*index*lvl;
  //特殊周效果
  if(!ANTIROBOT_D->stopped())
  {
      reward = reward*2/3;
      preward = preward*2/3;
      rreward = rreward*2/3;
  }//加入后续任务后，胡一刀前5次奖励 折扣2/3 by Zine 2010 Nov 11
  
  if (SPECIAL_D("lucky")->active_level(me)>=2 && (me->query("age")>=18))
	reward = reward + reward/10; //有lucky 2的玩家奖励多10%

  qid=me->query("yidao/questid");
  if ( quest_list[qid]["weight"] )
  {
    reward  = reward  * SPEWEEK_D->query_huyidao_bonus()/100 * quest_list[qid]["reward"]/100;
    preward = preward * SPEWEEK_D->query_huyidao_bonus()/100 * quest_list[qid]["reward"]/100;    
    rreward = rreward * SPEWEEK_D->query_huyidao_bonus()/100 * quest_list[qid]["reward"]/100;
  }
  else 
  {
    reward  = reward  * SPEWEEK_D->query_huyidao_bonus()/100;
    preward = preward * SPEWEEK_D->query_huyidao_bonus()/100;    
    rreward = rreward * SPEWEEK_D->query_huyidao_bonus()/100;
  }
  
  //机器人参数影响
//  reward  = reward  * deactivity_rate/100;
//  preward = preward * deactivity_rate/100;    
//  rreward = rreward * deactivity_rate/100;
  if (me->query_temp("extrajob/hyd"))
  {
    me->delete_temp("extrajob/hyd");
    reward=reward*2;
    preward=preward*2;
    rreward=rreward*2;
  }
	folds=this_object()->MyProBonus(me);
	reward*=folds;
	preward*=folds;
	rreward*=folds;
	if ( ( hard = me->query("yidao/hard")) &&
	     me->query("antirobot/deactivity")<4 )
	{
	  tell_object(me, sprintf("%d\n", hard));
	  point=hard*4+random(2+hard*4);
	  reward=reward*(100+5*hard )/100;
	  preward=preward*(100+20*hard )/100;
	  me->add("cjg/point", point );
	  me->delete("yidao/hard");
	  msg=me->query("name")+"在胡一刀任务中获得经验奖励"+reward+"，潜能奖励"+preward+"，声望奖励"+rreward+"，任务积分"+point+"。";
	}
	else
	{
	  msg=me->query("name")+"在胡一刀任务中获得经验奖励"+reward+"，潜能奖励"+preward+"，声望奖励"+rreward+"。";
	  hard=0;
	}
	reward = REWARD_D->add_exp(me,reward);
	me->add("exp/yidao",reward);
	preward = REWARD_D->add_pot(me,preward);
	me->add("pot/yidao",preward);
	rreward = REWARD_D->add_rep(me,rreward);
	
	if (lvl==8)
	{
     if(!ANTIROBOT_D->stopped())
     {
       newmap=new(__DIR__"obj/newmap");
       command("say "+RANK_D->query_respect(me)+"我把参详出的东西绘成了一幅新图，希望你能找到宝藏，恢复我汉室江山。");
       tell_object(me,"胡一刀把一张注释过的藏宝图递给了你。\n");
       newmap->set("owner",me->query("id"));
       newmap->move(me);
       me->add_temp("hyd_addi_give",1);
     }
		
 		 me->set_skill("hujia-daofa",sk+1);
		 if (!random(30))
		 {
       CHANNEL_D->do_channel(this_object(), "bd", "praise "+me->query("id"), 1);
       CHANNEL_D->do_channel(this_object(), "bd", RANK_D->query_respect(me)+"如此辛苦帮我寻回藏宝图，我就将我祖传的胡家刀法传授一二！");
     }
     
     write(HIC"\n你的「胡家刀法」进步了！\n"NOR);
		 if (index>=1)
		 { 
// 提高任务奖励。by lordstar 20171016
		   me->add("balance",150000+random(50000));
		   command("say "+RANK_D->query_respect(me)+"辛苦了，这里有些辛苦费已经转入你的帐户。");
		 }
	   
	   me->add("yidao/times",1);
     me->add("jobs/completed/huyidao", 1);        //任务平衡系统，统计所有任务完成的次数  by boost  2008.09.19
	}
	
	me->delete("yidao/fail/"+me->query("yidao/questid"));
	command("thank "+me->query("id"));
	me->delete_temp("yidao/lvl");
	me->delete("yidao/on_job");
	me->delete("yidao/done");
  CHANNEL_D->do_channel(this_object(), "sys_misc", msg);
  if ( hard )
    tell_object(me,HIY"你的经验提高了" + chinese_number(reward) + "点，你的潜能提高了" + chinese_number(preward) + "点，你的江湖声望提高了" + chinese_number(rreward) + "点，你获得了"+chinese_number(point)+"点任务积分！\n"NOR);
  else 
    tell_object(me,HIY"你的经验提高了" + chinese_number(reward) + "点，你的潜能提高了" + chinese_number(preward) + "点，你的江湖声望提高了" + chinese_number(rreward) + "点！\n"NOR);
  //加入任务统计系统 by icer
  if (me->query_temp("task_stat/yidao/last_asked")!=me->query("yidao/last_asked"))
  {
  	me->set_temp("task_stat/yidao/last_asked",me->query("yidao/last_asked"));
   	cost_time = time()-me->query("yidao/last_asked");
  } 
  else cost_time = 0;	//一次提交多个map只计时一次
  COMBAT_D->add("task_stat/yidao/complete_times",1);
  COMBAT_D->add("task_stat/yidao/cost_time",cost_time);
  COMBAT_D->add("task_stat/yidao/exp",reward);
  COMBAT_D->add("task_stat/yidao/pot",preward);
  COMBAT_D->add("task_stat/yidao/repute",rreward);
  COMBAT_D->add("task_stat/yidao/expratio",to_float(reward)/me->query("combat_exp"));
  
  if (lvl==8)
	{
  	COMBAT_D->add("task_stat/yidao/skill",1);
    	
	  if ( (int)me->query("jobs/completed/huyidao")%40==39 && lvl==8 )
	  {
		letter=new("/d/changjiang/obj/letter");
		letter->set("owner",me->query("id"));
		letter->move(me);
		tell_object(me,this_object()->name()+"身上掉下了一封信，你赶忙捡了起来。\n");
	  }
	  if (random(10000)>9950)
	  {
		xtshi= new("/obj/m_weapon/item/xuantie");
		xtshi->move(me);
		CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成胡一刀任务，获得千年玄铁一枚。");
	  }
	  if (random(10000)>9995)
	  {
		xiliandan= new("/d/changjiang/obj/special-ob.lpc");
		xiliandan->move(me);
		CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成胡一刀任务，获得特质洗炼丹一颗。");
	  }
	  nrn=random(10000);
	  if (nrn>9960)
	  {
		if (nrn>9998)
			{
				baoshi2= new("obj/taozhuang/xiaobao/boots");
				baoshi2->set("forge/max",1);
			}
		else if (nrn>9992) 
			{
				baoshi2= new("obj/taozhuang/xiaobao/boots");
			}
		else if (nrn>9985) 
			{
				baoshi2= new("obj/taozhuang/xiaobao/cloth");
				baoshi2->set("forge/max",1);
			}
		else if (nrn>9978) 
			{
				baoshi2= new("obj/taozhuang/xiaobao/dagger");
				baoshi2->set("forge/max",1);
			}
		else if (nrn>9970) baoshi2= new("obj/taozhuang/xiaobao/cloth");
		else if (nrn>9960) baoshi2= new("obj/taozhuang/xiaobao/dagger");
		baoshi2->move(me);
		CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成胡一刀任务，获得"+baoshi2->query("name")+"一件。");

	  }
		id_mf=(int)me->query_temp("apply/magic");
		if (id_mf>1600)
		{
			nrn=1;
		}
		else
		{
			nrn=2;
		}
		id_mf=(int)id_mf/5;
		if (random(nrn)==0)
		{
			gem=new("/obj/gem/gem");
// 提高任务奖励。by lordstar 20171016
			id_mf += 8000;
			nrn = id_mf + random(2000);
			if (nrn>10000) nrn=10000;
			gem->set_level(id_mf,nrn,gems[random(sizeof(gems))]);
			gem->move(me);
			write("\n胡一刀给你一颗"+gem->name()+"作为额外奖励！\n");  
		}
		
//增加无常造化丹药材掉落。by lordstar 20171102
		if (random(10000)>9970 && !me->query("hsz_auto"))
		{
			material=new("/obj/remedy/drug/wuchang-material");
			if (objectp(material))
			{
				material->set("owner", me->query("id"));
				material->move(me);
				tell_object(me, "胡一刀又送你一份罕见的珍贵药材作为额外馈赠。\n");
			}
		}

  }
	return 1;
}