#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"爱心果"NOR, ({"shen guo", "guo"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW"这是神奇果子，看起来满不错的样子，吃起来会怎么样呢？:)\n"NOR);
                set("unit", "枚");
                set("value", 200);
        }
}
void init()
{
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{
        object me;

        if( !arg || ((arg != "guo") && (arg != "shen guo")) )
                return notify_fail("你想吃什么？\n");
        me->set_skill("zixia-shengong",32);
        message_vision(MAG"$N狠了狠心，一个大口把爱心果全都吞了下去，噎得直打嗝。\n"NOR,me);
        call_out("destroy", 0);
        return 1;
}
void destroy()
{
        destruct(this_object());
}

