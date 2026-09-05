// cb_renshen.c

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("老山参", ({"laoshan shen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支生长在长白山地区的老山参。\n");
                set("value", 1000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

	if(me->is_busy())
	return notify_fail("你正忙着呢。\n");

	switch (random(2))
	{
		case 0:
        	me->add("max_neili", 1);
        	message_vision(HIG "$N吃下一支老山参，只觉得内功又有进境 !\n" NOR, me);
        	break;
        	case 1:
        	message_vision(GRN "$N吃下一支老山参，但是由于服食太急并没有收到应有的效果 !\n" NOR, me);
        	break;
        }
	me->start_busy(1);

        destruct(this_object());
        return 1;
}

