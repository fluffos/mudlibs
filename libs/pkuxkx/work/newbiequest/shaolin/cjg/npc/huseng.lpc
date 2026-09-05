
#include <ansi.h>
inherit NPC;
#include "monksk.h"
#include "../nature.h"

int ask_fight();
void do_copy(object );
object *team_copy(object *);
object *alert_seng(object );
void die();

void create()
{
	set_name(CYN"护寺僧人"NOR, ({"husi sengren", "sengren"}));
	set("gender", "男性" );
	set("attitude", "heroism");
	
  set("food",500);
  set("water",500);
  set("max_qi", 10000);
//  set("shen", 150000);
  set("class", "bonze");
//  set_temp("no_exert", 1);
  set("uni_target", this_object());
  
  set("inquiry", ([
    "fight" : (: ask_fight :) ]));
  
	setup();
}

void init()
{
	add_action("do_halt", "halt");
}

int ask_fight()
{ 
	object me, ob, *team, *eny;
	int lp, lpp;
  
  me=this_player();
  ob=this_object();
  if (is_fighting())
  	return notify_fail("等战斗结束以后再问吧。\n");
  
  if ( !wizardp(me) )
  	return notify_fail("只有巫师才能这么干。\n");
  
  team=me->query_team();
  if ( !arrayp( team ) || sizeof(team)<2 )
  {
    if ( objectp(ob->query("uni_target")) &&
    	   ob->query("uni_target")!=ob )
	    eny=alert_seng(me);
    else
    {
      do_copy(me);
      eny=alert_seng(me);
      eny+=({ob});
      me->kill_ob(this_object());
      kill_ob(me);
    }
  }
  else
  {
  	if (team[0]!=me)
  	{
  		printf("只有队伍的首领才有挑战的权利。\n");
  		return 1;
  	}
//组队的情况下复制和招呼npc计算
  	team_copy(team);
//    destruct(ob);
  }
  
  return 1;
}

