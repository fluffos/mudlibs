inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/check_point.h"
string look_bi();
void create() 
{ 
        set("short", HIW"西峰"NOR);
        set("long", @LONG
这里是不儿罕山的西边主峰，同样也是终年积雪，一处峭壁(bi)通向山下。
LONG
        );
	    set("item_desc", ([
		"bi" : (:look_bi:), ]));
        set("exits", ([ "east" : __DIR__"buerhan4",
                        
]));
        set("outdoors", "menggu_e");
		setup();
}

string look_bi()
{
    object me=this_player();
    string msg;
    if (me->query_skill("dodge")<1000)
    {
        if (me->query_temp("shediaoquest/jdfm/gogogo"))
        {
            msg="这里峭壁险峻，根本没有落脚之地。但军情紧急，你也只好冒险一试(climb)。\n";
        }
        else
        {
            msg="这里峭壁险峻，根本没有落脚之地。跳(jump)下去估计是最快的找死方法了。\n";
        }
    }
    else
    {
        msg="此处虽然险峻，但小心些应该可以攀爬(climb)而下。\n";
    }
    return msg;
}

void init()
{
    add_action("do_climb","climb");
    add_action("do_jump","jump");
}

int do_jump(string arg)
{
    object room,me=this_player();
    if (arg=="down")
    {
        room=load_object(__DIR__"buerhan6_down");
        message_vision("$N纵身跳了下去。\n",me);
        tell_room(room,me->name()+"从峰顶跳了下来。\n");
		me->move(room);
        if (random(100)>95)
        {
            me->receive_damage("qi", 0, "从峰顶跳下");
            me->die();
        }
        else
        {
            me->unconcious();
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int do_climb(string arg)
{
    object room,me=this_player(),ob=this_object();
    if (arg=="down")
    {
        if (me->query_skill("dodge")>=1000)
        {
            room=load_object(__DIR__"buerhan6_down");
            tell_object(me,"你小心翼翼地向峭壁深处爬了下去。\n");
            tell_room(room,me->name()+"小心翼翼地爬了下来。\n");
			me->move(room);
			if (me->query_temp("shediaoquest/jdfm/gogogo"))
			check_point(me,ob);
        }
        else
        {
            if (me->query_temp("shediaoquest/jdfm/gogogo"))
            {
                room=load_object(__DIR__"buerhan6_down");
                tell_object(me,"你怀着必死的决心，向峭壁深处爬了下去。\n");
                tell_room(room,me->name()+"小心翼翼地爬了下来。\n");
				me->move(room);
                check_point(me,ob);
            }
            else
            {
                tell_object(me,"爬是爬不下去的！\n");
            }
        }
    }
    else
    {
        tell_object(me,"你四脚着地，学着山间的土狗爬了起来！\n");
    }
    return 1;
}
