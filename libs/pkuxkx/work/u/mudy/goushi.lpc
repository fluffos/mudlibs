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
        set_name(HIG"臭狗屎"NOR, ({"chou goushi", "goushi", "shi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是啸天犬啦的一粒臭狗屎。\n");
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
        message_vision(HIG "$N吃下一粒臭狗屎，满口狗屎味 !\n" NOR, me);

       	destruct(this_object());
       	return 1;
}
