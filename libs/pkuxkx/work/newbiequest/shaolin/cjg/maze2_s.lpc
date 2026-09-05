// maze.c 随机迷宫（刷怪物地图）
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

int do_lian()
{
	tell_object(this_player(), "这里太危险了，还是不要修炼武功了。\n");
	return 1;
}

void init()
{
	object *inv, me, ob;
	int complex, lp;
	mapping fam;
	
	me=this_player();
	
  if ( !userp(me) )
  	return;

	add_action("do_lian","lian");
	add_action("do_lian","practice");
	add_action("do_lian","xiulian");
	if ( time()-me->query_temp("cjg/time")>=1800 )
	{
		tell_object(me, "你在竹林中滞留了太长时间了，被路过的巡逻僧兵发现了踪迹。\n");
    me->set("startroom", "/d/shaolin/jlyuan");
    me->move("/d/shaolin/jlyuan"); 
    return;
	}

  me->start_busy(1);
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
			if (inv[lp]->is_character() &&
				  living(inv[lp]) &&
				  ( inv[lp]->query("id")=="husi sengren" ||
				    inv[lp]->query("id")=="husi zhanglao" ) &&
				  inv[lp]->query("uni_target")==me &&
				  inv[lp]->is_fighting() )
		    return;
    }
  	
//如果random（3）为0的情况下触发地雷    
    if ( !random(3) || 
    	 !me->query_temp("cjg/fights") )
    {
    	tell_object(this_object(), "突然远处一队巡逻僧兵走了过来，已经来不及躲避了，只能尽快杀掉他们。\n");
    	ob=new(__DIR__"npc/huseng");
    	ob->move(this_object());
    	ob->alert_seng(me);
    	destruct(ob);
    	me->add_temp("cjg/fights",1);
    }
  }
  else
  {
  	if ( !random(3) ||
  		   c_is_day() )
  	{
   		tell_object(me, "你已经被护寺僧人发现踪迹，只看见僧兵越来越多，只见僧兵把你压到了戒律院。\n");
	    if ( (fam = me->query("family")) && 
	      	 fam["family_name"] == "少林派" 
	         && me->query("guilty") != 1 )  
	      me->set("guilty",3);
    	me->set("startroom", "/d/shaolin/jlyuan");
    	me->move("/d/shaolin/jlyuan"); 
    }
  }
}

//没有组队的直接送出副本
//必须领队走出迷宫其他人才可以走
//每走一步都需要检查房间内是否还有你们队伍相关的护寺僧人没有杀干净
int valid_leave(object me, string dir)
{
  object *inv, ob;
  int lp;
  
  inv=all_inventory(this_object());
  for(lp=0; lp<sizeof(inv); lp++)
  {
  	if ( (inv[lp]->query("id")=="husi sengren"||
  		    inv[lp]->query("id")=="husi zhanglao") &&
  		   inv[lp]->query("uni_target")==me )
  	{
  		write("你必须解决了房间内的敌人以后才能离开。\n");
  		return 0;
  	}
  }
  
  if ( dir=="out" && 
  	   query("exits/out") &&
  	   query("maze/room")=="0_0" )
  	return notify_fail("进入藏经阁副本以后就不能回头了。\n");
  
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