void real_copy(object me, int exp, int bossflag, int teamflag)
{
	int hps, sklvl, lp, maxqi;
	string *wp_sks, *un_sks;
	int wp_wgt, un_wgt, level,hard;
	function *pfms;
	mapping wp_sk, un_sk;
	
	hard=me->query_temp("cjg/hard");
	 	
  if (bossflag)
  {
  	if ( hard )
  	  lp=500+random(500);
  	else
  	  lp=100+random(900);
  	
  	if (lp<=250)
  	{
  	  if ( hard )
  	    set_name(HIB"罗汉堂"HIR"长老"NOR, ({"husi zhanglao", "zhanglao"}));
  	  else
  		  set_name(HIB"罗汉堂长老"NOR, ({"husi zhanglao", "zhanglao"}));
  		set("chat_chance_combat", 10);
  		hps=250+c_is_day()*(60+random(60));
      set_temp("apply/damage",200+hps*2/3);
  	}
  	else if (lp<=500)
  	{
  	  if ( hard )
  	    set_name(HIG"般若堂"HIR"长老"NOR, ({"husi zhanglao", "zhanglao"}));
  	  else
  		  set_name(HIG"般若堂长老"NOR, ({"husi zhanglao", "zhanglao"}));
  		set("chat_chance_combat", 12+3*hard);
  		hps=300+c_is_day()*(80+random(80))+150*hard;
      set_temp("apply/damage",250+hps*2/3);
      if ( hard )
      {
        set_temp("apply/kf_def_wound", 15+random(15));
        set_temp("apply/week_injure", 15+random(15));
      }
  	}
  	else if (lp<=750)
  	{
  	  if ( hard )
  	    set_name(HIY"达摩院"HIR"长老"NOR, ({"husi zhanglao", "zhanglao"}));
  	  else
  		  set_name(HIY"达摩院长老"NOR, ({"husi zhanglao", "zhanglao"}));
  		set("chat_chance_combat", 14+4*hard);
  		hps=350+c_is_day()*(100+random(100))+180*hard;
      set_temp("apply/damage",300+hps*2/3);
      if ( hard )
      {
        set_temp("apply/kf_def_wound", 20+random(20));
        set_temp("apply/week_injure", 20+random(20));
      }
  	}
  	else
  	{
  	  if ( hard )
  	    set_name(HIM"藏经阁"HIR"长老"NOR, ({"husi zhanglao", "zhanglao"}));
  	  else
  		  set_name(HIM"藏经阁长老"NOR, ({"husi zhanglao", "zhanglao"}));
  		set("chat_chance_combat", 16+6*hard);
  		hps=400+c_is_day()*(120+random(120))+200*hard;
      set_temp("apply/damage",350+hps*2/3);
      if ( hard )
      {
        set_temp("apply/kf_def_wound", 25+random(25));
        set_temp("apply/week_injure", 25+random(25));
      }
  	}
	if ((hard==0)&&(random(30)==0))
	{
  		set("chat_chance_combat", 50);
  		hps=600+c_is_day()*(120+random(120));
		set_temp("apply/damage",350+hps*2/3);
		set_temp("apply/kf_def_wound", 25+random(10));
		set_temp("apply/week_injure", 25+random(10));
	}
    set("age", 60+random(40) );
    set("long", "这是一个常年在寺院里面苦修的老和尚，每到晚上都会在寺院里面重要场所巡视。\n");
    set_temp("apply/armor",1000);
    create_family("少林派", 36, "弟子");
    carry_object("/d/shaolin/obj/xuan-cloth")->wear();
  }
  else 
  {
    if ( hard )
      lp=500+random(500);
    else
  	  lp=100+random(900);
  	
  	if (lp<=500)
  	{
  	  if ( hard )
  	    set_name(HIB"罗汉堂"HIR"僧兵"NOR, ({"husi sengren", "sengren"}));
  	  else
        set_name(HIB"罗汉堂僧兵"NOR, ({"husi sengren", "sengren"}));
      set("chat_chance_combat", 5);
      hps=80+c_is_day()*(30+random(30));
	  if(random(30)==0)
		  hps+=50;
      set_temp("apply/damage",50+hps*2/3);
    }
    else if (lp<=700)
    {
  	  if ( hard )
  	    set_name(HIG"般若堂"HIR"僧兵"NOR, ({"husi sengren", "sengren"}));
  	  else
    	  set_name(HIG"般若堂僧兵"NOR, ({"husi sengren", "sengren"}));
    	set_temp("apply/armor_effect_poison", 5);
    	set("kar", 10+random(30) );
    	set_temp("apply/magic", 300+random(1000));
    	set("chat_chance_combat", 6+3*hard);
    	hps=100+c_is_day()*(40+random(40))+50*hard;
	  if(random(30)==0)
		  hps+=50;
      set_temp("apply/damage",100+hps*2/3);
      if ( hard )
      {
        set_temp("apply/kf_def_wound", 5+random(5));
        set_temp("apply/week_injure", 5+random(5));
      }

    }
    else if (lp<=900)
    {
  	  if ( hard )
  	    set_name(HIY"达摩院"HIR"僧兵"NOR, ({"husi sengren", "sengren"}));
  	  else
    	  set_name(HIY"达摩院僧兵"NOR, ({"husi sengren", "sengren"}));
    	set_temp("apply/armor_effect_armor_vs_force", 10+random(15));
    	set("kar", 10+random(30) );
    	set_temp("apply/magic", 1000+random(1000));
    	set("chat_chance_combat", 7+4*hard);
    	hps=120+c_is_day()*(50+random(50))+60*hard;
	  if(random(30)==0)
		  hps+=50;
	  set_temp("apply/damage",100+hps*2/3);
      if ( hard )
      {
        set_temp("apply/kf_def_wound", 7+random(7));
        set_temp("apply/week_injure", 7+random(7));
      }

    }
    else
    {
  	  if ( hard )
  	    set_name(HIM"藏经阁"HIR"僧兵"NOR, ({"husi sengren", "sengren"}));
  	  else
    	  set_name(HIM"藏经阁僧兵"NOR, ({"husi sengren", "sengren"}));
    	set_temp("apply/armor_effect_rebound", 10+random(15) );
    	set("kar", 10+random(30) );
    	set_temp("apply/magic", 1000+random(1000));
    	set("chat_chance_combat", 8+6*hard);
    	hps=150+c_is_day()*(60+random(60))+75*hard;
	  if(random(30)==0)
		  hps+=50;
      set_temp("apply/damage",100+hps*2/3);
      if ( hard )
      {
        set_temp("apply/kf_def_wound", 10+random(10));
        set_temp("apply/week_injure", 10+random(10));
      }

    }
    
    set("age", 40+random(20) );
    set("long", "这是一个中年和尚，锐利的目光不时扫视寺内各处防止宵小潜入寺内。\n");
    set_temp("apply/armor",1000);
    create_family("少林派", 37, "弟子");
    carry_object("/d/shaolin/obj/cheng-cloth")->wear();
  }
  
	sklvl=to_int(ceil(pow(to_float(exp)*10000000.0,0.33)));
	set("combat_exp", exp*1050000);

//减少由于经验增加导致的气血急剧增加的问题  
  if ( exp>=100 && exp<= 700 )
  	exp=100+(exp-100)/3;
  else if ( exp> 700 )
    exp=300+(exp-700)/8;
  
  if ( exp> 600 )
    exp=600;
  
  if ( exp< 50 )
  	exp=50;
	
	set("max_qi", exp*hps);
	set("eff_qi", exp*hps);
	set("qi", exp*hps);
	set("max_jing", exp*hps);
	set("eff_jing", exp*hps);
	set("jing", exp*hps);
	set("max_jingli", exp*hps);
	set("jingli", exp*hps);
	set("food", exp*hps);
	set("water", exp*hps);
	
	set_skill("force", sklvl);
	set_skill("buddhism", sklvl+300);
	set_skill("parry", sklvl);
	set_skill("dodge", sklvl);
	set_skill("shaolin-shenfa", sklvl);
	set_skill("hunyuan-yiqi", sklvl);
	
	if (bossflag)
	{
		if ( sklvl>1600 )
		{
		  set_skill("iron-cloth", 1600);
			set_skill("jingang-buhuai", 1600);
		}
		else
		{
		  set_skill("iron-cloth", sklvl);
		  set_skill("jingang-buhuai", sklvl);
		}
		set_skill("yijin-jing", sklvl);
		map_skill("iron-cloth", "jingang-buhuai");
		map_skill("force", "yijin-jing");
	  set("max_neili", sklvl*30);
	  if ( hard )
	    set("neili", sklvl*45);
	  else
	    set("neili", sklvl*30);
	}
	else
	{
		map_skill("force", "hunyuan-yiqi");
	  set("max_neili", sklvl*15);
	  if ( hard )
	    set("neili", sklvl*30);
	  else
	    set("neili", sklvl*15);
  }

	wp_sks=keys(weapon_sk);
	un_sks=keys(unarmed_sk);
	wp_wgt=0;
	un_wgt=0;
	pfms=({});
	if (bossflag)
		pfms+=({ (: exert_function, "powerup" :),
			       (: exert_function, "jingang" :) });
			       	
	for(lp=0;lp<sizeof(wp_sks);lp++)
	{
		if (bossflag)
			wp_wgt+=weapon_sk[wp_sks[lp]]["class"];
		else
			wp_wgt+=1000/weapon_sk[wp_sks[lp]]["class"];
	}

	for(lp=0;lp<sizeof(un_sks);lp++)
	{		
		if (bossflag)
			un_wgt+=unarmed_sk[un_sks[lp]]["class"];
		else
			un_wgt+=1000/unarmed_sk[un_sks[lp]]["class"];
	}
	
	wp_wgt=random(wp_wgt);
	un_wgt=random(un_wgt);
	
	for(lp=0;lp<sizeof(wp_sks);lp++)
	{
		if (bossflag)
			level=weapon_sk[wp_sks[lp]]["class"];
		else
			level=1000/weapon_sk[wp_sks[lp]]["class"];
		
		if (wp_wgt<level)
		{
			wp_sk=weapon_sk[wp_sks[lp]];
			break;
		}
		else
			wp_wgt-=level;
	}

	for(lp=0;lp<sizeof(un_sks);lp++)
	{
		if (bossflag)
			level=unarmed_sk[un_sks[lp]]["class"];
		else
			level=1000/unarmed_sk[un_sks[lp]]["class"];
		
		if (un_wgt<level)
		{
			un_sk=unarmed_sk[un_sks[lp]];
			break;
		}
		else
			un_wgt-=level;
	}
	
	set_skill(wp_sk["base"], sklvl);
  set_skill(wp_sk["special"], sklvl);
	set_skill(un_sk["base"], sklvl);
	set_skill(un_sk["special"], sklvl);
	map_skill("parry", un_sk["special"]);
	map_skill("dodge", "shaolin-shenfa");
	map_skill(wp_sk["base"], wp_sk["special"]);
	map_skill(un_sk["base"], un_sk["special"]);
	prepare_skill(un_sk["base"], un_sk["special"]);
	if (wp_sk["perform"])
		pfms+=wp_sk["perform"];
	if (un_sk["perform"])
		pfms+=un_sk["perform"];
	set("chat_msg_combat", pfms);
	carry_object(wp_sk["weapon"])->wield();
	set("attack_weapon", wp_sk["weapon"]);
	if (teamflag)
		delete("uni_target");
	else
	  set("uni_target", me);
}

