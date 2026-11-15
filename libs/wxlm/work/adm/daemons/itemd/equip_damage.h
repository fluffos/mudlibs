void receive_damage(object attack, object victim, string type, int damage)
{
	int damage_bonus;

	damage_bonus = attack->query("item_special_damage");//特攻宝石

	if (damage_bonus)
	{
		damage += damage_bonus;
	}

	damage = COMBAT_D->calc_damage(attack, victim, damage);
	victim->receive_damage(type, damage);
}

void receive_wound(object attack, object victim, string type, int damage)
{
	int damage_bonus;

	damage_bonus = attack->query("item_special_damage");//特攻宝石

	if (damage_bonus)
	{
		damage += damage_bonus;
	}


	damage = COMBAT_D->calc_wound(attack, victim, damage);
	victim->receive_wound(type, damage);
}
