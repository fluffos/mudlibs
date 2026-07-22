void init()
{
        object me,ob,obj,env;
	string way;
	int i,j,count;
		me = this_player();
		way = base_name(environment(me));
		count = random(3)+1;

		if( !me->query("evil_mob") && !me->query_temp("evil_no_damage") )
		{
		        me->receive_damage("gin",250);
        		me->receive_damage("kee",250);
	        	me->receive_damage("sen",250);
	        	COMBAT_D->report_status(me,1);
		}
		if( me->query_temp(way) != way && !me->query("evil_mob") && !me->query_temp("evil_no_enemy") )
		{
			me->set_temp(way,way);
			if( !present("fly-bird",environment(me)) && !present("fly-worm",environment(me)) && !present("fly-spider",environment(me)) && !present("spider-girl",environment(me)) && !present("evil-ghost",environment(me)) && !present("evil-clever",environment(me)) )
			{
				for( i = 0 ; i < count ; i++ )
				{
					j = random(12)+1;
					obj = new(__DIR__"npc/bug"+j);
					obj->move(environment(me));
					obj->kill_ob(me);
				}
			}
		}
	return ;
}
