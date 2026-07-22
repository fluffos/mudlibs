// sserver.c

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
    int sz,k;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
    if( sz > 0 ) {
    k=random(sz);
if(!me || !enemy[k]) return 0;
if(environment(me)!=environment(enemy[k])) {
return 0; } else {
    return enemy[k];
}
}
	else return 0;
}
