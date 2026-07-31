// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q;

	if ((int)me->query("neili") < 20 || !me->query_skill("force"))
		return notify_fail("你的内力不够。\n");

	q = ((int)me->query("eff_jingli") + (int)me->query_temp("apply/jingli")) - (int)me->query("jingli");
	if (q < 10)
		return notify_fail("你现在精力充沛。\n");
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("jingli", q);
	
        message_vision("$N长长地舒了一口气。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
