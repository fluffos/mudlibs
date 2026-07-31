// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	if (target != me) 
		return notify_fail("你只能用内功提振自己的精力。\n");

	if (me->query("gin") >= me->query("eff_gin"))
		return notify_fail("你现在精神很好。\n");

	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

	me->add("force", -20);
	me->receive_heal("gin", (int)me->query_skill("force") / 3);
	
        message_vision("$N深深吸了口气，手脚活动了几下，整个人看起来有活力多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

