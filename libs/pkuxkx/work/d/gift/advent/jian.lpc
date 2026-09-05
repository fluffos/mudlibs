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
    me = this_player();
    if (!arg)  return notify_fail("你要吃什么？\n");
    if((arg=="shen guo") || (arg=="guo")) 
    {
        if ( (int)me->query("marks/xmas2002" ) > 0 ) return notify_fail("你已经吃过爱心果了！\n");
        me->add("mud_age",-172800);
        message_vision(HIG"\n$N一口把爱心果吞了下去!\n"NOR,me);
        tell_object(me,"你觉得自己年轻了很多！");
        me->set("marks/xmas2002",1);
        destruct(this_object());
     }
     return 1;
}
