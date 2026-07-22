int is_sea(){return 1;}

mixed valid_move(object me)
{
	object npc;
	if( !userp(me) || !clonep(this_object())
	 || me!=query("owner") )
		return 0;
	if( !environment(me) || environment(me)->is_sea() )
		return 0;	
	if( !me->query_temp("pendding/wzg_apprentice") )
	{	
		if( !me->query_temp("pendding/fc_seaask") )
			return 0;
		if( !me->query_temp("pendding/fc_visite")
    	 	 || me->is_knowing("puti_panlong") )
    	 		return 0;
    		if( me->query_temp("pendding/fc_visite_wzg") )
    			return 0;
    		if( me->query_temp("pendding/fc_visite_sea") )
    			return 0;	
    	}		
    	return "还是安心跟随八仙遨游东海吧，免得出了纰漏。\n";	
}

void remove_room()
{
	object *inv = all_inventory();
	int i;
	for(i=0;i<sizeof(inv);i++)
	{
		if( userp(inv[i]) )
		{
			message_vision("\n一道大浪打来，$N闪避不及，被巨浪卷入海中，顿时无影无踪！\n\n",inv[i]);
			inv[i]->move("/d/changan/eastseashore");
			message_vision("\n远处一道巨浪卷着$N打在了岸边的礁石之上！\n\n",inv[i]);
			inv[i]->unconcious();
		}
	}
	REMOVE_D->add_room(this_object(),1);
}
