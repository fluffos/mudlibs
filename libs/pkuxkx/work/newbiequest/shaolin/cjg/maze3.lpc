// maze.c 随机迷宫（伤气血陷阱）
// seagate@pkuxkx by 2011.02.17

#include <ansi.h>
inherit ROOM;
#include "nature.h"
inherit F_VIRTUAL;

void create()
{
  set("outdoors", "shaolin/cjg");
  set("cjgmaze", "level2");
  set("no_die",1);
	setup();
}

int do_none()
{
	tell_object(this_player(), "副本内部不允许重组队伍。\n");
	return 1;
}

int do_lian()
{
	tell_object(this_player(), "这里太危险了，还是不要修炼武功了。\n");
	return 1;
}

void init()
{
	object *team, *inv, *eny, me, ob;
	int complex, lp, lpp;
	mapping fam;
	
	me=this_player();
	team=me->query_team();
	
	if ( !arrayp( team ) || 
		   sizeof(team)<2 || 
		   !userp(me) )
    return;

	add_action("do_lian","lian");
	add_action("do_lian","practice");
	add_action("do_lian","xiulian");
	add_action("do_none","team");
	if ( time()-me->query_temp("cjg/time")>=1800 )
	{
		tell_object(me, "你在竹林中滞留了太长时间了，被路过的巡逻僧兵发现了踪迹。\n");
    me->set("startroom", "/d/shaolin/jlyuan");
    me->move("/d/shaolin/jlyuan"); 
    return;
	}
  
  if ( !random(4+c_is_day()*2) )
  {
    message_vision(YEL"$N掉进了护寺僧人设下的陷阱。\n"NOR, me);
    me->start_busy(3);
    me->receive_damage("qi", 1000, "掉进陷阱");
    me->receive_wound("qi", 300, "掉进陷阱");
  }
  
  if ( team[0]!=me )
  	return;

  inv=all_inventory();
	for(lp=0;lp<sizeof(inv);lp++)
	{
	  if (inv[lp]->is_character() &&
			  living(inv[lp]) &&
			  ( inv[lp]->query("id")=="husi sengren" ||
			    inv[lp]->query("id")=="husi zhanglao" ) &&
			  inv[lp]->query("fight_team")==me &&
			  inv[lp]->is_fighting() )
		  return;
  }
  
  if ( ( c_is_day() &&
  	     !random(4) ) || 
    	 !team[0]->query_temp("cjg/fights") )
  {
  	tell_object(this_object(), "突然远处一队巡逻僧兵走了过来，已经来不及躲避了，只能尽快杀掉他们。\n");
  	ob=new(__DIR__"npc/huseng");
   	ob->move(this_object());
   	ob->team_copy(team);
   	ob->delete("uni_target");
   	ob->set("fight_team", team[0]);
   	team[0]->add_temp("cjg/fights",1);
//   	destruct(ob);
  }
}

//没有组队的直接送出副本
//必须领队走出迷宫其他人才可以走
//每走一步都需要检查房间内是否还有你们队伍相关的护寺僧人没有杀干净
int valid_leave(object me, string dir)
{
  object *team, *inv, ob;
  int lp;
  
  team=me->query_team();
  if ( !arrayp( team ) || sizeof(team)<2 )
  {
  	write("藏经阁任务副本只允许组队通过。\n");
  	me->move("/d/shaolin/hsyuan5");
	if (me->query_temp("pfm_skip"))
	{
		me->delete_temp("pfm_skip");
	}

  	return 0;
  }
  
  inv=all_inventory(this_object());
  for(lp=0; lp<sizeof(inv); lp++)
  {
  	if ( (inv[lp]->query("id")=="husi sengren"||
  		    inv[lp]->query("id")=="husi zhanglao") &&
  		   inv[lp]->query("fight_team")==team[0] )
  	{
  		write("你必须解决了房间内的敌人以后才能离开。\n");
  		return 0;
  	}
  }
  
  if ( dir=="out" && 
  	   query("exits/out") &&
  	   query("maze/room")=="0_0" )
  	return notify_fail("进入藏经阁副本以后就不能回头了。\n");
  
  if ( dir=="out" && 
  	   query("exits/out") &&
  	   query("maze/room")!="0_0" )
  {
    if ( me==team[0] )
    	return ::valid_leave(me, dir);
    
    ob=environment(team[0]);
    if ( userp(ob) )
    	return notify_fail("领队的状态不对，等领队状态恢复以后再离开这个地图。\n");
    
    if ( ob->query("cjgmaze") == "level2" )
    	return notify_fail("必须等领队先走你才能再离开。\n");
  }
  
  return ::valid_leave(me, dir);
}

void clean_corpse()
{
	object *inv=all_inventory(this_object());
	int fighting=0,lp;
	
	for ( lp=0;lp<sizeof(inv);lp++ )
	{
	  if ( objectp(inv[lp]) &&
		     !userp(inv[lp]) && 
		     inv[lp]->is_corpse() )
    {
	    destruct(inv[lp]);	
	  }
	  
	  if ( userp(inv[lp]) &&
	  	   inv[lp]->is_fighting() )
	    fighting=1;
	}
	
	if ( fighting )
		call_out("clean_corpse",10);
}