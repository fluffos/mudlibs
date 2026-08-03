
int accept_object(object me,object ob)
{
	object npc;
	int exp,sil,pot,s_exp;
	npc=this_object();
	if(!me->query_temp("zhu_sx/"+this_object()->query("s_flag"))) return 0;
    if(!ob->query("zhu_sx")) return 0;
	exp=(int)me->query("combat_exp",1);
	if(exp<200000)
	exp=me->query("max_pot")-30-random(5);
	else exp=250+random(10);
	if(exp<1000000)
	pot=me->query("max_pot")/3;
	else pot=me->query("max_pot")/2;
	sil=SONGXIN_JOB+me->query("max_pot")/5;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/3,sil/2);
	me->delete_temp("zhu_sx");
	me->delete_temp("dtsl_job");
	tell_object(me,this_object()->name()+"奖励了你"+""HIW""+chinese_number(exp)+""NOR""+"点经验值 "+""HIW""+chinese_number(pot)+""NOR""+"点潜能 "+MONEY_D->money_str(sil)+"\n");
	tell_object(me,"你的钱庄存款增加了！\n");
	return 1;
}