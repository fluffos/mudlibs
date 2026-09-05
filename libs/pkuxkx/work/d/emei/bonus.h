//峨眉奖惩文件 Zine
#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "emnewbiejob"
#define FamilyMark "峨嵋派"
#define ComMark "emeinewbiejobdone"
int CalcResult(object me,string Type,string ValueType)
{
	int BaseValue,TaskFactor;
	if (Type=="punish")
	{
		BaseValue=(random(5)+6)*GetSelfFactor(me,"punish",ComMark,ComMark);
	}
	if (Type=="bonus")
	{
		TaskFactor=this_object()->query("bonus");
		if (!TaskFactor)
		TaskFactor=2+random(2);
		if (TaskFactor==1&&me->query("combat_exp")>7000)
		TaskFactor=1+random(2);
		BaseValue=TaskFactor*GetSelfFactor(me,"bonus",ComMark,ComMark)*5+(20+random(20))*TaskFactor;
		if (me->query_temp("emnewbiejob/qingjie/robot")>1)
		BaseValue/=(int)me->query_temp("emnewbiejob/qingjie/robot");
	}
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	return 1+random(BaseValue*3/4);
	if (ValueType=="rep")
	return 1+random(BaseValue/4);
}
string completeness(object me)
{
	float percent;
	if (me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("exp/"+MARK)>1000)
	{
		me->set(ComMark,1);
        tell_object(me,BLINK+HIW+"你似乎已经可以掌握峨眉武功的真谛了，去找周芷若和灭绝掌门指点一下吧，静迦和静闲好像也在找你。\n"+NOR);
	}
	if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("exp/"+MARK)>100000)
	{
		me->set(ComMark,1);
        tell_object(me,BLINK+HIW+"你似乎已经可以掌握峨眉武功的真谛了，去找周芷若和灭绝掌门指点一下吧，静迦和静闲好像也在找你。\n"+NOR);
	}
	if (me->query("chushi"))
	percent=to_float(me->query("exp/"+MARK))/1000;
	else
	percent=to_float(me->query("exp/"+MARK))/100000;
	if (me->query(ComMark))
	percent=1.0;
	percent=percent*100.0;
	return sprintf("%.2f",percent);
}
void punish(object me)
{
	int exp,pot,rep,neili,jingli,score;
	exp=CalcResult(me,"punish","exp");
	pot=CalcResult(me,"punish","pot");
	rep=CalcResult(me,"punish","rep");
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,-1,"");
	me->delete(MARK+"/start");
	me->delete_temp(MARK);
	return;
}
void bonus(object me)
{
	object ob=this_object();
	int exp,pot,rep,neili,score,jingli;
	int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-10;
	string percent,*skill_set=({"tiangang-zhi","jinding-mianzhang","fuliu-jian","yanxing-dao","zhutian"});
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	if (random(100)>75 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=3500)
	neili=2+random(3);
	if (random(100)>70 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=4500)
	jingli=1+random(2);
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete_temp(MARK);
	if (ob->query("id")=="miejue shitai"&& random(3))
	SkillBonus(me,skill_set[random(sizeof(skill_set))],limit_sk);//奖励技能的函数在公共函数中，这里需要一个*string作为技能池，从中选择。Zine
	return;
}   

