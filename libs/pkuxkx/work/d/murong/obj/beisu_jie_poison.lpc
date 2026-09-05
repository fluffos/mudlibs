int update_condition(object me, int duration)
{
	if(duration<1)
	{
		if( me->query_temp("beisu_du") )
		{
			me->set_temp("beisu_du", 0);
			tell_object(me, "你的悲酥清风解药时间已过。\n");
		}
		return 0;
	}
	me->apply_condition("beisu_jie_poison", duration-1);
	return 1;
}