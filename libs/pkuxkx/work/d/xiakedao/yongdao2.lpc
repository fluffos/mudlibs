#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "甬道");
	set ("long", @LONG

   这是一条长长的甬道，两旁点着油灯，光线虽暗，却也可辨
道路。甬道依着山腹中天然洞穴修凿而成，人工开凿处甚是狭窄
，有时却豁然开阔，只觉渐行渐低，洞中出现了流水之声，琮琮
铮铮，清脆悦耳，如击玉罄。你俯身倾听(listen),想知道水源的方位。
LONG);

 	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : __DIR__"yongdao3",
		"southup" : __DIR__"yongdao1",
	]));

  setup();
}

void init()
{
	add_action("do_listen","listen");
	add_action("do_listen","ting");
	add_action("do_search","search");
	add_action("do_search","mo");
	add_action("do_push",  "push");
	
}

int do_push(string arg)
{
	object me;
	me = this_player();
        if ( ( !arg) || (arg != "开关"  && arg != "button") )
	{
		tell_object(me,"你要按什么？\n");
		return 1;
	}
	if ( me->query_temp("marks/摸到") )
	{
		message_vision(HIG"$N按动开关，顿觉前方墙壁一转，眼前一花...\n"NOR,me);
		me->move(__DIR__"ting1");
		message_vision(HIG"$N挣开双眼，发现自己已经到了墙壁以内。顿觉豁然开朗。\n"NOR,me);
		return 1;
	}
	tell_object(me,"哪里有什么开关，莫不是你在意想天开！\n");
	return 1;
}
int do_search(string arg)
{
	object me;
	me = this_player();
        if ( (!arg ) || ( arg!= "墙壁" && arg != "左侧墙壁" && arg != "leftwall" && arg != "wall") ) 
		return notify_fail("你要找什么？\n");
         if ( arg == "墙壁" || arg == "wall")
		return notify_fail("你要搜索哪面墙壁？\n");
        if ( ( arg == "左侧墙壁" || arg == "leftwall") && ( me->query_temp("marks/听到") ) )
	{
		me->start_busy(3);
		call_out("searching",3,me);
		return 1;
	}
	else {
		return notify_fail("你没事闲的，摸墙干吗？\n");
	}
				
}
int searching(object me)
{
       message_vision(HIR"$N在左侧墙上的一块石缝中摸到了一处开关(button)。\n"NOR,me);
	me->set_temp("marks/摸到",1);
	me->delete_temp("marks/听到");
	return 1;
}
int do_listen()
{
	object me;
	me = this_player();
	message_vision("$N拢起右手搭在耳边，仔细倾听着声音的来源。\n",me);
	call_out("check_move",5,me);
	return 1;
	
}

int check_move(object me)
{
	if(  environment(me) != this_object() ) return 1;	
       message_vision(HIY"$N听到声音的来源好象是从左侧(left)的墙壁(wall)中发出的。\n"NOR,me);
	me->set_temp("marks/听到",1);
	return 1;
}
