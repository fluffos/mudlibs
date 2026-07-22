// /u/jpei/thd/obj/liuren-wan.c 六壬集气丸 

#include <ansi.h>

inherit ITEM;

void setup() {}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("六壬集气丸", ({"liuren wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗淡绿色的丸药，隐隐透出清香。\n");
		set("value", 100);
                set("no_drop", 1);
                set("no_get", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if ( me->query("family/family_name") != "桃花岛" )
	{
	/*	if (me->add("max_neili", -10) < 0)
			me->set("max_neili", 0);
		message_vision(HIR "$N服下一颗六壬集气丸，只觉得肝肠寸断，原来竟是一颗假药！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
	*/
		message_vision(HIR "所练内功不符，这药你不能随便吃！\n" NOR, me);
		return 1;
	}
	if ( (int)me->query("max_neili" ) < 400) {
		message_vision(HIR "功力不够，灵药吃了有害无宜。\n" NOR, me);
		return 1;
	}
	

	if ( (int)me->query_condition("medicine" ) > 0 )
	{
		me->add("max_neili", -10);
			me->set("neili", 0);
		message_vision(HIR "$N服下一颗六壬集气丸，只觉得头重脚轻，摇摇欲倒，原来灵药服食太急太多，药效适得其反！\n" NOR, me);
	}
            else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N吃下一颗六壬集气丸，只觉得药性平平，难以再提高你的修为了！\n" NOR, me);
        }
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N服下一颗六壬集气丸，只觉得体内真力鼓荡，内力修为小有进益！\n" NOR, me);
		me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
