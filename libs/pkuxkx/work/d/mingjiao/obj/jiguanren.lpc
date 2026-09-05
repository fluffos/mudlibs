//机关人，给明教增加一个练dagger的途径
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("机关人", ({"jiguan ren", "jiguan", "ren"}));
	set_weight(500);
	if( clonep() )
	set_default_object(__FILE__);
	else 
	{
		set("unit", "个");
		set("long","这是明教前辈制作的机关人，用以提高门下后辈的刺击之术。你可以拨动(bo)它试试。\n");
		set("value", 0);
        set("material","steel");
	}
	set("no_get","这个机关人比你还大，怎么拿得起来呢？\n");
	setup();
}


void init()
{
	add_action("do_bo", "bo");
}
int improve(object me)
{
	object ob=this_object();
	if (!me)
	return 1;
	if (environment(me)!=environment(ob))
	return 1;
	message_vision("$N像真人一般，栩栩如生的动了起来。$n从中学到了一些刺击格斗的窍门。\n",ob,me);
	me->improve_skill("dagger", 3*(int)me->query_skill("dagger", 1)+random((int)me->query_skill("dagger", 1)));
	if (me->query_skill("dagger",1)<50)//对于低级别的补偿
	me->improve_skill("dagger", 2*(int)me->query_skill("dagger", 1));
	if (me->query("family/family_name")=="明教")//对于明教弟子的优惠
	me->improve_skill("dagger", 2*(int)me->query_skill("dagger", 1));
	return 1;
}
int do_bo()
{
	object me=this_player(),ob=this_object();
	int i, jing_cost, qi_cost;
	jing_cost = 1200 / (int)me->query("int");
	qi_cost = 1000 / (int)me->query("int");
	if(((int)me->query("jing") <= jing_cost+100) || ((int)me->query("qi") <= qi_cost+100))
	{
		return notify_fail("你现在精气不足，拨不动机关人。\n");
	}
	if (me->is_busy()||me->is_fighting())
	{
		return notify_fail("你现在正忙着呢。\n");
	}
	if (!me->query_skill("dagger"))
	{
		return notify_fail("你完全不会使用匕首的方法，对着机关人也是白练。\n");
	}
	if (me->query_skill("dagger",1)>150)
	{
		return notify_fail("你从机关人身上已经无法学到任何有价值的东西了。\n");
	}
	message_vision("$N拨动$n，$n缓缓动了起来。\n", me,ob);
	me->add("jing",-jing_cost);
	me->add("qi",-qi_cost);
	me->add_busy(4);
	call_out("improve",4,me);
	return 1;
}
