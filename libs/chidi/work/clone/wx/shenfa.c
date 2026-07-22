// wxdan.c 洗髓丹
#include <ansi.h>
inherit ITEM;
void create()
{	set_name(HIC "身法丹" NOR, ({ "shenfa dan", "dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的身法丹，据说吃了可以临时增加1分钟的10倍身法。\n");
                set("value", 10000);
                set("merit", 100000);
               set("no_give", 1);
               set("no_drop", 1);
               set("no_put", 1);
               set("no_get", 1);
		set("unit", "颗");
	}
}
void init()
{
	add_action("do_eat", "eat");
}
int do_eat(string arg)
{ 
	object me;
	int tempwx;
	me = this_player();

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        if (me->query("sfdan", 1))		   
                return notify_fail("干什么？小心撑死你！\n");
       
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (random(10) >= 8)
            {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
            } else
        if (me->query("shenfa", 1))
            {
                tell_object(me, "不过你觉得好像没什么作用。\n");
            } else
        {       tempwx=(int)me->query_dex() * 10;
                tell_object(me, HIR "你感觉到身体轻了些。\n" NOR);
                me->set("sfdan", 1);
                me->add("dex",tempwx);
                me->set("shenfadan",tempwx);
                me->apply_condition("shenfa", 6);                
        }

        destruct(this_object());
	return 1;
}

void owner_is_killed() { destruct(this_object()); }