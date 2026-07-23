// /clone/drug/badan.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");

}

void create()
{
        set_name(RED"续命八丹"NOR, ({"ba dan", "badan", "dan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}

int do_eat(string arg)
{
       
        object me = this_player();
        if (!living(me)) return notify_fail("想当机吗？\n");
        if (!id(arg)) return 0;
if( me->query_condition("medicine")>0 )
{ message_vision(HIG"$N吃下一颗续命八丹，因为吃得太频繁，没有起到什么效果。\n", me);
me->apply_condition("medicine",30);
destruct(this_object());
return 1;
}
        message_vision(HIG"\n$N气喘嘘嘘的吃下一颗续命八丹，终于把命吊了回来。\n\n"NOR,me);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("eff_jing"));
me->apply_condition("medicine",30);
        destruct(this_object());
        return 1;
}
