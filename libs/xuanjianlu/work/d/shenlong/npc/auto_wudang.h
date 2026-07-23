
int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if( !me->query_temp("taiji") && random(3) ==1)
		command("exert taiji");

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" && (int)me->query_skill("taiji-jian", 1) > 200 && random(2) == 1)
			return perform_action("sword.chan");
		else return perform_action("sword.shenmen");

	}
	else return perform_action("cuff.luanhuan");
}
