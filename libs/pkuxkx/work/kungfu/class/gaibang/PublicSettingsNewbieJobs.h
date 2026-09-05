#include <ansi.h>
#define INC_BONUS 15 //新手任务提速10倍，Zine 2014/1/18
// 重新修订的新手任务公共设置放在第一个修改的丐帮任务下
int BuffInc()
{
	return INC_BONUS;
}
int GetSelfFactor(object me,string type,string ComMark,string ComMark2)
{
	int result=-1;
	if (type=="punish")
	{
		if (me->query("combat_exp")<10000)
		result=8;
		else if (me->query("combat_exp")<30000)
		result=12;
		else if (me->query("combat_exp")<55000)
		result=14;
		else if (me->query("combat_exp")<85000)
		result=16;
		else if (me->query("combat_exp")<120000)
		result=18;
		else
		result=4;
	}
	if (type=="bonus")
	{
		if (me->query("combat_exp")>=1000000)
		result=1;
		else if (me->query("combat_exp")<10000)
		result=6;
		else if (me->query("combat_exp")<30000)
		result=12;
		else if (me->query("combat_exp")<55000)
		result=14;
		else if (me->query("combat_exp")<85000)
		result=16;
		else if (me->query("combat_exp")<120000)
		result=18;
		else if (me->query("combat_exp")<150000)
		result=10;
		else 
		{
			if (me->query(ComMark)||me->query(ComMark2)||ComMark=="NoNeed")
			result=1;
			else
			result=4;
		}
		result*=INC_BONUS;
		result=result*4/5+random(result/5);
		return result;
	}
	return result;
}
void SkillBonus(object me,string skill,int SkLimit)//SkLimit是奖励下陷条件
{
	if (SkLimit>100)
	SkLimit=100;
	if (me->query_skill(skill,1)<SkLimit)
	{
		me->set_skill(skill,me->query_skill(skill,1)+1);
		tell_object(me,HIC+"你被奖励了一级『"+CHINESE_D->chinese(skill)+"』！\n"+NOR);
	}
}

void IndeedModify(object me,int exp,int pot,int rep,int neili,int jingli,int score,string Mark,string FamilyMark,int flag,string completeness)
{
	exp=REWARD_D->add_exp(me,exp*flag);
	me->add("exp/"+Mark, exp);
	pot=REWARD_D->add_pot(me,pot*flag);
	me->add("pot/"+Mark, pot);
	rep=REWARD_D->add_rep(me,rep*flag);
	me->add("rep/"+Mark, rep);
	if (flag<0)//负操作,punish
	{
		tell_object(me,WHT+"因为没有完成这项任务，你被扣除了：\n");
		if (exp)
		tell_object(me,"\t"+chinese_number(-exp)+"点经验；\n");
		if (pot)
		tell_object(me,"\t"+chinese_number(-pot)+"点潜能；\n");
		if (rep)
		tell_object(me,"\t"+chinese_number(-rep)+"点江湖声望。\n"+NOR);
		if (me->query("combat_exp")<0)
		me->set("combat_exp",0);
	}
	else
	{
		if (environment(this_object()))
		CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s在"+FamilyMark+"入门任务中获得经验：%d、潜能：%d、声望：%d。", me->name(), exp, pot, rep));
		else
		CHANNEL_D->do_channel(load_object(MONITOR_D), "sys_misc",sprintf("%s在"+FamilyMark+"入门任务中获得经验：%d、潜能：%d、声望：%d。", me->name(), exp, pot, rep));
		tell_object(me,HIR+"完成任务后，你被奖励了：\n");
		if (exp)
		tell_object(me,"\t"+chinese_number(exp)+"点经验；\n");
		if (pot)
		tell_object(me,"\t"+chinese_number(pot)+"点潜能；\n");
		if (rep)
		tell_object(me,"\t"+chinese_number(rep)+"点江湖声望。\n"+NOR);
		if (neili)
		{
			me->add("max_neili",neili);
			me->add("exercised_neili",neili);
			tell_object(me,HIR+"\t"+chinese_number(neili)+"点内力。\n"+NOR);
		}
		if (jingli)
		{
			me->add("max_jingli",jingli);
			tell_object(me,HIR+"\t"+chinese_number(jingli)+"点精力。\n"+NOR);
		}
		if (score)
		{
			me->add("score",1);
			tell_object(me,HIR+"办事认真，你被额外奖励了一点"+FamilyMark+"门忠。\n"+NOR);
		}
		tell_object(me,HIR+"你已经通过"+FamilyMark+"入门任务获得了"+chinese_number((int)me->query("exp/"+Mark))+"点经验，");
		if (completeness!="NoNeed")
		tell_object(me,"任务完成度为"+completeness+"%。\n"+NOR);
		else
		tell_object(me,"此任务为可选任务，不影响拜师。\n"+NOR);
	}
	return;
}