inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIC "黑玉断续膏" NOR, ({"heiyugao"}));
        set("unit", "粒");
        set("long", "这是一粒千年极其难配制的的黑玉断续膏,据说能起死回生。\n");
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        this_player()->receive_curing("jing", 300);
        this_player()->receive_curing("qi", 2000);
        tell_object(this_player(), HIG "你只觉一股热流在七经八脉中循环了一个周天，立刻神
采奕奕了！\n" NOR );
        destruct(this_object());
        return 1;
}
