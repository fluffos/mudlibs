// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山林深处");
        set("long", @LONG
山林深处，这里据说有猛虎出没。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                
                "northwest" : __DIR__"shanlu",
                
]));
     
        
   setup();
}

void init()
{
    object me=this_player();
    add_action("do_zhui","zhui");
    if (me->query_temp("zc/step1"))
    {
        tell_object(me,"你看见远处似乎有猛虎的踪迹，立刻准备追(zhui)出去。\n");
        me->delete_temp("zc");
        me->set_temp("zc/step1a",1);
    }
    return;
}

int nextstep(object me)
{
    object laohu;
    laohu=load_object(__DIR__"laohudong");
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
    if (!me->query_temp("zc/step1a"))
    {
        tell_object(me,"你要追什么？\n");
        return 1;
    }
    else
    {
        me->delete_temp("zc/step1a");
        message_vision(HIY+"$N看见老虎的踪迹，紧紧跟了上去。\n"+NOR,me);
        call_out("nextstep",1+random(2),me);
        return 1;
    }
}