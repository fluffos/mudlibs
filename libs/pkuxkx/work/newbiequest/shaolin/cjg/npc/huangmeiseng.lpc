// huangmeiseng.c 黄眉僧 拈花寺住持 天龙八部人物
// 这里借做藏经阁任务的发起人。

#include <ansi.h>
inherit NPC;

string ask_quest();
string ask_reward();
int go_reward();
void create()
{
	set_name("黄眉僧", ({ "huangmei seng", "huangmei", "seng" }) );
	set("title", HIY "拈花寺住持" NOR);
	set("gender", "男性" );
	set("age", 69);
	set("long", "大理拈花寺的住持，一向以拿人钱财替人消灾而著称。\n");
	set("attitude", "heroism");
	set("class", "bonze");

	set("str", 30);
	set("con", 30);
	set("int", 27);
	set("dex", 23);

	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 100);
	set("shen_type", 1);
	set("nianhua", 1);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 80);

	set("combat_exp", 2500000);

	set_skill("force", 250); 
	set_skill("cuff", 250);
	set_skill("staff", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("shaolin-shenfa", 250); 
	set_skill("jingang-quan", 250); 
	set_skill("jingang-chu", 250); 
	set_skill("hunyuan-yiqi", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff","jingang-quan");
	map_skill("parry", "jingang-chu");
	map_skill("staff", "jingang-chu");
	map_skill("dodge", "shaolin-shenfa");
	prepare_skill("cuff", "jingang-quan");

  set("inquiry", ([
    "拈花寺" : "自从我离开莆田少林寺以后，一直驻锡在拈花寺，一向以热与助人著称，保定帝也时常来我寺修禅。\n",
    "少林寺" : "最近心血来潮，北上少林寺拜见我佛，发现附近多了很多来历不明的武林人士似乎有什么图谋。\n",
    "武林人士" : "没到夜晚就有很多武林人士在藏经阁附近晃悠，最近少林寺武僧加派了很多人到藏经阁附近巡逻，戒备十分森严。\n",
    "藏经阁" : "有道是天下武功出少林，少林寺藏经阁收藏了千年以来从各地收集的武功秘籍，神兵宝甲等等，真令人向往啊。\n",
    "潜入藏经阁" : (:ask_quest:),
    "奖励" : (:ask_reward:),
    "兑奖" : (:go_reward:) ]));

	setup();

  carry_object("/d/shaolin/obj/cheng-cloth")->wear();
  carry_object("/clone/weapon/gangzhang")->wield();
}

#include "huangmei.h"
#include "../nature.h"

string ask_quest()
{
	object me=this_player(), *team, env=environment(),*inv;
	int lp, dlp, complex;
	
	team=me->query_team();

  if ( env->query("outdoors")=="shaolin/cjg" )
  	return "你已经在副本中了不能再领任务了。\n";

	if ( !arrayp( team ) || 
		   sizeof(team)<2 )
	{
		me->delete_temp("cjg");
    me->set_temp("cjg/teams", 1 );

    if ( me->query_combatgrade() < 70 )
    	return "少林寺藏经阁太危险了，你还是再闯荡闯荡江湖吧。\n";
    
    if ( me->name() != "守寺僧兵" &&
    	   me->name() != CYN"护寺僧人"NOR )
    	return "你必须易容成守寺僧兵或者"CYN"护寺僧人"NOR"才能参与藏经阁任务。\n";
    
    if ( me->query("cjg/date") == c_date() &&
    	   me->query("cjg/number")>=2 )
    	return "你在今天已经参加过两次藏经阁任务。\n";
    	
  	inv=all_inventory(me);
  	for(dlp=0;dlp<sizeof(inv);dlp++)
  	{
  		if ( userp(inv[dlp]) )
  	 		return "背着人潜入藏经阁太危险了。\n";
  	}
    
    me->delete_temp("cjg/killer_point");
    complex=me->query_face_complex();
    if ( complex < 100+c_is_day()*100 )
   	  return "你的易容效果不足以参与藏经阁任务。【注意白天比晚上要求更高的易容效果】\n";
  
    if ( complex < 300+c_is_day()*100 )
  	  me->set_temp("cjg/disguise", 1);
    else
  	  me->set_temp("cjg/disguise", 1+(complex-100-c_is_day()*100)/200);
  
    tell_object(me, "只见黄眉僧偷偷说道，我知道一条小径通向藏经阁的偏僻处，进了藏经阁以后拿一本里面珍藏的佛经给我，必有重谢。\n");
    tell_object(me, "黄眉僧说道：藏经阁白天守卫森严，潜入以后危险重重，晚上就好多了，很多武林人士都是等到夜色降临才想办法潜入进去。\n");
    "/newbiequest/shaolin/cjg/zhulin3_config"->init_virtualMap();
    "/newbiequest/shaolin/cjg/zhulin4_config"->init_virtualMap();
    CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"开始过藏经阁任务，任务地图开始更新。已经在单人副本中的个人将会被传送到初始位置。");
    tell_object(me, "只见黄眉僧偷偷说道：凭借你的易容效果，只要被巡逻僧兵发现"+chinese_number(me->query_temp("cjg/disguise")+1)+"次以上就会被识破伪装。\n");
 	  if ( me->query("cjg/date") != c_date() )
  	{
  	  me->set("cjg/number", 1);
  	  me->set("cjg/date", c_date());
  	}
  	else
  	  me->add("cjg/number", 1);
  	
  	//开启藏经阁任务的困难模式
  	if ( me->query("env/adv_quest") )
  	  me->set_temp("cjg/hard", 1);
  	
  	me->set_temp("cjg/time", time());
  	me->set_temp("cjg/start", 1);
  	me->set_temp("pfm_skip", 1);
  	me->move("/newbiequest/shaolin/cjg/entry_s");
  }
  else
  {
  	me->delete_temp("cjg");
  	me->set_temp("cjg/teams", sizeof(team) );
  
    if ( sizeof(team)>=2 && 
  	     me != team[0] )
  	  return "只有领队才能领取藏经阁任务。\n";
  	
  	if ( sizeof(team) > 6 )
  		return "藏经阁副本最多支持6人队伍完成任务。\n";
  
    for ( lp=0; lp<sizeof(team); lp++)
    {
  	  if ( !objectp(team[lp]) ||
  		     environment(team[lp])!= environment() )
  		  return "要等人来齐了才能开始任务。\n";
    
      if ( team[lp]->query_combatgrade() < 70 )
    	  return "少林寺藏经阁太危险了，你们还是再闯荡闯荡江湖吧。\n";
    
      if ( team[lp]->name() != "守寺僧兵" &&
    	     team[lp]->name() != CYN"护寺僧人"NOR )
    	  return "所有组员必须易容成守寺僧兵或者"CYN"护寺僧人"NOR"才能参与藏经阁任务。\n";
    
      if ( team[lp]->query("cjg/date") == c_date() &&
    	     team[lp]->query("cjg/number")>=2 )
    	  return "组员中有人在今天已经参加过两次藏经阁任务，请调整队伍以后再参加任务。\n";
 
  	  inv=all_inventory(team[lp]);
  	  for(dlp=0;dlp<sizeof(inv);dlp++)
  	  {
  	  	if ( userp(inv[dlp]) )
  	  		return "背着人潜入藏经阁太危险了。\n";
  	  }
      
      if ( team[lp]==me )
        team[lp]->delete_temp("cjg/killer_point");
      else
      	team[lp]->delete_temp("cjg");
    } 
  
    complex=me->query_face_complex();
    if ( complex < 100+c_is_day()*100 )
   	  return "你的易容效果不足以参与藏经阁任务。【注意白天比晚上要求更高的易容效果】\n";
  
    if ( complex < 300+c_is_day()*100 )
  	  me->set_temp("cjg/disguise", 1);
    else
  	  me->set_temp("cjg/disguise", 1+(complex-100-c_is_day()*100)/200);
  
    tell_object(environment(), "只见黄眉僧偷偷说道，我知道一条小径通向藏经阁的偏僻处，进了藏经阁以后拿一本里面珍藏的佛经给我，必有重谢。\n");
    tell_object(environment(), "黄眉僧说道：藏经阁白天守卫森严，潜入以后危险重重，晚上就好多了，很多武林人士都是等到夜色降临才想办法潜入进去。\n");
    "/newbiequest/shaolin/cjg/zhulin1_config"->init_virtualMap();
    "/newbiequest/shaolin/cjg/zhulin2_config"->init_virtualMap();
    CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"小队开始过藏经阁任务，任务地图开始更新。已经在组队副本中的队伍将会被传送到初始位置。");
    tell_object(environment(), "只见黄眉僧偷偷说道：凭借你的易容效果，只要被巡逻僧兵发现"+chinese_number(me->query_temp("cjg/disguise")+1)+"次以上就会被识破伪装。\n");
    for ( lp=0; lp<sizeof(team); lp++)
    {
    	team[lp]->set_temp("cjg/teams", sizeof(team) );
  	  if ( team[lp]->query("cjg/date") != c_date() )
  	  {
  		  team[lp]->set("cjg/number", 1);
  	    team[lp]->set("cjg/date", c_date());
  	  }
  	  else
  		  team[lp]->add("cjg/number", 1);
  	
  	  team[lp]->set_temp("cjg/time", time());
  	  team[lp]->set_temp("cjg/start", 1);
  	  team[lp]->set_temp("pfm_skip", 1);
  	  team[lp]->move("/newbiequest/shaolin/cjg/entry");
    }
  }
  
  return "...";
}

