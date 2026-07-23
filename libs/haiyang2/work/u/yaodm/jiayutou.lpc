//jiuhuawan.c
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
        set_name(HIG"万年甲鱼头"NOR, ({"jiayu tou","tou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一个经多种名贵药材浸泡的甲鱼头，经秋香精心研制，
有滋阴状阳之奇效，据说，服用后一个晚上包睡百XX。\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if(arg=="tou") 
	{
                fw = (int)me->max_food_capacity();
              fw = fw*2;
                me->set("food", fw);
                me->set("water", fw);
                me->set("eff_jing",me->query("max_jing")*1);
                me->set("eff_qi",me->query("max_qi")*1);
                me->set("jing",me->query("max_jing")*2);
                me->set("qi",me->query("max_qi")*2);
                me->set("neili",me->query("max_neili")*2);
message_vision(HIG"$N吃下一个万年甲鱼头丸，感到浑身燥热，不由的开始留意起异性来了！\n"NOR,me);
		me->start_busy(1);
        	destruct(this_object());
	}
	return 1;
}