//单个复制模式，经验直接和当前玩家相关
void do_copy(object me)
{
	int exp,bossflag,hard;
	
	if( !objectp(me) )
		return;
  
  hard=me->query_temp("cjg/hard");
  
  if (random(1000)>=950-c_is_day()*80)
  	bossflag=1;
  else
  	bossflag=0;
  
//取经验值，经验值限定在50m到500m之间
//困难模式下任务经验没有最大值限定
	exp=me->query("combat_exp")/1000000;
	if ( exp<20 ) 
		exp=20;
	else
		exp=exp+random(exp/5);
	
	if ( hard )
	  exp=exp*130/100;
	
	if ( exp>600 && !hard )
		exp=600;  
	
  real_copy(me, exp, bossflag, 0);
}

//战斗检查！如果没有战斗重新触发战斗
void killer_target(mixed ob)
{
	object me=this_object();
	int lp;
	
	if ( is_fighting() )
	{
		call_out("killer_target",4+random(3),ob);
		return;
	}
		
	if (objectp(ob) && userp(ob) && environment(me)==environment(ob) )
	{
		kill_ob(ob);
		ob->kill_ob(me);
	}
	else if ( arrayp(ob) && objectp(ob[0]))
	{
		for(lp=0;lp<sizeof(ob);lp++)
		{
			if ( objectp(ob[lp]) && 
				   environment(me)==environment(ob[lp]) )
			{
			  kill_ob(ob[lp]);
			  ob[lp]->kill_ob(me);
			}
		}
	}
	call_out("killer_target",2+random(3),ob);
}

