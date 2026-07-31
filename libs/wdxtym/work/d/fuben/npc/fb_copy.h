
void copy_status(object me, object ob, int job_lvl)
{
	int qi, jing, neili, jingli, exp, lvl;

	lvl = (100+job_lvl)/100;
	qi = me->query_temp("baozang/qi_lv")*lvl;
    	jing = me->query_temp("baozang/jing_lv") *lvl;
 	neili = me->query_temp("baozang/neili_lv")*lvl;
 	jingli = jing * lvl;
 	exp = me->query_temp("baozang/exp_lv") * lvl;

	ob->set("str", 30);
	ob->set("con", 30);
	ob->set("dex", 30);
	ob->set("int", 30);
 	ob->set("max_qi", qi);
	ob->set("eff_qi", qi);
	ob->set("qi", qi);
	ob->set("max_jing", jing);
	ob->set("eff_jing", jing);
	ob->set("jing", jing);
 	ob->set("max_neili", neili);
 	ob->set("neili", neili*2);
 	ob->set("max_jingli", jingli);
 	ob->set("eff_jingli", jingli);
 	ob->set("jingli", jingli);
 	ob->set("combat_exp", exp);
 	me->set_temp("doing_job", 1);
}

void copy_skills(object me, object ob, int job_lvl)
{
	int i, j, lvl;
	mapping skills;
	string *sk;

	lvl = me->query_temp("baozang/sk_lv");

	lvl = lvl + lvl*job_lvl/100;	
	if (lvl < 100)
		lvl =100;
	
	skills = ob->query_skills();
	if (mapp(skills))
	{
		sk = keys(skills);
		j = sizeof(sk);
		for (i = 0;i < j;i ++)
			skills[sk[i]] = lvl;
	}
	ob->set("apply/damage", lvl/6);
	ob->set("apply/unarmed_damage", lvl/6);
 	ob->set("jiali", lvl/2);
}
void do_copy_player(object me, object ob, int job_lvl)
{
	copy_status(me, ob, job_lvl);
	copy_skills(me, ob, job_lvl);
}

