// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大湖");
        set("long", @LONG
这里是义兴县西的一处大湖，据说湖底有蛟龙经常吃人。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "eastup" : __DIR__"yx-ximen",
             
]));
    
    set("objects", ([
     //   "/d/city/npc/bing" : 1,
        ]));    
   setup();
}

void init()
{
    object me=this_player();
    add_action("do_zhui","qian");
    if (me->query_temp("zc/step2"))
    {
        tell_object(me,WHT+"你看见深水处有蛟龙翻腾，立刻准备潜(qian)下去。\n"+NOR);
        me->delete_temp("zc");
        me->set_temp("zc/step2a",1);
    }
    return;
}

int nextstep(object me)
{
    object laohu;
    laohu=load_object(__DIR__"longtan");
    me->move(laohu);
    laohu->start(me);
    return 1;
}

int do_zhui()
{
    object me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("zc/step2a"))
    {
        tell_object(me,"水那么深，这可不是个洗澡的好处所。\n");
        return 1;
    }
    else
    {
        me->delete_temp("zc/step2a");
        message_vision("$N潜下水去，准备降伏蛟龙。\n",me);
        call_out("nextstep",1+random(2),me);
        return 1;
    }
}