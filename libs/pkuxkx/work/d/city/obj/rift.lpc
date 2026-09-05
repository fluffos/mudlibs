//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(HIG"竹筏"NOR, ({ "zhu fa", "rift"}));
	set_weight(1000000);
	set("long", "一条刚刚由竹子绑起来的竹筏。\n");
	set("unit", "条");
	set("value", 1);
	setup();
}

void init()
{
	add_action("do_push", ({ "tui" }));
	add_action("do_chai", ({ "chai" }));
}

int do_push()
{
	object me = this_player();
	object curroom=load_object("/d/city/grass");
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着呐！\n");
	if (environment() != curroom)
	return notify_fail("你站在竹筏上，再推就要翻了。\n");
	else
	{
		if((int)me->query("neili")<400)
		{
			message_vision(WHT"$N内力不足，试了一下，竹筏纹丝不动。\n"NOR, me);
			me->add_busy(random(3));
		}
		else
		{
			message_vision(HIB"$N大喝一声，突然发力，将竹筏推向南边。\n"NOR, me);
			me->add("neili",-400);
			me->add_busy(random(3));
			me->set_temp("skf/qingbing3",1);
			call_out("southward", 3, me);
		}
		return 1;
	}
}
int southward(object me)
{
	object nm;
	if (nm=me->query_temp("skf/nanmin"))
	{
		nm->move("/d/city/changjiang");
	}
	this_object()->move("/d/city/changjiang");
	me->move("/d/city/changjiang");
	tell_object(me,"竹筏渡过池塘，众人来到一条大江前。\n");
	return 1;
}
int do_chai(string arg)
{
	object me=this_player();
	object ob=this_object();
	object zl;
	if (!arg||(arg!="zhu fa" && arg!="zhufa" && arg!="fa" && arg!="rift" && arg!="竹筏"))
	return notify_fail("你要拆什么？\n");
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	if (!me->query_temp("skf/zhufapass"))
	return notify_fail("你没事拆竹筏干嘛？\n");
	if((int)me->query("neili")<400)
	return notify_fail("你体力太差，解不开竹筏上的绳结。\n");
	message_vision("$N手下一加力，竹筏上的麻绳寸寸断裂。\n", me);
	me->add("neili",-400);
	me->add_busy(random(3));	
	zl=new("/d/city/obj/bamboo2");
	zl->move(me);
	destruct(ob);
	return 1;
}