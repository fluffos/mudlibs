#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name("菩提子", ({"puti zi", "zi"}));
                set("unit", "颗");
                set("long", "这是一颗晶莹如玉的菩提子，采自灵山佛祖座前，珍稀无比，
乃万年菩提树之实，功能化百劫，渡千灾，与天地同寿。\n");
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
                me->add("max_neili", 20);
                me->add("neili", 20);
                message_vision(HIY "$N吃下一颗菩提子，顿然间只觉一股浩荡无比的真气直冲顶门...\n" NOR, this_player());
        destruct(this_object());
        return 1;
}
