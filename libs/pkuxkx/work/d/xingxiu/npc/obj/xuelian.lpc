// medicine: xuelian.c
// Jay 3/18/96

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
        set_name("天山雪莲", ({"xue lian", "lian", "lotus"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支只有在寒冷的地方才能生长的雪莲。\n");
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
	object me=this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

        me->add("max_jingli", 1);
         message_vision(HIG "$N吃下一支天山雪莲，只觉得全身充满活力！\n" NOR, me);

       	destruct(this_object());
       	return 1;
}
