// entry.c 矩阵迷宫（入口）
// seagate@pkuxkx by 2011.02.16

#include <ansi.h>
inherit ROOM;

string ask_map();
void create()
{
	set("short", "青石小径");
	set("long", 
"在幽静的竹林中有一条青石小径通向了竹林深处，入口旁边不知道被谁贴上一张地图(map)。\n"
	);
	
	set("item_desc", ([ /* sizeof() == 1 */
  "map" : (:ask_map:) ]));
	
  set("outdoors", "shaolin/cjg");	
	setup();
}

void init()
{
	object me=this_player();
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

string ask_map()
{
	object me=this_player(),*inv, ob, maze;
	int xlp, ylp, lp;
	string msg;
/*	
	if (!wizardp(me))
		return 0;
	*/
	msg=HIG"竹林地图（其中矩阵最下面一条边是入口，最上面一条边是出口，\n" + 
	    "红色是出入口方向，@是空房间，×是存在巡逻兵的房间，由于进入\n" +
	    "的时候地图可能在更新，请多敲几次map，稳定后的map就是正确的\n" +
	    "地图，矩阵地图中巡逻兵每30秒钟更新一次。）：\n"NOR;
	    
	for( ylp=6; ylp>=0; ylp--)
	{
	  for( xlp=0; xlp<10; xlp++)
	  {
	  	call_other(sprintf("%s/%d_%d", __DIR__"zhulin1_config", xlp, ylp), "???");
	  	maze=load_object(sprintf("%s/%d_%d", __DIR__"zhulin1_config", xlp, ylp));
	  	inv=all_inventory(maze);
	  	ob=0;
	  	for(lp=0; lp<sizeof(inv); lp++)
	  	{
	  		if(inv[lp]->is_character() &&
			     inv[lp]->query("id")=="husi sengren" &&
			     inv[lp]->query("xunluo") )
			    ob=inv[lp];
			}
			if ( maze->query("exits/enter") ||
				   maze->query("exits/out") )
				msg+=HIR;
			if( ob )
				msg+="* ";
			else
			 	msg+="@ ";
			msg+=NOR;
	  }
	  
	  msg+="\n";
	}
	return msg;
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
  
  if ( dir=="enter" && query("exits/enter") )
  {
    if ( me==team[0] )
    	return ::valid_leave(me, dir);
    		
    ob=environment(team[0]);
    if ( userp(ob) )
    	return notify_fail("领队的状态不对，等领队状态恢复以后再离开这个地图。\n");
    
    if ( ob->query("cjgmaze") != "level1" )
    	return notify_fail("必须等领队先走你才能跟着走。\n");
  }
  
  return ::valid_leave(me, dir);
}