//组队复制模式，经验为队伍人员的平均经验，如果队伍经验差距过于悬殊，则取最高经验玩家
object *team_copy(object *team)
{
	object env, ob, *eny;
	int lp, lpp, exp, sumexp, maxexp;
	int bossflag, hps, npcs, bos, teams, thps=0;
	
	env=environment(team[0]);
	sumexp=0;
	maxexp=0;
	if ( env->query("outdoors") != "shaolin/cjg" )
		return 0;
	
	teams=sizeof(team);
		
	for(lp=0;lp<teams;lp++)
	{
//取经验值，经验值限定在50m到500m之间
	  exp=team[lp]->query("combat_exp")/1000000;
	  if ( exp<20 ) 
		  exp=20;
	  else if ( exp>500 )
		  exp=500;
		
		if ( exp>maxexp )
			maxexp=exp;
		sumexp+=exp;
	}
	
	exp=(sumexp*120)/(teams*100);
	if ( exp < (maxexp*80)/100 )
		exp=maxexp;
	else if ( exp > 500 )
		exp=500;
  
  eny=({});

//当队伍组成小于等于5人时，怪物数量是2+队伍人数×3，否则为2+队伍人数×6
  if (teams<=4)
  {
  	if ( !team[0]->query_temp("cjg/fights") &&
  		   environment(team[0])->query("cjgmaze")=="level2" )
  	{
  		npcs=4+c_is_day();
  		bos=7-c_is_day()*(1+random(2));
  	}
  	else
  	{
  	  npcs=3+c_is_day();
  	  bos=8-c_is_day()*(1+random(2));
  	}
  }
  else
  {
  	npcs=4+c_is_day()*(1+random(2));
  	bos=6-c_is_day()*(1+random(2));
  }
  
