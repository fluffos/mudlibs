inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "大草原边缘");
        set("long", @LONG
这里是和林北边一片大草原的边缘，也是蒙古最大的草原。
LONG
        );
	
        set("exits", ([ "south" : __DIR__"helin_n_link",
]));
        set("outdoors", "menggu_m");
		setup();
}

void init()
{
    object zhang,me=this_player();
    object room=load_object(__DIR__"helin_n_link");
    if (!me->query_temp("shediaoquest/jdfm/gogogo"))
    {
        return;
    }
    else if (me->query_temp("shediaoquest/jdfm/kouling"))
    {
        return;
    }
    else if (!zhang=present("shifu zhang",room))
    {
        zhang=new(__DIR__"npc/shifu");
        zhang->set("uni_target",me->query("id"));
        zhang->move(room);
        return;
    }
    else if (zhang->query("uni_target")!=me)
    {
        me->set_temp("shediaoquest/jdfm/cantgo",1);
        tell_object(me,"大汗派出的另一波人正在通过"+room->query("short")+"，此刻过去，恐怕打草惊蛇。\n");
        return;
    }
    else
    {
        tell_object(me,room->query("short")+"的"+zhang->name()+"可不是那么好对付的，要小心一点。\n");
        return;
    }
}

int valid_leave(object me,string dir)
{
    object zhang,room=load_object(__DIR__"helin_n_link");
    if (dir=="south"&&me->query_temp("shediaoquest/jdfm/cantgo"))
    {
        if (!present("shifu zhang",room)&&me->query_temp("shediaoquest/jdfm/gogogo")&&!me->query_temp("shediaoquest/jdfm/kouling"))
        {
            zhang=new(__DIR__"npc/shifu");
            zhang->set("uni_target",me);
            zhang->move(room);
            return notify_fail("另一波人已经通过，你也快想办法混过去吧。\n");
        }
        return notify_fail("大汗派出的另一波人正在通过"+room->query("short")+"，此刻过去，恐怕打草惊蛇。\n");
    }
    return ::valid_leave(me,dir);
}