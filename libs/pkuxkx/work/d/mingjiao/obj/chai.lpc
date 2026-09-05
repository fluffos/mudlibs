//柴火，mj新手任务 by Zine
#include <ansi.h>

inherit ITEM;


void init()
{
    add_action("do_chai","jiachai");
}

void create()
{
        set_name("柴火", ({"chai huo", "chai"}));
        set("unit", "支");
        set("long", "这是一支干燥的柴火，可以往圣火里添加(jiachai)。\n");
        set("value", 0);
        setup();
}

int do_chai()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/task1start"))
    return notify_fail("你还没开始看守圣火，扇什么风？\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (base_name(environment(me))!="/d/mingjiao/fireroom")
    return notify_fail("你要往哪里加柴？\n");
    if (me->query_temp("mingjiao/tasks/task1act")=="chai")
    {
        message_vision("$N小心翼翼往圣火里添了点柴火，圣火燃烧得更加健旺了。\n",me);
        me->delete_temp("mingjiao/tasks/task1act");
        me->delete_temp("mingjiao/tasks/chai");
        me->add_temp("mingjiao/tasks/task1actsuc",1);
        destruct(this_object());
        return 1;
    }
    else
    {
        message_vision("因为$N的胡乱操作，圣火熄灭了。快去狮王那里领罪吧。\n",me);
        me->delete_temp("mingjiao/tasks/task1act");
        me->set_temp("mingjiao/tasks/task1fail",1);
        destruct(this_object());
        return 1;
    }
}

