// tianqi.c 田七
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"田七"NOR, ({"tianqi"}));
        set_weight(800);
        set("unit", "根");
        set("long", "这是一根田七，看来可以入药。\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="tianqi")
        {
                write("你三口两口把田七吃了下去。\n");
                destruct(this_object());
        }
        return 1;
}
