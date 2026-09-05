// medicine: xuelian.c
// llin 
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
        set_name("山参", ({"shan shen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
               set("unit", "支");
               set("long", "一支色作土黄的山参，难得的草药啊。\n");
               set("value", 20000);
        }
        setup();
}

int do_eat(string arg,object me)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
	message_vision(HIY"$N从囊中取出一支山参吃了下去，只觉气血旺盛，精神一振。\n"NOR,me);
	me->add("max_neili",2);

       	destruct(this_object());
       	return 1;
}

