int valid_leave(object me,string dir)
{
	if (me->query_skill("dodge",1)>=10)
	{
		if( random(me->query_skill("dodge",1))==0 )
		{
			me->start_busy(random(2)+1);
			return notify_fail("你走累了，需要休息一下！\n");
		}
		else return 1;
	}
	else return 1;
}
