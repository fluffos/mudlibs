// medicine: xuelian.c
// llin 
#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("何首乌", ({"heshou wu", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
               set("unit", "支");
               set("long", "一支已初成人形的何首乌，一看就知道是名贵的药材。\n");
               set("value", 20000);
        }
        setup();
}

int do_eat(string arg,object me)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
	message_vision(HIY"$N吃了一支何首乌，只觉疲劳顿消，精神倍增。\n"NOR,me);
	me->add("max_jing",2);

       	destruct(this_object());
       	return 1;
}
