

void join_fight( object me )
{
	object ob = this_object() , *all = me->query_enemy();
	int i;
	for( i = 0 ; i < sizeof(all) ; i ++ ) {
		ob->kill_ob( all[i] );
		all[i]->kill_ob( ob );
	}
}
