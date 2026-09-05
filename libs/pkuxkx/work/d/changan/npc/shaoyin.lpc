//zine分管房子放出
#include <ansi.h>
#include "/quest/changan/quest.h"

inherit NPC;

int ask_ling();
int ask_tongji();
int ask_reward();
int ask_points();
int quest_help();

void create()
{
	set_name("郭隆", ({ "jingzhao shaoyin", "shaoyin" }));
	set("title",YEL"京兆少尹"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "他是一个京兆府少尹，协助京兆尹负责京城的大小日常事务。\n");
	
	set("combat_exp", 100000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "通行令" : (: ask_ling :),
    "通缉" : (: ask_tongji :),
    "布告栏" : "城门口的布告栏上会定时贴出最近城中发生的大小案件，有兴趣的侠士可以在\n我这里登记（record）任务，完成任务以后将证据交还给我。\n",
    "任务信息" : (: quest_help :),
    "领赏" : (: ask_reward :),
    "积分" : (: ask_points :),
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_record", "record");
}

int ask_ling()
{
	object me=this_player(),ob;
	
	if ( me->query("repute")<200000 &&
	     me->query("changan/points")+me->query("changan/level")*100<100 )
	{ 
		tell_object(me, "你的声望不够不能申请皇城通行令。\n");
		return 1;
	}
	
	if ( me->query("balance")<10000 )
	{ 
		tell_object(me, "申请皇城通行令至少要花费1两黄金。\n");
		return 1;
	}
	
	message_vision("$n缴纳了一两黄金后，$N递给$n一面"+HIM+"皇城通行令"+NOR+"，凭令可以在一天内在皇城内通行无阻。\n",this_object(), me);
	me->add("balance",-10000);
	ob=new(__DIR__"obj/ling-1");
	ob->move(me);
	return 1;
}

int ask_tongji()
{
	object me=this_player();
	int killer;
	
	if ( !(killer=me->query_condition("cakiller") ) )
	{ 
		tell_object(me, "你没有在长安城犯事，又何必过来投案自首。\n");
		return 1;
	}
		
	if ( me->query("balance")<killer*5000 )
	{ 
		tell_object(me, "你至少要缴纳"+chinese_number(killer*50)+"两白银，才会撤销对你的通缉。\n");
		return 1;
	}
	
	me->add("balance",-killer*5000 );
	me->apply_condition("cakiller",0);
	tell_object(me, "你缴纳了"+chinese_number(killer*50)+"两白银，长安城京兆尹撤销了对你的通缉。\n");
	return 1;
}

int ask_reward()
{
	object player;
	string keyid;
	
	player=this_player();
	
	if ( !(keyid=player->query("changan/lv1/questid")) )
	{
		tell_object(player, "你未领取任务，也不能领取奖励。\n");
		return 1;
	}
	
	return TITLE_BASE->get_reward(keyid, player, 1);
}

int quest_help()
{
	object me=this_player();
  printf(TITLE_LV1->show_quest()+"\n");
  printf(
@LONG
    使用record命令登记或者取消任务，record命令只能取消领取的任务，失败或者成功的
任务不需要使用record命令取消。
    领取任务以后到案件发生的地点附近，询问附近的路人案件相关消息，收集完成信息以
后你可以向官府指证（testify）罪犯或者直接逮捕目标（ask 目标 about 盗贼），向官府
指证只有一次机会，出错没有任何奖励，直接逮捕罪犯有最多二次确认罪犯的机会，逮捕罪
犯不能中途终止战斗，否则下次罪犯就会直接逃跑。
LONG);
  return 1;
}

int do_record(string arg)
{
	object me;
	string keyid;
	int ret;
	
	me=this_player();
	
	if ( !arg )
	{
		tell_object(me, "必须输入任务标识，本衙门通缉的罪犯都可以在长安城各个城门的布告栏上找到。\n命令格式：record 任务标识|cancel，表示接任务或者取消自己领取的任务");
		return 1;
	}
	
	if ( arg=="cancel" )
	{
		keyid=me->query("changan/lv1/questid");
		if ( !keyid )
		{
			tell_object(me, "你并没有领取本衙门发布的通缉任务。\n");
			return 1;
		}
		
		ret=TITLE_BASE->complete_quest(keyid, me, 1);
		tell_object(me, "你取消了上一次领取的通缉任务。\n");

	  me->delete("changan/lv1");		
		return 1;
	}
	
	TITLE_LV1->get_quest(arg, me);
	return 1;
}

int ask_points()
{
	object me=this_player();
	int points, extpoints;
	
	points=me->query("changan/points");
	extpoints=me->query("changan/ext_points");
	if ( !me->query("changan/level") && points<100 )		
	{
		tell_object(me, "你拥有爵位升级积分"+chinese_number(points)+"点，还差"+chinese_number(100-points)+"才能升级为开国县男。\n");
		return 1;
	}
	else if ( !me->query("changan/level") && points>=100 )
	{
		tell_object(me, "你拥有爵位升级积分"+chinese_number(points)+"点，已经足够升级到开国县男，请尽快到吏部升级爵位。\n");
		return 1;
	}
	else
	{
		tell_object(me, "你在当前爵位积累了爵位升级积分"+chinese_number(points)+"点，积累了任务奖励积分"+chinese_number(extpoints)+"点。\n");
    return 1;
	}
}