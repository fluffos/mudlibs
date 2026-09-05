// maze.c 矩阵迷宫
// seagate@pkuxkx by 2011.02.16

#include <ansi.h>
inherit ROOM;
#include "nature.h"
inherit F_VIRTUAL;
int xunluo_times;

void create()
{
  set("outdoors", "shaolin/cjg");
  set("cjgmaze", "level1");
  set("no_die",1);
  xunluo_times=0;
  call_out("refresh_xunluo", 1);
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
  
  me->start_busy(1);
  if ( team[0]!=me )
  	return;
  
  if ( !me->is_mask() )
  	complex=0;
  else
    complex=me->query_face_complex();
  inv=all_inventory();
  if ( (me->name()== "守寺僧兵" ||
  	    me->name()== CYN"护寺僧人"NOR) &&
  	   complex >= 100+c_is_day()*100 )
  {
	  for(lp=0;lp<sizeof(inv);lp++)
	  {
		  if(inv[lp]->is_character() &&
			 inv[lp]->query("id")=="husi sengren" &&
			 inv[lp]->query("xunluo"))
			{
			  me->add_temp("cjg/disguise", -1 );
			  tell_object(me, "你感觉巡逻的护寺僧人已经对你们产生了怀疑。\n");
			}
			
			if (inv[lp]->is_character() &&
				  living(inv[lp]) &&
				  ( inv[lp]->query("id")=="husi sengren" ||
				    inv[lp]->query("id")=="husi zhanglao" ) &&
				  inv[lp]->query("fight_team")==me &&
				  inv[lp]->is_fighting() )
		    return;
    }

//每次任务发布给领队至少1点初始伪装度，伪装复杂度从100起每增加300，增加1点伪装度    
    if (me->query_temp("cjg/disguise")<0)
    {
    	for(lp=0;lp<sizeof(team);lp++)
    	{
    		tell_object(team[lp], "你已经被护寺僧人发现踪迹，只看见僧兵越来越多，只见僧兵把你压到了戒律院。\n");
	      if ( (fam = team[lp]->query("family")) && 
	      	   fam["family_name"] == "少林派" 
	           && team[lp]->query("guilty") != 1 )  
	        team[lp]->set("guilty",3);
    		team[lp]->set("startroom", "/d/shaolin/jlyuan");
    		team[lp]->move("/d/shaolin/jlyuan"); 
    	}
    }

//如果random（10）为0的情况下触发地雷    
    if ( !random(10-c_is_day()*5) )
    {
    	tell_object(this_object(), "突然远处一队巡逻僧兵走了过来，已经来不及躲避了，只能尽快杀掉他们。\n");
    	ob=new(__DIR__"npc/huseng");
    	ob->move(this_object());
    	ob->team_copy(team);
    	ob->delete("uni_target");
    	ob->set("fight_team", team[0]);
    	team[0]->add_temp("cjg/fights",1);
//    	destruct(ob);
    }
  }
  else
  {
  	if ( !random(10) ||
  		   c_is_day() )
  	{
    	for(lp=0;lp<sizeof(team);lp++)
    	{
    		tell_object(team[lp], "你已经被护寺僧人发现踪迹，只看见僧兵越来越多，只见僧兵把你压到了戒律院。\n");
	      if ( (fam = team[lp]->query("family")) && 
	      	   fam["family_name"] == "少林派" 
	           && team[lp]->query("guilty") != 1 )  
	        team[lp]->set("guilty",3);
    		team[lp]->set("startroom", "/d/shaolin/jlyuan");
    		team[lp]->move("/d/shaolin/jlyuan"); 
    	}
    }
  }
}

//每30秒钟刷新一次巡逻武僧的位置，有巡逻武僧的房间不能踏入。
void refresh_xunluo()
{
	object *inv, ob;
	int lp;
	
	ob=0;
	inv=all_inventory();
	tell_room(this_object(), CYN"巡逻僧兵在竹林中开始巡逻。\n"NOR);
	for(lp=0;lp<sizeof(inv);lp++)
	{
		if( userp(inv[lp]) )
			return;
		if(inv[lp]->is_character() &&
			 inv[lp]->query("id")=="husi sengren" &&
			 inv[lp]->query("xunluo"))
			ob=inv[lp]; 
  }
  
  if ( !( random(100)%4 ) &&
  	   !( query("exits/enter") ||
  	      query("exits/out") ) )
  {
  	if ( !ob )
  	{
  		ob=new(__DIR__"npc/huseng");
  		ob->set("xunluo", 1);
  		ob->set("name", CYN"巡逻僧人"NOR);
  		ob->move(this_object());
  	}
  }
  else
  	destruct(ob);
  
  xunluo_times++;
  if ( xunluo_times<=30 )
    call_out("refresh_xunluo", 30-c_is_day()*10);
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
  
  if ( dir=="out" && query("exits/out") )
  	return notify_fail("进入藏经阁副本以后就不能回头了。\n");
  
  if ( dir=="enter" && query("exits/enter") )
  {
    if ( me==team[0] )
    	return ::valid_leave(me, dir);
    
    ob=environment(team[0]);
    if ( userp(ob) )
    	return notify_fail("领队的状态不对，等领队状态恢复以后再离开这个地图。\n");
    
    if ( ob->query("cjgmaze") == "level1" )
    	return notify_fail("必须等领队先走你才能再离开。\n");
  }
  
  return ::valid_leave(me, dir);
}

void destruct_ob(object ob)
{
	destruct(ob);
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