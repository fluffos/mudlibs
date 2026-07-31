

void copy_status(object me, object ob, int job_lvl)
{
	int qi, jing, neili, jingli, exp, lvl;
		
	lvl = me->query_temp("baozang/sk_lv");
	
	if (job_lvl == 1) 
		lvl /= 12;
	else
	if (job_lvl == 2) 
		lvl /= 10;
	else
	if (job_lvl == 3) 
		lvl /= 8;
	else
	if (job_lvl == 4) 
		lvl /= 6;
	
	if (lvl < 10)
		lvl =10;
	
	qi = me->query_temp("baozang/qi_lv") * job_lvl;
    	jing = me->query_temp("baozang/jing_lv") *1;
 	neili = qi / 2;
 	jingli = jing * 1;
 	exp = me->query_temp("baozang/exp_lv") * 1;

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
 	ob->set("neili", neili);
 	ob->set("max_jingli", jingli);
 	ob->set("eff_jingli", jingli);
 	ob->set("jingli", jingli);
 	ob->set("combat_exp", exp);
 //	ob->set("job_npc", 1);
 	me->set_temp("doing_job", 1);
}

void copy_skills(object me, object ob, int job_lvl)
{
	int i, j, lvl, jiali;
	mapping skills;
	string *sk;
	
	lvl = me->query_temp("baozang/sk_lv");
		
	if (job_lvl == 1) 
		lvl = lvl * 4 / 5;
	else
	if (job_lvl == 2) 
		lvl = lvl * 11 / 10;
	else
	if (job_lvl == 3) 
		lvl = lvl * 6 / 5;
	else
	if (job_lvl == 4) 
		lvl = lvl * 5 / 4;
	
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
	jiali = ob->query_skill("force", 1) / 5;
	if (jiali > 200) jiali = 200;
 	ob->set("jiali", jiali);
}
void do_copy_player(object me, object ob, int job_lvl)
{
	copy_status(me, ob, job_lvl);
	copy_skills(me, ob, job_lvl);
}

