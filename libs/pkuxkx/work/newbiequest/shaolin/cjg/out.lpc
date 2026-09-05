// out.c 矩阵迷宫（出口）
// seagate@pkuxkx by 2011.02.16

inherit ROOM;
string show_point();

void create()
{
	set("short", "青石小径");
	set("long", 
"在幽静的竹林中有一条青石小径通向了竹林深处，旁边有一个布告栏（board）。\n"
	);
	
	set("item_desc", ([ /* sizeof() == 1 */
    "board" : (: show_point :)
  ]));
	
  set("outdoors", "shaolin/cjg");	
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
	object me=this_player();
	
	if ( userp(me) &&
		   me->query_temp("cjg/teams")>2 &&
		   !me->query_temp("cjg/teams2") )
	  me->set_temp("cjg/teams2", sizeof(me->query_team()));
	  
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
    
    if ( ob->query("cjgmaze") != "level2" )
    	return notify_fail("必须等领队先走你才能跟着走。\n");
  }
  
  return ::valid_leave(me, dir);
}

string show_point()
{
	object me=this_player();
	return "截至到目前为止你的杀敌积分为"+me->query_temp("cjg/killer_point")+"，你所在队伍总杀敌积分"+me->query_temp("cjg/total_kp")+"。\n";
}