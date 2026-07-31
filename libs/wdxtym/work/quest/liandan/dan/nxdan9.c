//Cracked by Kafei
// hugu.c 虎骨

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
	set_name("虎骨", ({ "hu gu", "gu" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("unit", "支");
                set("long", "这是一支老虎的胫骨，乃是极为珍贵的药材。\n");
	        set("value", 8000);
	        set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

        me->add("food", 40);

        if ( (int)me->query_condition("medicine" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("medicine", 30);
                message_vision(HIR "$N吃下一支虎骨，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
                call_out("destroy", 0);
                return 1;
        }

        if( !me->query_temp("cbs/hugu") ) {
                me->add_temp("apply/strength", 3);
                me->set_temp("cbs/hugu", 1);
        }

        me->receive_curing("qi", 200);
        me->set("qi", me->query("max_qi"));

        me->apply_condition("medicine", 
        me->query_condition("medicine")+30);
        message_vision(HIY "$N吃下一支虎骨，只觉得全身冒汗，爽快淋漓。\n" NOR, me);
        call_out("destroy", 0);
        return 1;
}

void destroy()
{
        destruct(this_object());
}
