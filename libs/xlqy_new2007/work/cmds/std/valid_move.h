// mon 9/25/97

int valid_move(object me)
{
        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
	if(me->check_look() == -1&&!random(13)&&userp(me))
	{
		me->receive_damage("kee",13);
		me->start_busy(1);
		 return notify_fail("太暗了，你不小心被什么东西绊了一下，差点摔个大跟头。\n");
		
	}
	if(!random(200449))
	{
		me->start_busy(1);
		 return notify_fail("你不小心被什么东西绊了一下，差点摔个大跟头。\n");	
		
	}
        if( me->query_temp("no_move") )
//              return notify_fail("你被定住了，哪里动得了！\n");
// mon 8/11/97. change the fail message since not only dingshen
// can lead to no_move.
                return notify_fail("你现在不能移动！\n");
		if( me->query("名人堂人物") )
			return notify_fail("你现在是名人了，不能随便走动，以防不测!:)\n");
		//bugbug,2002-4-27
        return 1;
}
