//长安城爵位任务-男爵任务

#include <ansi.h>
#include "quest.h"

#define TITLE_LEVEL 1        //设置爵位任务级别1-男爵
#define QUEST_TIME 900       //任务时间持续15分钟
#define MAX_QUESTS 5         //发布的任务个数最大值
//任务地点
mapping quest_loc=
(["东市":"/d/changan/eastmarket-1",
	"东市附近的顺街":"/d/changan/shunjie-1",
	"西市附近的顺街":"/d/changan/shunjie-2",
	"西市":"/d/changan/westmarket-1",
	"通化门大街":"/d/changan/tonghuastreet-5",
	"长乐坊":"/d/changan/tonghuastreet-3",
	"国子监":"/d/changan/eaststreet-1",
	"大雁塔":"/d/changan/daciensi",
	"小雁塔":"/d/changan/jianfosi"
]);
string *diff_info=({HIG"简单"NOR,YEL"普通"NOR,MAG"挑战"NOR,HIR"困难"NOR});

protected string show_time(int ttime);

//更新任务列表
//主要功能是清除过期任务，补充新任务
void update_quest()
{
	mapping qinfo;
	string *klist, keyid, qname, *locs, *elocs, location;
	int lp,qs,diff;
	
	TITLE_BASE->clean_quest();
	qinfo=TITLE_BASE->query_quests(TITLE_LEVEL);
	klist=keys(qinfo);
	locs=keys(quest_loc);
	//已完成任务超过15分钟强制清除
	for(lp=0;lp<sizeof(klist);lp++)
	{
		if ( qinfo[klist[lp]]["status"]>=2 &&
			   time()-qinfo[klist[lp]]["start_time"]>=QUEST_TIME )
		  TITLE_BASE->clean_quest(klist[lp]);
	}
	qinfo=TITLE_BASE->query_quests(TITLE_LEVEL);
	klist=keys(qinfo);
	qs=sizeof(klist);
	if ( qs>=MAX_QUESTS )
		return;
	
	elocs=({});
	for(lp=0;lp<sizeof(klist);lp++)
		elocs+=({qinfo[klist[lp]]["location"]});
	
	for(lp=0;lp<MAX_QUESTS;lp++)
	{
		diff=random(1000);  //随机选择任务难度
		//50%几率出现简单任务，25%几率出现普通任务，15%几率出现挑战任务，10%几率出现困难任务
		if ( diff<500 )
		{
			diff=0;           //设置任务级别为简单
		}
		else if ( diff<750 )
		{
			diff=1;          //设置任务级别为普通
		}
		else if ( diff<900 )
		{
			diff=2;          //设置任务级别为挑战
		}
		else
			diff=3;          //设置任务级别为困难
		
		qname="缉拿罪犯「"+diff_info[diff]+"」";
		keyid=TITLE_BASE->init_quest(TITLE_LEVEL, qname);
		TITLE_BASE->set_quest(keyid, "difficulty", diff);  //记录任务难度
		locs=locs-elocs;
		location=locs[random(sizeof(locs))];
		locs=locs-({location});
		TITLE_BASE->set_quest(keyid, "location", location);  //记录任务位置
		TITLE_BASE->set_quest(keyid, "expiring_time", time()+QUEST_TIME);  //记录任务超时时间
		qs++;
		if ( qs>=MAX_QUESTS )
			break;
	}
}

//显示任务信息
string show_quest()
{
	string *sstat=({"新建","已领取","已完成","失败"});
	mapping qinfo;
	string *klist;
	int lp;
	string result;
	
	update_quest();
	qinfo=TITLE_BASE->query_quests(TITLE_LEVEL);
	klist=keys(qinfo);
	
	result="官府公布以下任务请全城百姓协助完成：（"HIY"有意者到衙门领取任务"NOR"）\n";
	result+=CYN"任务标识  任务名称         任务状态  发布时间   截止时间   任务地点       资质要求  认领玩家\n"NOR;
  result+="============================================================================================\n";
  for(lp=0;lp<sizeof(klist);lp++)
    result+=sprintf("%8s  %16s %8s %9s  %9s %16s 无        %8s\n", klist[lp], qinfo[klist[lp]]["name"],
              sstat[qinfo[klist[lp]]["status"]], show_time(qinfo[klist[lp]]["start_time"]),  show_time(qinfo[klist[lp]]["expiring_time"]), 
              qinfo[klist[lp]]["location"], qinfo[klist[lp]]["user"]);
  result+="============================================================================================\n";
  
  return result;
}

//领取任务
int get_quest(string keyid, object player)
{
	object npc;
	int ret;
		
	if ( player->query_combatgrade()<10 )
	{
		tell_object(player, "你还需要多行走江湖，才能获得官府的信任。\n");
		return 0;
	}
	
	if ( player->query("changan/lv1/questid") )
	{
		tell_object(player, "你先把手头上的工作完成以后才能接着领下一个任务。\n");
		return 0;
	}
	
	if (player->query("antirobot/deactivity") > 4) 
	{
		tell_object(player, HIR"怎么又是你！我看你是机器人吧。\n"NOR);
		return 0;
	}
	
	//如果存在过期任务则先清理再进行下一步检查
	TITLE_BASE->clean_quest();

  ret=TITLE_BASE->get_quest(keyid, player);
  if ( ret>0 )
  {
  	player->set("changan/lv1/questid", keyid);
  	player->set("changan/lv1/start_time", time() );
    //下一步初始化任务相关npc
    npc=new("/quest/changan/npc/target");
    npc->init_quest(keyid);       //初始化目标对象并且产生一系列路人甲乙丙丁
    tell_object(player, "最近长安城内出现不少盗窃事件，有人报告"+TITLE_BASE->query_quest(keyid, "location")+"附近商铺\n丢失了几件贵重物品，你过去协助查看一下案情。\n");
    return 1;
  }
  else if ( !ret )
  	tell_object(player, "这个任务不是你能领取的，请查询一下别的任务。\n");
  
  return 0;
}

//查询具体位置
string query_location(string location)
{
	return quest_loc[location];
}

protected string show_time(int ttime)
{
	mixed *tm=localtime(ttime);
	if ( tm[1]==59 && tm[2]<23 )
		return sprintf("%d:00:%d", tm[2]+1, tm[0]+1);
	else if ( tm[1]==59 && tm[2]==23 )
		return sprintf("00:00:%d", tm[0]+1);
  else
	  return sprintf("%d:%d:%d", tm[2], tm[1]+1, tm[0]+1);
}