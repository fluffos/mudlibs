// Room: /d/shaolin/hantan3.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "洪荒古洞");
    set("long", @LONG
这是古洞之中。四周风声哗哗，似乎有一股力量在极力吸
着你进古洞。身上却仍然感觉到丝丝寒意侵入肌肤，而且越
是往前，风力越强，寒意更甚。
LONG
       );
    set("no_task", 1);
    setup();
}

void init()
{
    call_out("down", 10, this_player());
}

void down(object me)
{       
    me = this_player();
    if ((me->query("max_neili") < 3000  || me->query("neili") < 3000 )) 
    {
        tell_object(me, "你的内力太低，暗流一卷就把你推回来了。\n");
        me->move(__DIR__"bagua");
        me->set("neili",10);
        me->start_busy(50);
    }
    else if(( random((int)me->query("kar")*2)+random(5000))> 4998 )
    {
        tell_object(me, "突然，一股暗流把你推到一个洞口，你终于可以走到洞里，感觉轻松多了...\n");
        me->move(__DIR__"hantan4");
    }
    else 
    {
        tell_object(me, "你感觉到你的真气开始四处乱闯，渐渐体力不支，不得不回来歇一歇。\n");
        me->move(__DIR__"bagua");
        me->add("neili",-50);
        me->start_busy(50);
    }
}
