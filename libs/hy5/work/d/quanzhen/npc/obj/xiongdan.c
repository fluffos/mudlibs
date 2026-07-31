// xiongdan.c 熊胆
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"熊胆"NOR, ({"xiongdan"}));
        set_weight(1000);
        set("unit", "颗");
        set("long", "这是一颗鲜红的熊胆，看来可以入药。\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="xiongdan")
        {
                write("你三口两口把熊胆吃了下去。\n");
                destruct(this_object());
        }
        return 1;
}

