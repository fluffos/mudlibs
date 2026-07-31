// xuejie.c 血竭
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(RED"血竭"NOR, ({"xuejie"}));
        set_weight(800);
        set("unit", "颗");
        set("long", "这是一颗鲜红的血竭，看来可以入药。\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="xuejie")
        {
                write("你三口两口把血竭吃了下去。\n");
                destruct(this_object());
        }
        return 1;
}
