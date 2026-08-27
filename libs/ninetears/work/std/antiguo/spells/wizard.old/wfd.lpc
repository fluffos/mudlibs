/* damage throw fixups , based on prime stat and save type */


int wiz_fix_damage(object caster,object victim,int damage,string save)
{
	 /* caster damage 18 is nominal prime stat */
	 damage = (damage * caster->query_int())/18;
	 /* defender saving throws */
	 damage = (damage * (100 - (int)victim->query_property(save)))/100;
	 return damage;
}

int cleric_fix_damage(object caster,object victim,int damage,string save)
{
	 damage = (damage * caster->query_wis())/18;
	 damage = (damage * (100 - (int)victim->query_property(save)))/100;
	 return damage;
}

