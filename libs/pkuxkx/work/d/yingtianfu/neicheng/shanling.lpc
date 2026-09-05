//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "城东皇陵");
        set("long", 
"这里是大明的皇陵，闲杂人等不得入内。\n"

        );
        set("exits", ([
                
                
                
                
                "southdown" : "/d/yingtianfu/tulue1",
                
                
        ]));
        set("no_task",1);
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
    add_action("do_yingzao","yingzao");
}

int do_yingzao()
{
    object me=this_player();
    int n=1+random(5);
    
    if (me->query_temp("mingtasks/neigong/task")!=1)
    {
        return notify_fail("谁让你皇陵的？几个军士拦住了你。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("mingtasks/neigong/yingzao_degree")>50)
    {
        tell_object(me,"皇陵营造告一段落，你可以回去复命了。\n");
        return 1;
    }
    me->add_busy(3);
    message_vision("$N开始监督民伕修建皇陵。\n",me);
    me->set_temp("mingtasks/neigong/yingzao_degree",(int)me->query_temp("mingtasks/neigong/yingzao_degree")+n);
    tell_object(me,HIG"皇陵的营造工作正有条不紊的进行。\n"NOR);
    return 1;
}