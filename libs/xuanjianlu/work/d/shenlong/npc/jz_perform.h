int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object target=me->select_opponent();
	if(target->query("combat_exp") < 200000)
	return 0;

	if( me->query("qi",1) < 10 || me->query("jing",1) < 10 || me->query("jingli",1) < 10) 
       return 0;

	if( !me->query_temp("powerup") && me->query("combat_exp") > 100000 )
		command("exert powerup");


	if ( objectp(weapon) ) 
				{
			if ( weapon->query("skill_type") == "hook" && random(2) == 0 )
			return command("perform wucai"); 
			else if ( weapon->query("skill_type") == "sword" && random(2) == 0)
			return command("perform sanzhao");
				}

	else
				{
		me->map_skill("parry", "huagu-mianzhang");
		me->reset_action();

		switch( random(1) )
				{

			case 0:

			       return command("perform baliu");
				break;
			case 1:
				return command("perform juding");
				break;
				}
				}
	
}
