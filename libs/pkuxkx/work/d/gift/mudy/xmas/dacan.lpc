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
        set_name(HIR"圣诞大餐"NOR, ({"shengdan dacan", "shengdan", "dacan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
				set("no_give",1);
				set("no_get",1);
				set("no_sell",1);
                set("unit", "份");
                set("long", "这是mudy为众玩家准备的圣诞大餐！\n");
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
	object me=this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
		if(me->query("mudyxmas/dacan"))
		{
			me->add("max_jingli",5);
			me->add("max_neili",5);
			me->set("eff_jing",me->query("max_jing"));
			me->set("jing",me->query("max_jing"));
			me->set("eff_qi",me->query("max_qi"));
			me->set("qi",me->query("max_qi"));
			me->add("neili",50000);
			me->add("jiali",me->query("max_neili"));
        message_vision(HIG "$N吃下一份mudy为你准备的圣诞大餐感到全身无比通畅!\n" NOR, me);
		tell_object(me,HIW"你感到你的内力充盈！\n你的最大精力有所上升！\n你的最大内力有所上升！"NOR);
		destruct(this_object());
		return 1;
		}
		me->add("mudyxmas/dacan",1);
        me->add("max_jingli", 100);
		me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->add("neili",1000000);
		me->add("jiali",me->query("max_neili"));
		me->add("spi",1);
        message_vision(HIG "$N吃下一份mudy为你准备的圣诞大餐感到全身无比通畅!\n" NOR, me);
		tell_object(me,HIW"你感到你的内力充盈！\n你的最大精力上升１００点！\n你的灵性增加了！\n"NOR);

       	destruct(this_object());
       	return 1;
}
