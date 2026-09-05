#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "gmnewbiejob"
#define FamilyMark "古墓派"
#define ComMark "NoNeed"
int CalcResult(object me,int Value)
{
	if (me->query("exp/"+MARK)>400000)
	Value/=3;
	if (me->query("exp/"+MARK)>1000000)
	Value=10;
	return Value*BuffInc()/6;
}
string completeness(object me)
{
	return "NoNeed";
}
int SilentReward(object me,int score,int neili,int jingli)
{
	if (!score&&!neili&&!jingli)
	return 1;
	tell_object(me,HIR+"你被奖励了：\n");
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
	return 1;
}
int bonus(object me,int flag,int exp,int pot,int rep,string msg)
{
	//flag 1: caodi3,2:ceshi, 3:duandi, 4:duandi2, 5:caoping, 6:longer
	int BaseValue,neili,jingli,score;
	string percent,skill="";
	if (flag==1||flag==2||flag==3||flag==4||flag==5)//simply add exp pot and rep,without any notice. Rewarding msg has been sent during the job process.
	{
		exp=CalcResult(me,exp);
		pot=CalcResult(me,pot);
		rep=CalcResult(me,rep);
		exp = REWARD_D->add_exp(me,exp);
		pot = REWARD_D->add_pot(me,pot);
		rep = REWARD_D->add_rep(me,rep);
		me->add("exp/"+MARK,exp);
		me->add("pot/"+MARK,pot);
		me->add("rep/"+MARK,rep);
		msg=replace_string(msg,"EXP",chinese_number(exp));
		msg=replace_string(msg,"POT",chinese_number(pot));
		msg=replace_string(msg,"REP",chinese_number(rep));
		tell_object(me,msg);
		if (flag==2)
		{
			if (!random(10))
			score=1;
			if (random(100)>25 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=3500)
			neili=1+random(2);
			if (random(100)>35 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=7500)
			jingli=2+random(2);
			SilentReward(me,score,neili,jingli);
			if (!random(6))
			{
				SkillBonus(me,"yunu-xinfa",30);
				return 1;
			}
			if (!random(6))
			SkillBonus(me,"force",30);
		}
		return 1;
	}
	
	exp=CalcResult(me,exp);
	pot=CalcResult(me,pot);
	rep=CalcResult(me,rep);
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	return 1;
}   

