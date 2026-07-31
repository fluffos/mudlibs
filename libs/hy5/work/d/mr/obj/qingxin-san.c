// /u/beyond/obj/qingxin-san.c 玉露清新散
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
	set_name("玉露清新散", ({"qingxin san", "san", }));   
	set("no_drop",1);
	set("no_get",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗闪闪发亮的玉露清新散，此药乃慕容之珍药，提高体力，灵效无比。\n");
		set("value", 10000);     
		set("no_drop",1);
	set("no_get",1);
		
	}

	set("murong",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query_skill_mapped("force") != "shenyuan-gong")
	{
		if (me->add("max_jing", -20) < 0)
			me->set("max_jing", 0);
		if (me->add("eff_jing", -20) < 0)
			me->set("eff_jing", 0);
		message_vision(HIR "$N吃下一颗玉露清新散，只觉得肝肠寸断，原来所练内功不符，反而大损体力！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		if (me->add("max_jing", -1) < 0)
			me->set("max_jing", 0);
		if (me->add("eff_jing", -1) < 0)
			me->set("eff_jing", 0);
		message_vision(HIR "$N吃下一颗玉露清新散，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		me->add("max_jingli", 1);
		me->add("eff_jingli", 1);
		message_vision(HIY "$N吃下一颗玉露清新散，只觉得身轻如燕，体力顿然提高！\n" NOR, me);
		me->apply_condition("bonze_drug", 60);
	}
	
	destruct(this_object());
	return 1;
}
