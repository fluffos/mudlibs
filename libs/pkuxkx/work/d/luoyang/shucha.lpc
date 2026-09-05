//shucha.c -- 树杈上
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"树杈上"NOR);
  set("long", @LONG
一根粗大的树杈向南伸展着，这根树杈的下面，就是宝相精舍北厢房
的后窗。从这里可以很轻易地看到小院内的景象，但在小院里却不那么容
易发现有人在树上。
LONG
  );

  set("outdoors", "luoyang");
  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_watch", "watch");
}

int do_watch(string arg)
{
	object me;
	me = this_player();
	
	if ( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");
	
	if ( !arg || arg != "window" )
		return notify_fail("你要干什么？\n");
	
	if( arg=="window" )
	{
		switch(random(4))
			{
    	case 0:
				message_vision(
											"\n你屏气凝息，透过窗缝，向屋内望去......\n只见鹿杖客正在盘腿打坐。\n", me);
				me->start_busy(random(4));
  			break;
      case 1:
				message_vision(
											"\n你屏气凝息，透过窗缝，向屋内望去......\n只见鹿杖客正在屋内来回踱步。\n", me);
				me->start_busy(random(4));									
				break;
			case 2:
				message_vision(
											"\n你屏气凝息，透过窗缝，向屋内望去......\n只见鹿杖客正在闭目养神。\n", me);
				me->start_busy(random(4));		
				break;
			case 3:
				message_vision(
											"\n你屏气凝息，透过窗缝，向屋内望去......\n屋内此刻无人。\n", me);
				me->start_busy(1);											
			}
	}			
	
	return 1;
}

int do_climb(string arg)
{
	object me;
	me = this_player();
	
	if ( !arg || arg != "down" )
		return notify_fail("你要干什么？");
	
	if ( arg == "down" )
	{
		message_vision(
									"\n$N从树杈上蹑手蹑脚地向下爬去。\n", me);
		remove_call_out("move_me");
		call_out("move_me", 1, me);
	}
	return 1;
}

int move_me(object me)
{
	me->move(__DIR__"shushang");
	message_vision(">", me);
	return 1;
}
