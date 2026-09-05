// Room: /hangzhou/td_datang.c
// hubo 2008/4/19

inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
        set("short", "监狱");
        set("long", @LONG
杭州提督府的监狱，人犯要被关一段时间才能离开。
LONG);
        //set("outdoors", "hangzhou");
        set("exits", ([     
                "out" : __DIR__"td_houmen",
]));
        set("valid_startroom", 1);
        set("no_task",1);
        setup();
}

int notice(object ob)
{
    if (!ob||!living(ob))
    {
        return 1;
    }
    else if (environment(ob)&&environment(ob)==this_object())
    {
        tell_object(ob,HIG+"羁押期满，你被无罪开释了，现在可以离开了。\n"+NOR);
        return 1;
    }
    else
    return 1;
}

void init()
{

        object ob, room;
        int tick;
        ob = this_player();
        room = this_object();
        tick=30+random(30);
        if (!ob->query_temp("td_jianyu_enter"))
        {
            ob->set_temp("td_jianyu_enter",time()+tick);
        }
        call_out("notice",tick-1,ob);
        return;
}

int valid_leave(object me,string dir)
{
    object ob;
    if (!userp(me))
    {
        return notify_fail("NPC不许出去！\n");
    }
    else if (!me->query_temp("td_jianyu_enter"))
    {
        me->set_temp("td_jianyu_enter",time());
        return notify_fail("羁押期未满，你现在还不能出去！\n");
    }
    else if (me->query_temp("td_jianyu_enter")&&time()<(int)me->query_temp("td_jianyu_enter"))
    {
        return notify_fail("羁押期未满，你现在还不能出去！\n");
    }
    else
    {
        ob=load_object(__DIR__"td_houmen");
        me->delete_temp("td_jianyu_enter");
        tell_object(me,"你从监狱中被无罪开释了出来。\n");
        tell_room(ob,me->name()+"被从提督府释放了出来。\n");
        return ::valid_leave(me,dir);
    }
}