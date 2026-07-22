// medicine: xuelian.c
// Jay 3/18/96

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("天山雪莲", ({"xue lian", "lian", "lotus"}));
	set_weight(250);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支只有在寒冷的地方才能生长的雪莲。\n");
                set("value", 100);
		set("treasure", 1);
        }
        setup();
}

int do_eat(string arg)
{
       object me = this_player();

       if (!id(arg))
               return notify_fail("你要吃什么？\n");

	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
       message_vision(HIG "$N吃下一枚"
	+this_object()->query("name")+
	HIG "，顿时觉得头脑清爽，精神为之一振。\n"
	NOR,me);
       me->set("qi", me->query("max_qi"));
       me->set("jing", me->query("max_jing"));
	me->start_busy(1);
       destruct(this_object());
       return 1;
}

