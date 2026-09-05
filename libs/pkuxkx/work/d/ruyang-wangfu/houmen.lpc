//houmen.c -- 王府后门
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"王府后门"NOR);
  set("long", @LONG
这里是王府内宅的后门，没什么事，这个门从来不开。
LONG
  );

  set("exits", ([     
//		"east" : __DIR__"lane",
      "southwest" : __DIR__"neizhai-houyuan",   
  ]));

  set("outdoors", "luoyang");
  set("no_clean_up", 0);
  setup();
//  replace_program(ROOM);
}

void init()
{
	add_action("do_jump", "climb");
	add_action("do_jump", "pa");
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_unlock", "unlock");
}

int do_jump(string arg)
{
        object me;
        int n = this_player()->query_skill("dodge",1);
        me = this_player();
        
	if (!arg || (arg != "wall"))
		return notify_fail("你要干什么？\n");
	
	if( arg=="wall" ) 
	{
		if( n > 100 ) 
		{
			message_vision(
			"\n$N小跑几步，纵身一跃，轻轻巧巧地翻过了墙头。\n\n", me);
			remove_call_out("move_me");
			call_out("move_me", 1, me);
		}
		else
		{
			message_vision(
			"\n$N双手扒住墙头，双脚悬空，上下乱蹬，可就是爬不过这该死的墙头，看来$N该减减肥了。\n\n", me);
		}
	}
	
return 1;
}

int do_unlock()
{
	object ob, me;
	me = this_player();
	
	if (!(ob = present("tie key", this_player())))
			return notify_fail("你没有钥匙，又不会撬锁，打不开王府后门。\n");
	else
	{
		message_vision("$N用一把铁钥匙打开了王府的后门，悄悄地溜出了王府。\n\n", this_player());
		me->move(__DIR__"lane1");
		message_vision(">", me);			
	}
	return 1;
}

int move_me(object me)
{
	me->move(__DIR__"lane1");
	message_vision(">", me);	
	return 1;
}
