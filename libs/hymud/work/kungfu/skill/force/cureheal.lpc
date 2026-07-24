// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	int j,n,q,agea,inta,dexa;
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	
	if ((int)me->query("neili") < 55)
		return notify_fail("你的内力不够。\n");
	j = (int)me->query("max_jing") - (int)me->query("jing");
	q = (int)me->query("eff_qi") - (int)me->query("qi");

	if (j < 10 && q < 10)
		return notify_fail("你现在不需要疗伤。\n");

if (j>=10)
{
	me->add("neili", -30);

q=(int)me->query_skill("force") / 2;

if (me->query("jing",1) <= me->query("max_jing",1)/2 )
if (userp(me))q=q+me->query("per")*15;

		dexa=me->query("age",1);
		if (dexa >30) dexa=30;
if (userp(me)) q=q+me->query("int")*dexa;

if (q>me->query("max_jing",1)) q=me->query("max_jing",1);

if (me->query("zhuanshen"))
q=q*2;

if (me->query("zhuanbest"))
q=q*2;

if (me->query("4zhuan"))
q=q*2;

if (q>me->query("max_jing",1)) q=me->query("max_jing",1);


if ((int)me->query("eff_jing") <= (int)me->query("max_jing"))
{
	me->add("eff_jing", q);	
	me->receive_heal("jing", q);
}
if ((int)me->query("jing") <= (int)me->query("eff_jing"))
{
	me->add("jing", q);	
}        message_combatd("$N深深吸了几口气，精神看起来好多了。\n", me);

}
q = (int)me->query("eff_qi") - (int)me->query("qi");
if (q>=10)
{
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

if (userp(me) && q>= 200000) q=200000;

if (q>= 200000) q=200000;
if (me->query("qi",1) <= me->query("max_qi",1)/2 )
if (userp(me)) q=q+me->query("con")*15;


		dexa=me->query("age",1);
		if (dexa >30) dexa=30;
if (userp(me)) q=q+me->query("int")*dexa;

if (q>me->query("max_qi",1)) q=me->query("max_qi",1);
	me->add("neili", -n);
	me->receive_heal("qi", q);
	
        message_combatd("$N深深吸了几口气，脸色看起来好多了。\n", me);

}
        me->set_temp("ishealnb",1);
        if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
}          