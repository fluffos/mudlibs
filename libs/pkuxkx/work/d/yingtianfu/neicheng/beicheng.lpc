//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "北城");
        set("long", 
"这里是应天府的北城。北面是神策门，西北是金川门，西南面是几处军营。\n"

        );
        set("exits", ([
                
                
                "northwest" : "/d/yingtianfu/jinchuan",
                "north" : "/d/yingtianfu/shence",
                "southwest" : __DIR__"junying1",
                "south" : __DIR__"zhonglou",
                "southeast" : __DIR__"gulou",
                
        ]));
        set("objects", ([
                __DIR__"npc/xianhan" : 1,
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
    add_action("do_duzao","duzao");
}

int do_duzao()
{
    object me=this_player();
    int n=1+random(5);
    if (me->query_temp("mingtasks/bingbu/task")!=2)
    {
        return notify_fail("谁让你来北城的，军备官没有放行的意思。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("mingtasks/bingbu/xie_degree")>50)
    {
        tell_object(me,"军械越发充足，你可以回兵部复命了。\n");
        return 1;
    }
    me->add_busy(3);
    message_vision("大批民夫在$N监督下开始制造守城工具。\n",me);
    me->add_temp("mingtasks/bingbu/xie_degree",(int)me->query_temp("mingtasks/bingbu/xie_degree")+n);
    tell_object(me,HIG"地上的军械越积越多……\n"NOR);
    return 1;
}