//lane2.c -- 僻静小巷
//Zone: 汝阳王府
//Created by ddid
//2009-6-14

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"僻静小巷"NOR);
  set("long", @LONG
这里是一条僻静的小巷，两侧都是高高的围墙。拐角的墙根下似乎趴
着一个人(ren)。
LONG
  );

  set("exits", ([     
      "northeast" :"/d/luoyang/hutong1",   
			"north" : __DIR__"lane1",
  ]));
/*
	set("item_desc", ([
		"ren" : (:	look_ren()	:),
	]));
*/
  set("outdoors", "luoyang");
  setup();
}

void init()
{
	add_action("do_movex", "move");
	add_action("do_movex", "ban");
	add_action("do_movex", "help");
	add_action("do_movex", "jiu");
	add_action("look_renx","look");
}

int do_movex(string arg)
{
	object me,ob;
	me = this_player();
	
	if (!arg || (arg != "ren"))
		return notify_fail("你要干什么？\n");

	if( arg=="ren" )
	{	
		me->set_temp("jiehuji_step",1);
			
		ob = new(__DIR__"npc/weiyixiao",1);
		ob->move(__DIR__"lane2");
		
		message_vision("\n你把那人扳了过来，赫然就是韦一笑！\n", me);
	}			
	return 1;
}

int look_renx(string arg)
{
	/*	
	object me;
	if ( (int)me->query_temp("jiehuji_step") == 1 || !intp(me->query_temp("jiehuji_step")) )
		return "那只是个破斗篷，碰巧摆成个人形。\n";
	*/
	if (arg && arg == "ren")
	{
		write("那人裹在一件青色的大斗篷里，此刻正趴在地上，看不到面目，但似乎正在瑟瑟发抖。\n");
		return 1;
	}
	return 0;
}