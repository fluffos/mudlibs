// Room: yabi6.c

#include <ansi.h>
#include <room.h>

inherit ROOM;
#include "tiao.c"

void init()
{
        add_action("do_pa", "pa");       
}

void create()
{
	set("short", HIG"崖壁"NOR);
	set("long", @LONG
你手握藤条，身体紧紧贴附在悬崖峭壁之上。向四周望去，只见到云雾缭
绕的一片迷茫。阵阵切骨山风吹得你遍体冰凉。山壁光滑平境，要是没有支撑
点，就连飞鸟也难以立足。
LONG);	

        set("outdoors", "绝情谷");
	
	setup();
	
}

int do_pa(string arg)
{
	object me;
	me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
	if ( !arg || (arg != "down" && arg != "up"))
       		return notify_fail("你要往哪爬？\n");	
	if (arg =="down"){
          if ((int)me->query_temp("tengacc") <= 0)
       	     return notify_fail(HIR"藤条已经放尽，你无法再往下面爬了！\n"NOR);
	  message_vision(HIG"$N颤颤噤噤地爬了下去。\n"NOR, me);
	  me->move(__DIR__"yabi7");
	  me->add_temp("tengacc",-1);
          me->start_busy(1);
	  tell_room(environment(me), me->name() + "从上面颤颤噤噤地爬了下来。\n", ({ me }));
	  }
	if (arg =="up")	{	
          message_vision(YEL"$N颤颤噤噤地爬了上去。\n"NOR, me);
	  me->move(__DIR__"yabi5");
	  me->add_temp("tengacc",1);
          me->start_busy(1);
	  tell_room(environment(me), me->name() + "从下面颤颤噤噤地爬了上来。\n", ({ me }));
	  }
      return 1;
}
