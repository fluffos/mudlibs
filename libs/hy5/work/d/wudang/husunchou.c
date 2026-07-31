// /d/wudang/husunchou.c  猢狲愁

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","猢狲愁");
        set("long", @LONG
你好不辛苦才爬到了山顶，这里怪石参差，山风刺骨，三面都是万丈悬崖，
崖壁平滑，连猴子也难以攀登。四周寸草不生，有一棵迎客松(song)孤单地立
于崖边。
LONG                           
        );
	set("outdoors", "武当");
        set("exits", ([
                "northdown":__DIR__"gudao2",
        ]));
        set("item_desc", ([
                "song" :
"这是棵千年迎客松，向崖外生长，树干比碗口还粗，正是一个绝好的借力支撑点。\n",
        ]));

        set("objects",([
                __DIR__"npc/monkey" : 3,

        ]));

        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_bang", ({ "tie", "bang" }));
}                   

int do_pa(string arg)
{
        object me;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("你要往哪爬？\n");
        if (!( present("sheng zi", this_player())))
              return notify_fail("没有支撑点，你怎么下爬？\n");
	if (!me->query_temp("mark/bang"))
              return notify_fail("没有支撑点，你想跳崖自杀呀？！\n");

        message_vision("$N颤颤噤噤地爬了下去。\n", me);
        if ((int)me->query_skill("force", 1) < 20) 
           {
           message_vision(RED"山风突然转强，$N功力不够，无法稳住身体，一阵摇晃，又被吹了回去。\n"NOR, me);
            message_vision(HIR"$N心里一急，一口气转不过来顿时昏了过去。\n"NOR, me);
            me->unconcious();
            return 1;
           }
        me->move(__DIR__"shanya1");
	tell_room(environment(me), me->name() + "从上面爬了下来。\n", ({ me }));
        me->delete_temp("mark/bang");
     	return 1;
}

int do_bang(string arg)
{      
        object me;
        me = this_player();
        if (!( present("sheng zi", this_player())))
            return notify_fail("你要用什么绑？\n");

        if ( !arg || arg != "song" )
            return notify_fail("你要绑什么？\n");
	if (me->query_temp("mark/bang"))
		return notify_fail("绳子已经绑好了。\n");
        message_vision("$N仔仔细细地把绳子一端绑在松树干上。\n", me);
        me->set_temp("mark/bang",1);
        return 1;
}
