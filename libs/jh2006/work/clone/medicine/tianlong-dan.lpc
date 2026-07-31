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
	set_name("天龙丹", ({"tianlong dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗金黄色圆溜溜的药丸，散发一股清香，正是灵药天龙丹。\n");
		set("value", 100);
                set("no_drop", 1);
                        set("no_get", 1);
                        set("no_give", 1);
                set("tianlongsi",1);    
                }
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query_skill_mapped("force") != "qiantian-yiyang" )
      {
       if ( me->query_skill_mapped("force") != "kurong-changong" )

	{
	/*
		if (me->add("max_neili", -10) < 0)
			me->set("max_neili", 0);
		message_vision(HIR "$N吃下一颗天龙丹，只觉得肝肠寸断，原来所练内功不符，反而大损真元！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
	*/
		write("所练内功不符，这药你还是不要吃的好！\n");

		return 1;

	}
            }  

         if ( me->query("max_neili") < 450 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗天龙丹，只觉得头重脚轻，摇摇欲倒，原来功力不够，药效适得其反！\n" NOR, me);
	}
	else if ( (int)me->query_condition("medicine" ) > 0 )
	{
		            me->add("max_neili", -10);
			me->set("neili", 0);
		message_vision(HIR "$N吃下一颗天龙丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}

	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N吃下一颗天龙丹，只觉得体内真力源源滋生，遍布奇筋八脉，全身功力顿然提高！\n" NOR, me);
		me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
