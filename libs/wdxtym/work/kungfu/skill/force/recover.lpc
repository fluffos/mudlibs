// recover.c

int exert(object me, object target)
{
	int n, q;

	if (me != target)
		return notify_fail("你只能用内功调匀自己的气息。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够。\n");

	q = (int)me->query("eff_qi") - (int)me->query("qi");
	if (q < 10)
		return notify_fail("你现在气力充沛。\n");
	if (me->query_skill("force")<500) 
          n = q * 100 / me->query_skill("force");
      else n = q / 5 - q * me->query_skill("force")/20000;
	if (me->query("breakup"))
		n = n * 8 / 10;
	if (n < 20)
		n = 20;

	if ((int)me->query("neili") < n)
	{
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("qi", q);
	
	if (me->is_fighting())
	message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);
        else write("你深深吸了几口气，脸色看起来好多了。\n");

	if (me->is_fighting() && ! me->query("special_skill/self"))
		me->start_busy(2);
	
	return 1;
}
