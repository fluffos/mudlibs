// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q;

	if (me->query("neili") < 20 || !me->query_skill("force"))
		return notify_fail("你的内力不够。\n");
	q = me->query("eff_qi") + me->query_temp("apply/qi") - me->query("qi");
	if (q < 10)
		return notify_fail("你现在气力充沛。\n");
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if (me->query("neili") < n) {
		n = me->query("neili");
		q = me->query("neili") * me->query_skill("force") / 100;
	}

	me->add("neili", -n);
	me->receive_heal("qi", q);
	
	message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

	q *= sqrt(q);
	q /= 2000;
	me->improve_skill("force", q, 1);
        if (me->is_fighting())
		me->start_busy(1);

	return 1;
}
