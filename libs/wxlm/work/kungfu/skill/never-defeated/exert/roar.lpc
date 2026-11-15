// roar.c 天地长吟



inherit F_CLEAN_UP;

string query_name() { return "天地"ZJBR"长吟"; }

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	skill = me->query_skill("never-defeated")*2;

	me->add("neili", -100);
	me->receive_damage("qi", 10);

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能攻击别人! \n");

	me->start_busy(5);
	message_combatd(HIY "$N" HIY "纵声长啸，真力贯注、威震百里，发人耳聩！"NOR"\n", me);

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
			if ((int)ob[i]->query("neili") < skill * 2)
				ob[i]->receive_damage("qi", damage, me);
			tell_object(ob[i], "你只觉得眼前一片模糊，眼前一阵阵发黑......\n");
		}
	}
	return 1;
}
