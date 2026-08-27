// sserver.c

//inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	int sz;
	object *enemy,victim,defender;
	if(!me) return 0;
	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) victim=enemy[random(sz)];
	else return 0;
	
	if(!victim) return 0;
	if(environment(victim)!=environment(me)) return 0;
	if(defender=victim->query_temp("defender"))
	{
	 if(environment(defender)==environment(me)
	    && defender->can_fight(me) ) return defender;
	}
	return victim;
}
