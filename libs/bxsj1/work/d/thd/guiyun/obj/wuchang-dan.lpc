#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"无常丹"NOR, ({"wuchang dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", HIR"这是一颗血红的丹药，是桃花岛的疗伤圣药无常丹。\n"NOR);
                set("value", 100);
                set("no_drop", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
         if (!id(arg))
                return notify_fail("你要吃什么？\n");
         me->receive_curing("qi", 10000);
         message_vision(HIR"$N吃下一颗无常丹，脸色看来好多了。\n"NOR, this_player());
        destruct(this_object());
                return 1;
}

