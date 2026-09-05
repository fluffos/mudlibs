//shushang.c -- 大树上
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"大树上"NOR);
  set("long", @LONG
你来到了树上，四周不是树叶就是四下伸展的树杈，树叶在微风的拂
动下唰唰作响，你眼中尽是一片抖动的绿色。
LONG
  );

  set("outdoors", "luoyang");
  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_jump", "jump");
}

int do_climb(string arg)
{
	int n = this_player()->query_skill("dodge",1);
	object me;
	me = this_player();
	
	if( n < 200 )
		return notify_fail("以你的轻身功夫，想爬到树杈上，又要做到悄无声息，似乎很难。\n");
			
	if ( !arg || (arg != "shucha" && arg != "southup") )
		return notify_fail("你要干什么？\n");
	
	if( arg == "shucha" || arg == "southup" )
	{
		message_vision(
									"\n$N小心翼翼地爬向一根向南伸展的大树杈。\n\n", me);
		remove_call_out("move_me_shucha");
		call_out("move_me_shucha", 1, me);
	}
	return 1;
}

int do_jump(string arg)
{
	object me;
	me = this_player();
			
	if ( !arg || (arg != "down") )
		return notify_fail("你要干什么？\n");
	
	if( arg == "down" )
	{
		message_vision(
									"\n$N一个大鹏展翅，从树上一跃而下，飘然落在地上，竟然毫无声息。\n\n", me);
		remove_call_out("move_me_down");
		call_out("move_me_down", 1, me);
	}
	return 1;
}

int move_me_shucha(object me)
{
	me->move(__DIR__"shucha");
	message_vision(">", me);	
	return 1;
}

int move_me_down(object me)
{
	me->move(__DIR__"xiaoyuan");
	message_vision(">", me);	
	return 1;
}
