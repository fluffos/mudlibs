//Cracked by Roath
//skills action include func
//wzfeng 2002 1 xkx
//dodge_min set rang for dodge . 
mapping query_skill_action(int dodge_lim_min,int dodge_lim_max,int parry_lim_min,int parry_lim_max,
						int force_lim_min,int force_lim_max,int damage_lim_min,int damage_lim_max,
						int skills_lim,mapping* skill_action,int skills_lvl)
{
	int skills_rate;
	mapping act;
	skills_rate=skills_lvl*10/skills_lim;
//	printf("skills_lvl=%d\tskills_lim=%d",skills_lvl,skills_lim);

	if(skills_rate>10)
		skills_rate=10;

//	printf("skills_rate=%d",skills_rate);

	act=skill_action[random(sizeof(skill_action))];
	act["dodge"]=(dodge_lim_max-dodge_lim_min)*skills_rate/10+dodge_lim_min;
	act["parry"]=(parry_lim_max-parry_lim_min)*skills_rate/10+parry_lim_min;
	act["force"]=(force_lim_max-force_lim_min)*skills_rate/10+force_lim_min;
	act["damage"]=(damage_lim_max-damage_lim_min)*skills_rate/10+damage_lim_min;
	return act;




}
