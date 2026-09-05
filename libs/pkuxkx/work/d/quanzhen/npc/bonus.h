#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "qznewbiejob"
#define FamilyMark "全真派"
#define ComMark "NoNeed"
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
		BaseValue=TaskFactor*GetSelfFactor(me,"bonus",ComMark,ComMark)*(15+random(11));
	}
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	if (me->query("combat_exp")<20000)
    return BaseValue+random(BaseValue);
	return 1+random(BaseValue/2)+random(BaseValue/2);
	if (ValueType=="rep")
	return 1+random(BaseValue/4);
}
string completeness(object me)
{
	return "NoNeed";
}
void bonus(object me)
{
	string percent;
	int exp,pot,rep,neili,jingli,score;
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	if (random(100)>60 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=10000)
	neili=3+random(3);
	if (random(100)>70 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=15000)
	jingli=3+random(5);
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete_temp(MARK);
	return;
}   


