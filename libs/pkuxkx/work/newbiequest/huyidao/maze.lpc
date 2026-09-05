// milin3.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;
inherit F_VIRTUAL;

void create()
{
  set("outdoors", "hydmaze");
	setup();
}

void init()
{
	add_action("do_leave","leave");
}

int do_leave()
{
	object me=this_player();
	
	if ( !me->query_temp("yidao/from") )
		return notify_fail("你在树林里转来转去，也不知道往哪儿走。\n");

	tell_object(me,"你发现前面没路了，没奈何只能原路返回。\n");
	me->move(me->query_temp("yidao/from"));
	return 1;
}

int valid_leave(object me,string dir)
{
	object ob;

	if ( time()-me->query_temp("yidao/maze_time")>=900 )
	{
	  tell_object(me, "你里面待的时间太长了，胡一刀的家丁害怕有事，把你带了出来。\n");
		if ( me->query_temp("yidao/from") )
			me->move(me->query_temp("yidao/from"));
		else
			me->move("/d/city/kedian");
	  return 0;
	}
	
	ob=me->query_temp("yidao/maze");
	if ( objectp(ob) && dir=="east" )
		ob->set("vtime",0);
	
	return ::valid_leave(me, dir);
}