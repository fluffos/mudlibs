//Cracked by Kafei
// hulipi.c 狐狸皮

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
	set_name("狐狸皮", ({ "huli pi", "pi" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("unit", "张");
                set("long", "这是一张毛长寸许，柔软光滑的狐狸皮。\n");
	        set("value", 3000);
	        set("medicine", 1);
	}

	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

        me->add("food", 30);

        if ( (int)me->query_condition("medicine" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("medicine", 30);
                message_vision(HIR "$N吃下一张狐狸皮，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
                call_out("destroy", 0);
                return 1;
        }

        if( !me->query_temp("cbs/hulipi") ) {
                me->add_temp("apply/dexerity", 3);
                me->set_temp("cbs/hulipi", 1);
        }

        me->add("jingli", 300);
        me->apply_condition("medicine", 
        me->query_condition("medicine")+30);
        message_vision(HIY "$N吃下一张狐狸皮，只觉全身的精力都恢复了。\n" NOR, me);
        call_out("destroy", 0);
        return 1;
}

void destroy()
{
        destruct(this_object());
}