  if ( teams>=4 )
  	thps=random(npcs*teams/4);
  if ( !team[0]->query_temp("cjg/fights") &&
  		 environment(team[0])->query("cjgmaze")=="level2" )
    thps+=3;
  thps+=3+(npcs+c_is_day()*random(2))*(random(2)+teams-1);

	for(lp=0;lp<thps;lp++)
	{
//当队伍组成小于等于5人时，boss为每8个怪物出一个boss，否则每4个怪物出一个boss。
		if ( !(lp%bos) )
			bossflag=1;
		else
			bossflag=0;
	  
	  ob=new("/newbiequest/shaolin/cjg/npc/huseng");
	  ob->move(env);
	  ob->real_copy(team[0], exp, bossflag, 1);
	  ob->set("fight_team", team[0]);
	  eny+=({ob});
	}

//组队情况下fight计算，先攻击随机一个队员，然后将所有队员加入攻击列表，使攻击平均分配
  call_out("team_fight",1, eny, team);
 
  return eny;
}

int team_fight(object *eny, object *team)
{
	int lp, lpp;
	int teams=sizeof(team);
	
  for( lp=0; lp<sizeof(eny); lp++)
  {
  	if ( !objectp(eny[lp]) )
  		continue;
  	
    while(1==1)
    {
      lpp=random(teams);
      if ( environment(team[lpp])==environment(team[0]) )
      {
        team[lpp]->kill_ob(eny[lp]);
        eny[lp]->kill_ob(team[lpp]);
        if ( teams>=3 )
        {
      	  lpp=random(teams);
      	  team[lpp]->kill_ob(eny[lp]);
      	  eny[lp]->kill_ob(team[lpp]);
        }
        break;
      }
    }
  	eny[lp]->killer_target(team);
  }
  destruct(this_object());
  return 1;
}

//招护寺僧人
object *alert_seng(object me)
{
	object *env, *rtn, ob;
	int bosscheck, lp, tnps;
	
	env=all_inventory(environment(me));
	bosscheck=0;
	rtn=({});
	
	for(lp=0;lp<sizeof(env);lp++)
	{
		if ( env[lp]!=this_object() && 
			   (env[lp]->query("id")=="husi sengren" ||
			    env[lp]->query("id")=="husi zhanglao") &&
			   env[lp]->query("uni_target")==me )
	    bosscheck++;
	}
	
	tnps=4+c_is_day()+random(3+c_is_day())-bosscheck;
	if ( !me->query_temp("cjg/fights") &&
  		 environment(me)->query("cjgmaze")=="level2" )
    tnps+=2;
  
	for(lp=1;lp<tnps;lp++)
	{
		message_vision("$N大叫一声，招来了附近的护寺僧众，向$n猛攻过来！\n", this_object(), me);
		ob=new("/newbiequest/shaolin/cjg/npc/huseng");
		ob->move(environment(me));
		ob->do_copy(me);
		me->kill_ob(ob);
		ob->kill_ob(me);
		ob->killer_target(me);
		rtn+=({ob});
  }
  
  return rtn;
}

void unconcious()
{
//拒绝一招晕
  if(query("qi") > (query("max_qi")/100)*30 && 
  	 query("eff_qi") > (query("max_qi")/100)*30 && 
  	 query("jing") > (query("max_jing")/100)*30 && 
  	 query("eff_jing") > (query("max_jing")/100)*30)
	{
	  return;
	}

	die();
}

//busy最多只能有6个心跳，并且每分钟只能被busy一次
varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	if ( time()- query("busy_time") <60 )
		return;
	else
		set("busy_time", time());

	if ( intp(new_busy) && new_busy>30)
		::start_busy( 30, new_interrupt);
	else
	  ::start_busy(new_busy, new_interrupt);
}

