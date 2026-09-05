//wofang-w.c -- 西卧房
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"西卧房"NOR);
  set("long", @LONG
自从王爷几个月前新纳了一名西域进贡的胡姬做妾，就常常住在这里
。这里房间的布置与东卧房如出一辙，只是多了些绿色的幔帐，挂毯上的
图案也与东卧房明显不同，带有些波斯的韵味。房间里点着不知名的香，
淡淡的烟雾，缓缓地包围了你，一缕缕浓香不时飘过来，使你有点昏昏欲
睡，一个冷战突然让你惊醒，你强压下心头汩汩涌起的冲动，不断地提醒
自己，要镇定......  要镇定...... ......

LONG
  );

  set("exits", ([     
      "east" : __DIR__"neizhai-zhengting",
  ]));

	set("objects", ([
		__DIR__"npc/huji" : 1,
	]));

  setup();
//  replace_program(ROOM);
}

void init()
{
	object me = this_player();
	
	if ( userp(me) && (int)me->query_temp("jiehuji_step") != 1 && environment(me)->query("short") == HIC"西卧房"NOR ) 
	{
		remove_call_out("piao_xiang");
		call_out("piao_xiang", 2, me);
		call_out("piao_xiang", 4, me);
		
		remove_call_out("fainting");
		call_out("fainting", 6, me);
	}
}

int valid_leave(object me, string dir)
{
	if ( dir == "east" )
	{
		remove_call_out("piao_xiang");
		remove_call_out("piao_xiang");		
//		remove_call_out("fainting");
	}
	return ::valid_leave(me, dir);
}


int fainting(object me)
{
	me = this_player();
	
	message_vision("\n"HIR"$N察觉那香味有些不对... 但为时已晚"NOR"\n",me);
	me->unconcious();
	me->move("/d/ruyang-wangfu/shuilao");	
	return 1;
}

int wakeup(object me)
{
	me = this_player();
	
	me->revive();
	return 1;
}

int piao_xiang(object me)
{
	me = this_player();
	
	switch(random(3))
		{
			case 0:
				message_vision(
											"\n"YEL"一缕暗香飘过，除了淡淡的香气，$N没觉得有什么异样 ......"NOR"\n\n>", me);
				me->add("jing", -50);
				break;
			case 1:
				message_vision(
											"\n"HIG"一缕浓香飘过，$N渐渐觉得有些头晕目眩 ......"NOR"\n\n>", me);
				me->add("jing", -100);
				break;	
			case 2:
				message_vision(
											"\n"MAG"一层淡淡的烟雾混着丝丝异香在$N的身前缓缓飘过，$N觉的眼皮开始发沉 ......"NOR"\n\n>", me);
				me->add("jing", -100);
				break;				
		}
	return 1;
}
