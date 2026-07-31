//Cracked by Kafei
// xiongdan.c 熊胆

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
	set_name("熊胆", ({ "xiong dan", "dan" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
        	set("long", "这是一颗比拳头还大的熊胆，遍体发出乌黑的亮光。\n");
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
        me->add("food", 50);

        if ( (int)me->query_condition("medicine" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("medicine", 30);
                message_vision(HIR "$N吃下一颗熊胆，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
                call_out("destroy", 0);
                return 1;
        }

        if( !me->query_temp("cbs/xiongdan") ) {
                me->add_temp("apply/damage", 30);
                me->set_temp("cbs/xiongdan", 1);
        }

        me->add("neili", 200);
        me->apply_condition("medicine", 
        me->query_condition("medicine")+30);
        message_vision(HIY "$N吃下一颗熊胆，只觉得丹田充满真气混身有劲。\n" NOR, me);

//      destruct(this_object());
        call_out("destroy", 0);
        return 1;
}

void destroy()
{
        destruct(this_object());
}


