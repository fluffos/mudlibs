//屯田
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "屯田");
        set("long", 
"这里是皇家的田庄，你可以来指挥屯田(tun)。\n"

        );
        set("exits", ([
                
                
                
                "east" : __DIR__"guandaosa",
                
                
        ]));
        set("outdoors", "yingtianfu");
		set("no_task",1);
        setup();
   
}

void init()
{
    add_action("do_tun","tun");
}

int do_tun()
{
    object me=this_player();
	string *desc=({"抢种作物","挑水施肥","清除虫害","收割庄稼"});
    int n;
    if (me->query_temp("mingtasks/gongbu/task")!=2)
    {
        return notify_fail("这里可是皇庄，闲杂人等切勿接近。\n");
    }
	if (me->is_busy())
	{
		return notify_fail("你正忙着呢。\n");
	}
    message_vision("$N指挥起大量民伕在田间"+desc[random(sizeof(desc))]+"。\n",me);
    n=1+random(5);
    me->add_temp("mingtasks/gongbu/tuntian",n);
    me->add_busy(2);
	if (me->query_temp("mingtasks/gongbu/tuntian")>30)
	{
		me->set_temp("mingtasks/gongbu/task2finish",1);
		me->delete_temp("mingtasks/gongbu/tuntian");
		tell_object(me,"屯田的任务基本顺利完成了，你可以回去复命了。\n");
	}
    return 1;
}

int valid_leave(object me,string dir)
{
	if (me->query_temp("mingtasks/gongbu/task")==2)
	{
		me->delete_temp("mingtasks/gongbu/task");
	}
	return ::valid_leave(me,dir);
}