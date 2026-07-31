// refresh.c

//inherit SSERVER;

int exert(object me, object target)
{
	if (target != me) 
		return notify_fail("你只能用内功收回自己的心神。\n");

	if (me->query("sen") >= me->query("eff_sen"))
		return notify_fail("你现在神气很好。\n");

	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

	me->add("force", -20);
	me->receive_heal("sen", (int)me->query_skill("force") / 3);
	
        message_vision("$N略一凝神，吸了口气，精神看起来清醒多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

