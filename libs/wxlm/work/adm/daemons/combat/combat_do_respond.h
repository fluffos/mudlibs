varargs string do_respond(object me, object target, int damage, int percent, mixed final)
{
	int armor;
	int wound;
	string msg;
	// Check the target's armor
	armor = target->query_temp("apply/armor");
	msg = "";
	while (damage > 0)
	{
		if (target->is_busy()) target->interrupt_me(target, 4 + random(4));

		if (damage > 400)
			damage = (damage - 400) / 4 + 300;
		else if (damage > 200)
			damage = (damage - 200) / 2 + 200;

		damage = damage*percent / 100;
		wound = damage;
		damage = COMBAT_D->calc_damage(me, target, damage);
		damage = target->receive_damage("qi", damage, me);

		if (target->query("character") == "光明磊落")
			wound -= wound * 20 / 100;

		if (wound > 0)
		{
			wound = COMBAT_D->calc_wound(me, target, wound);
			wound = target->receive_wound("qi", wound, me);
		}

		if (stringp(final))
		{
			msg += final;
			msg += HIG"$n对$N造成 "+damage+"/"+wound+" 点 "HIR+("反伤")+NOR"\n";
			msg += "( $N" + eff_status_msg(target->query("qi") * 100 / target->query("max_qi")) + ")\n";
		}

		break;
	}

	return msg;
}