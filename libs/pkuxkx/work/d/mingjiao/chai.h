#include <ansi.h>
void init()
{
    add_action("do_jian","jian");
}

int do_jian()
{
    object chai;
    object me=this_player();
    if (me->query_temp("mingjiao/tasks/taskno")!=1)
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    message_vision("$N开始收集散落在地面的干柴。\n",me);
    me->add_busy(2);
    if (random(3))
    {
        chai=new(__DIR__"obj/chai");
        chai->move(me);
        tell_object(me,HIG"你拣起了一段干柴！\n"NOR);
        return 1;
    }
    tell_object(me,"但你似乎一无所获。\n");
    return 1;
}