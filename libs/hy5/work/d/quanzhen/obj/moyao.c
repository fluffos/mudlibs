// moyao.c 没药
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"没药"NOR, ({"moyao"}));
        set_weight(500);
        set("unit", "根");
        set("long", "这是一根名贵药材-没药，看来可以入药。\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="moyao")
        {
                write("你三口两口把没药吃了下去。\n");
                destruct(this_object());
        }
        return 1;
}
