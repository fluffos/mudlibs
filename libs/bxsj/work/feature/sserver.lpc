// sserver.c

inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int necessary(object ob)
{
	if(!ob) return 0;
	
	if(!living(ob)) return 0;
	
	//living(ob) && 			
	if (ob->query("qi") < 0 || ob->query("jing") < 0 || ob->query("jingli") < 0)
		return 0;
	if (ob->query("eff_qi")+ob->query_temp("apply/qi") < 0
		|| ob->query("eff_jing")+ob->query_temp("apply/jing") < 0)
		return 0;
	return 1;
}