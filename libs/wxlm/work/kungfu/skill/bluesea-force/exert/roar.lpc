// roar.c 沧浪一笑



inherit F_CLEAN_UP;

string query_name() { return "沧海"ZJBR"一笑"; }

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	skill = me->query_skill("bluesea-force")*2;

	me->add("neili", -100);
	me->receive_damage("qi", 10);

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能攻击别人! \n");

	me->start_busy(5);
	message_combatd(HIC "$N" HIC "纵声长笑，声音远远的传了开去，犹如波浪声一般此起彼伏！"NOR"\n", me);

	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if (! ob[i]->is_character() || ob[i] == me)
			continue;
		if (! playerp(me) && !playerp(ob[i]))
			continue;

		if (skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2)
			continue;

		if (userp(ob[i]) && !ob[i]->die_protect(me))
			continue;

		me->want_kill(ob[i]);
		me->fight_ob(ob[i]);
		ob[i]->kill_ob(me);
		
		damage = skill;
		if (damage > 0)
		{
			ob[i]->set("last_damage_from", me);
			ob[i]->receive_damage("qi", damage, me);
			tell_object(ob[i], "你只觉得眼前一团漆黑，阵阵晕眩......\n");
		}
	}
	return 1;
}
