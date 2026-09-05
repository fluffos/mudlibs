//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "军仓");
        set("long", 
"这里是应天府的军仓，东西两面都有重兵驻守。\n"

        );
        set("exits", ([
                
                
                
                "east" : __DIR__"junying1",
                "west" : __DIR__"junying2",
                "southup" : __DIR__"shanlu",
                
                
        ]));
        
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
    add_action("do_qingdian","qingdian");
}

int do_qingdian()
{
    object me=this_player();
    int n=1+random(5);
    if (me->query_temp("mingtasks/bingbu/task")!=3)
    {
        return notify_fail("谁让你来军仓的，军粮官没有放行的意思。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("mingtasks/bingbu/liang_degree")>50)
    {
        tell_object(me,"军粮清点完毕，你可以回兵部复命了。\n");
        return 1;
    }
    me->add_busy(3);
    message_vision("$N开始核算库中的军粮。\n",me);
    me->set_temp("mingtasks/bingbu/liang_degree",(int)me->query_temp("mingtasks/bingbu/liang_degree")+n);
    tell_object(me,HIG"军粮被一一造册存放。\n"NOR);
    return 1;
}