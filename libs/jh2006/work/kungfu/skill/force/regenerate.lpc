// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q;

	if ((int)me->query("neili") < 20 || !me->query_skill("force"))
		return notify_fail("你的内力不够。\n");

	q = ((int)me->query("eff_jing") + (int)me->query_temp("apply/jing")) - (int)me->query("jing");
	if (q < 10) return notify_fail("你现在精神饱满。\n");
	n = 100 * q / me->query_skill("force");
	if (n < 20) n = 20;
	if ((int)me->query("neili") < n) {
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("jing", q);

	if (userp(me)) tell_object(me, "你深深吸了几口气，精神看起来好多了。\n");
	else message_vision("$N深深吸了几口气，精神看起来好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
