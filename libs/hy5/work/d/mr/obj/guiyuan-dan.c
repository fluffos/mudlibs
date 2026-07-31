// /u/beyond/mr/obj/guiyuan.c 归元丹
// this is made by beyond
// update 1997.6.23
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
	set_name("归元丹", ({"guiyuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗莹白溜圆的归元丹。\n");
		set("value", 100);
                   set("murong",1);    
                   set("no_drop",1);    
                   set("no_get",1);    
                   set("no_give",1);    
                }
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query_skill_mapped("force") != "shenyuan-gong" )
	{
		if (me->add("max_neili", -10) < 0)
			me->set("max_neili", 0);
		message_vision(HIR "$N吃下一颗归元丹，只觉得肝肠寸断，原来所练内功不符，反而大损真元！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

             else if ( (int)me->query_condition("medicine") > 0 )
	{
		       me->add("max_neili", -5);
			me->set("neili", 0);
		message_vision(HIR "$N吃下一颗归元丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
         else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N吃下一颗归元丹，只觉得药性平平，难以再提高你的修为了！\n" NOR, me);
        }
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N吃下一颗归元丹，只觉得体内真力源源滋生，遍布奇筋八脉，全身功力顿然提高！\n" NOR, me);
   me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
