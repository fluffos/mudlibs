//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "库房");
        set("long", 
"这里是御用监的库房，你可以整理(zhengli)物件。\n"

        );
        set("exits", ([
                
              
                
                "out" : __DIR__"yuyong",
                
        ]));
        
       
        setup();
   
}

void init()
{
    add_action("do_zhengli","zhengli");
}

int do_zhengli()
{
    object me=this_player();
    int n=1+random(5);
    
    if (me->query_temp("mingtasks/yuyong/task")!=1)
    {
        return notify_fail("谁让你库房的？当心砍了你的手。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("mingtasks/yuyong/zhengli_degree")>50)
    {
        tell_object(me,"库房已经被你整理的井井有条，可以回去复命了。\n");
        return 1;
    }
    me->add_busy(3);
    message_vision("$N开始整理库房。\n",me);
    me->add_temp("mingtasks/yuyong/zhengli_degree",(int)me->query_temp("mingtasks/yuyong/zhengli_degree")+n);
    tell_object(me,HIG"你认真比对，把一件件器物归档。\n"NOR);
    return 1;
}