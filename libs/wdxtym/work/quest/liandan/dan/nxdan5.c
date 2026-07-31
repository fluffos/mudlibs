//Cracked by Kafei
// /d/changbai/renshen.c 人参

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
        set_name("人参", ({"ren shen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("long", "这是一株沾满山泥的长白山人参。\n");
                set("value", 10000);
                set("medicine", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");
        if ( (int)me->query_condition("medicine") > 0 ) {
                me->add("eff_jingli", -1);
                me->add("max_jingli", -1);
                message_vision(HIR "$N吃下一株人参，只觉得头重脚轻，火气翻腾，原来服食太多，药效适得其反！\n" NOR, me);
                call_out("destroy", 0);
                return 1;
        }

        if( !me->query_temp("cbs/renshen") ) {
                me->add_temp("apply/constitution", 5);
                me->set_temp("cbs/renshen", 1);
        }

        me->add("jingli", 150);
        me->add("neili", 150);

        message_vision(HIG"$N吃下一株人参，只觉得浑身一股热气兜底冒了上来 !\n" NOR, me);

        me->apply_condition("medicine", 
                this_player()->query_condition("medicine")+30);

        call_out("destroy", 0);
        return 1;
}

void destroy()
{
        destruct(this_object());
}

