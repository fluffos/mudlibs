//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name("竹排", ({ "zhu pai", "rift"}));
	set_weight(1000000);
	set("long", "一条小竹排，只能坐上一个人。\n");
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
		{
			return notify_fail("你正忙着哪！\n");
        }
	if (environment() != curroom)
		{
		return notify_fail("你站在竹筏上，再推就要翻了。\n");
		}
	else
		{
			if((int)me->query("neili")<400)
				{
					message_vision("你内力不足，试了一下，竹筏纹丝不动。\n", me);
					me->add_busy(random(3));
				}
			else
				{
					message_vision("$N大喝一声，突然发力，将竹筏推向南边。\n", me);
					me->add("neili",-400);
					me->add_busy(random(3));
					call_out("southward", 3, me);
				}
			return 1;
		}
}
int southward(object me)
{
	int i;
	object* all = all_inventory(environment());
	for(i=0;i<sizeof(all);i++)
		{
			if(!objectp(all[i])) continue;
			if(!living(all[i])) continue;
			if(all[i]->query("skfleader")==me->query("id"))
			{all[i]->move("/d/city/changjiang");} 
		}
	this_object()->move("/d/city/changjiang");
	this_player()->move("/d/city/changjiang");
	tell_object(me,"竹筏渡过池塘，众人来到一条大江前。\n");
	return 1;
}
int do_chai(string arg)
{
	object me=this_player();
	object ob=this_object();
	object z1 = new("/d/city/obj/bamboo");
	object z2 = new("/d/city/obj/bamboo");
	if (!arg||arg!="rift")
		{
			return notify_fail("你要拆什么？\n");
		}
	else 
		{
			if (me->is_busy() || me->is_fighting())
				{
					return notify_fail("你正忙着哪！\n");
				}
			if (me->query_temp("zhufapass"))
				{
					if((int)me->query("neili")<400)
						{	
							message_vision("$N体力太差，解不开竹筏上的绳结。\n", me);
							me->add_busy(random(3));
						}
					else
						{
							message_vision("$N手下一加力，竹筏上的麻绳寸寸断裂。\n", me);
							me->add("neili",-400);
							me->add_busy(random(3));
							z1->move(me);
							z2->move(me);
							destruct(ob);
						}
				}
			else
				{
					return notify_fail("你没事拆竹筏干嘛？\n");
				}
		}
	return 1;
}