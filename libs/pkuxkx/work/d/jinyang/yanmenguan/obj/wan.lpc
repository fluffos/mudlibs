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
        set_name(HIR"通天草"NOR, ({"tongtian cao", "cao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一棵通天草，疗伤灵药。\n");
                set("value", 5);
				set("yanmen_item",1);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();
	    if (!id(arg))  return notify_fail("你要吃什么？\n");
	    {
                if (me->query("eff_qi")>me->query("max_qi")*4/5)
                {
                    tell_object(me,"你的伤势不重，不要糟蹋灵丹了。\n");
                    return 1;
                }
                fw = (int)me->max_food_capacity();
                me->set("food", fw);
                fw = (int)me->max_water_capacity();
                me->set("water", fw);
	 	        me->set("eff_qi",me->query("max_qi")/10*(8+random(3)));
                me->set("qi",me->query("eff_qi"));
                message_vision(HIG"$N吃下一棵通天草，顿时只觉伤势好了些许！\n"NOR,me);
		        me->start_busy(1);
        	    destruct(this_object());
	    }
	    return 1;
}

