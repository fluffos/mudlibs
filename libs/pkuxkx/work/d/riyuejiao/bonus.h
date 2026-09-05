#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "rynewbiejob"
#define FamilyMark "日月神教"
#define ComMark "rynewbiejobdone2"
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
		BaseValue=((TaskFactor+random(5))*GetSelfFactor(me,"bonus",ComMark,ComMark)+(1+random(10))*GetSelfFactor(me,"bonus",ComMark,ComMark))/3;
	}
	if (me->query(ComMark))
	return 1;
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	if (me->query("combat_exp")<18000)
	return 1+random(BaseValue)*2;
	return 1+random(BaseValue);
	if (ValueType=="rep")
	return 1+random(BaseValue/4);
}
string completeness(object me)
{
	float percent;
	if (me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("exp/"+MARK)>50000&&!me->query(ComMark))
	{
		me->set(ComMark,1);
		tell_object(me,BLINK+HIM+"你似乎已经可以掌握神教武功的真谛了。\n"+NOR);
	}
	if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("exp/"+MARK)>100000&&!me->query(ComMark))
	{
		me->set(ComMark,1);
		tell_object(me,BLINK+HIW+"你似乎已经可以掌握神教武功的真谛了。\n"+NOR);
	}
	if (me->query("chushi")&&me->query("family/family_name")==FamilyMark)
	percent=to_float(me->query("exp/"+MARK))/50000.0;
	if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark)
	percent=to_float(me->query("exp/"+MARK))/100000.0;
	if (me->query(ComMark))
	percent=1.0;
	percent=percent*100.0;
	return sprintf("%.2f",percent);
}

int bonus(object me)
{
	int exp,pot,rep,neili,jingli,score,limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-10;
	string percent;
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	if (me->query("chushi/done"))
	{
		exp *= 4;
		pot *= 2;
		rep *= 2;
	}
	if (random(100)>75 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=3500)
	neili=6+random(3);
	if (random(100)>70 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=6500)
	jingli=1+random(10);
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete_temp(MARK);
	return 1;
}   

