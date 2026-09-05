//天龙奖惩文件 Zine
#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "tlnewbiejob"
#define FamilyMark "天龙寺"
#define ComMark "tlnewbiejobdone"
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
		BaseValue=TaskFactor*GetSelfFactor(me,"bonus",ComMark,ComMark)*5+(1+random(8))*GetSelfFactor(me,"bonus",ComMark,ComMark);
	}
	if (me->query(ComMark))
	return 1;
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	BaseValue=1+random(BaseValue/3)+random(BaseValue/4);
	if (me->query("combat_exp")<20000)
	return BaseValue*3+random(BaseValue);
	return BaseValue;
	if (ValueType=="rep")
	return 1+random(BaseValue/4);
}
string completeness(object me)
{
	float percent;
	if (me->query("chushi")&&me->query("family/family_name")== FamilyMark&&me->query("exp/"+MARK)>20000)
	{
		me->set(ComMark,1);
		tell_object(me,BLINK+HIG+"枯荣大师好像在找你，快去看看有什么事吧。\n"+NOR);
	}
	if (!me->query("chushi")&&me->query("family/family_name")== FamilyMark&&me->query("exp/"+MARK)>100000)
	{
		me->set(ComMark,1);
		tell_object(me,BLINK+HIG+"枯荣大师好像在找你，快去看看有什么事吧。\n"+NOR);
	}
	if (me->query("chushi"))
	percent=to_float(me->query("exp/"+MARK))/20000;
	else
	percent=to_float(me->query("exp/"+MARK))/100000;
	if (me->query(ComMark))
	percent=1.0;
	percent=percent*100.0;
	return sprintf("%.2f",percent);
}

int bonus(object me)
{
	int exp,pot,rep,score,neili,jingli,n;
	string percent;
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	percent=completeness(me);
	if (random(100)>25 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=10000)
	neili=1+random(4);
	if (random(100)>50 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=15000)
	jingli=2+random(2);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete_temp(MARK);
	return 1;
}   