void unconcious()
{
	::die();
}

string ask_reward()
{
	object me=this_player(), env=environment();
	int reward,teams, kp, lp, hard;
	object *team=me->query_team();
	
	me->delete_temp("pfm_skip");

	if ( env->query("short")!="藏经阁小院" ||
		   env->query("outdoors")!="shaolin/cjg" )
    return "黄眉僧理都没理你。";
  
  if ( !me->query_temp("cjg/start") )
  	return "黄眉僧理都没理你。";

  message_vision("$N偷偷从藏经阁中拿了一本佛经递给了$n，$n笑着说道好样的。\n", me, this_object());
  if (!me->query("biography/jobs/cjg"))
	{
		me->set("biography/jobs/cjg",time());//个人传记记录第一次完成任务时间ZINE
	}
	me->add("newjobs/completed/cjg",1);	
	hard=me->query_temp("cjg/hard");
  if ( me->query_temp("cjg/teams")<2 )
  {
    if ( hard )
      reward=80-(time()-me->query_temp("cjg/time")-480)/24;
    else
      reward=80-(time()-me->query_temp("cjg/time")-300)/18;
    
    if (reward<40)
  	  reward=40;
    else if (reward>120)
  	  reward=120;
  	
  	if ( me->query_temp("cjg/fights")>4 &&
  		   me->query_temp("cjg/fights")<=6 )
  		reward+=30*(me->query_temp("cjg/fights")-3);
  	else if ( me->query_temp("cjg/fights")>6 )
  		reward+=90;
  	
  	hard=me->query_temp("cjg/hard");
  	
  	if ( hard ) 
  	  me->add("cjg/point", 160+reward);
  	else
      me->add("cjg/point", 80+reward);
      
    log_file( "user/cjg", ctime(time())+":"+me->query("id")+"获得"+chinese_number(160+reward)+
    "藏经阁奖励积分，一共拥有"+chinese_number(me->query("cjg/point"))+"点积分。\n");
    message_vision(HIY"$n奖励给$N"HIY"固定任务积分八十点。\n", me, this_object());
    if ( hard )
      message_vision(HIY"$n奖励给$N"HIY"困难模式积分八十点。\n", me, this_object());
  }
  else
  {
  	if ( me->query_temp("cjg/teams")==me->query_temp("cjg/teams2") &&
  		   me->query_temp("cjg/teams")==me->query_temp("cjg/teams3") &&
  		   me->query_temp("cjg/teams") > 2)
  	  teams= me->query_temp("cjg/teams");
  	else
  		teams=2;
  	
  	if ( !team || 
  		   !arrayp(team) || 
  		   !objectp(team[0]) )
  	{
  		tell_object(me, "组队模式下藏经阁任务领取奖励的时候必须保持队伍存在。\n");
  		me->delete_temp("cjg");
  		return "又可以好好研究佛经了。";
  	}
  	
    reward=80+20*teams-(time()-me->query_temp("cjg/time")-360)/(18+teams);
    if (reward<(40+10*teams))
  	  reward=40+10*teams;
    else if (reward>(120+20*teams))
  	  reward=120+20*teams;
  	if ( teams>=3 && team[0]->query_temp("cjg/fights")>2 )
  		reward+=30*(teams-2);
  	
 	  if ( team[0]->query_temp("cjg/fights")>4 &&
 		     team[0]->query_temp("cjg/fights")<=6 )
 		  reward+=(10+6*teams)*(team[0]->query_temp("cjg/fights")-3);
 	  else if ( team[0]->query_temp("cjg/fights")>6 )
 		  reward+=(10+6*teams)*3;
 		
 		kp=me->query_temp("cjg/total_kp");
 		
 		if ( kp<40 || me->query_temp("cjg/killer_point")==0 ||
 			   (me->query_temp("cjg/killer_point")*100)/kp<=10 )
 		{
 	    if ( kp < 40 )
 	    {
 	      reward=reward-50-10*teams;
 	    	message_vision(HIY"由于$N"HIY"的队伍杀敌过少，扣除任务积分"+chinese_number(50+10*teams)+"点。\n", me);
 	    }
 	    else if ( me->query_temp("cjg/killer_point") < 10 )
 	    {
 	    	if ( me->query_temp("cjg/killer_point") <= 1 )
 	    	{
 	    		reward=(reward*50)/100-80-20*teams;
 	    		message_vision(HIY"由于$N"HIY"杀敌过少，扣除任务积分"+chinese_number(reward*50/100+80+20*teams)+"点。\n", me);
 	    	}
 	      else
 	      {
 	    	  reward=reward-80-20*teams;
 	    	  message_vision(HIY"由于$N"HIY"杀敌过少，扣除任务积分"+chinese_number(80+20*teams)+"点。\n", me);
 	    	}
 	    }
 	  }
  	
    me->add("cjg/point", 80+20*teams+reward);
    log_file( "user/cjg", ctime(time())+":"+me->query("id")+"获得"+chinese_number(80+20*teams+reward)+
    "藏经阁奖励积分，一共拥有"+chinese_number(me->query("cjg/point"))+"点积分。\n");
    message_vision(HIY"$n奖励给$N"HIY"固定任务积分"+chinese_number(80+20*teams)+"点。\n", me, this_object());
  }
  
  me->delete_temp("cjg");
  message_vision("$n奖励给$N"HIY"快速通关积分"+chinese_number(reward)+"点。\n", me, this_object());
  message_vision("$N目前拥有"+chinese_number(me->query("cjg/point"))+"点藏经阁任务积分。\n"NOR, me);
  return "又可以好好研究佛经了。";
}

int go_reward()
{
	object me=this_player();
	if ( me->query("cjg/point")>1000 )
	{
		message_vision("$n偷偷地将$N带到了藏经阁，$N可以随意兑奖了。\n", me, this_object());
		me->move("/newbiequest/shaolin/cjg/cjg1");
		return 1;
	}
	else
	{
		message_vision("$n理都不理$N。\n", me, this_object());
		return 1;
	}
}