void add_busy(int morebusy)
{
	mixed busy;
	busy=query_busy();

	if ( intp(busy) && !busy && morebusy) {
		if ( time() - query("busy_time") <60 )
			return;
		else
			set("busy_time", time());
	}
	
	tell_room(environment(),sprintf("%d\n", busy));
	
	if (intp(busy) && busy+morebusy>=30 && busy<30)
		::add_busy(30-busy);
	else if ( intp(busy) && busy>=30 )
		return;
	else
	  ::add_busy(morebusy);
}

void die()
{
	object me = query("uni_target");
	object ob = this_object();
  object *env, itm, corpse;
  object *team;
  int lp, loy, drops;
  string *key_drop, *cor_drop, drop_obj;
  mapping drop_list=
  ([ __DIR__"obj/fine_ftools":9990,
  	 "/d/city/obj/normal_ftools":9800,
  	 "/d/city/obj/easy_ftools":9700,
  	 "/newbiequest/shaolin/cjg/drug/mzjinchuang":6000,
  	 "/newbiequest/shaolin/cjg/drug/mzyangjing":7000,
  	 __DIR__"obj/huiqi-yao":3000,
  	 __DIR__"obj/jiedu-wan":4000 ]);
  
  env=all_inventory(this_object());
  for(lp=0;lp<sizeof(env);lp++)
    destruct(env[lp]);
  
	if(!objectp(me)) 
	{
		me=ob->get_damage_origin_object();
		if(!me) 
			me=this_player();
	}
	
	if ( ob->query("id")=="husi zhanglao" )
		loy=5+3*me->query_temp("cjg/hard");
	else
		loy=1+me->query_temp("cjg/hard");

//杀死怪物将获得副本积分，通过杀怪获得副本积分最高为100分。	
	if ( me->query_temp("cjg/killer_point")<100 )
	{
	  tell_room(environment(ob), me->name()+"杀死"+ob->name()+"获得"+chinese_number(loy)+"点藏经阁副本积分。\n");
	  me->add("cjg/point", loy);
	  me->add_temp("cjg/killer_point", loy);
	  team=me->query_team();
	  if ( sizeof(team) > 0 && sizeof(team)== me->query_temp("cjg/teams") )
	  {
	  	for(lp=0;lp<sizeof(team);lp++)
	  	  if ( objectp(team[lp]) )
	  	    team[lp]->add_temp("cjg/total_kp", loy);
	  }
	  if ( !me->query_temp("cjg/total_kp") )
	    tell_object(me, HIR+sprintf("\n你通过战斗获得任务积分%d。\n\n", me->query_temp("cjg/killer_point"))+NOR);
	  else
	  	tell_object(me, HIR+sprintf("\n你通过战斗获得任务积分%d，你的队伍一共获得任务积分%d。\n\n", 
	  	   me->query_temp("cjg/killer_point"),me->query_temp("cjg/total_kp"))+NOR);
	}
	
	drops=random(10000);
	key_drop=keys(drop_list);
	cor_drop=({});
  for(lp=0;lp<sizeof(key_drop);lp++)
  {
  	if ( drops>=drop_list[key_drop[lp]] )
  		cor_drop+=({key_drop[lp]});
  }
  
  if ( sizeof(cor_drop)>0 )
  {
  	drop_obj=cor_drop[random(sizeof(cor_drop))];
  	itm=new(drop_obj);
  	itm->move(me);
  	message_vision("$N掉落了一"+itm->query("unit")+"$n。\n", ob, itm);
  }
  
  message_vision(CYN"\n$N叫道：各位师兄，盗贼太凶猛了，老衲先闪了。\n\n"NOR,this_object());
	destruct(this_object());
}

int do_halt()
{
	object me = this_player();
	if(!me->is_fighting())
	{
		return 0;
	}
	
	tell_object(HIR"生死之战，岂容你逃避？！\n"NOR);
	me->start_busy(1+random(4));
	return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
	if ( !query_temp("weapon") && query("attack_weapon") )
		carry_object(query("attack_weapon"))->wield();

	return ::receive_damage(type,damage,who);
}

int chat()
{
        string *msg;
        int chance, rnd;
         
        if( !environment() || !living(this_object()))
                return 0;
        
        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
                return 0;
        
        if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
                if( random(100) < chance ) {
                        if (sizeof(msg) == 0)
                                return 0;
                        rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
}