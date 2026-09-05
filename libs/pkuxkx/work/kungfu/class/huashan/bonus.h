#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "hsnewbiejob"
#define FamilyMark "华山派"
#define ComMark "huashannewbiejobdone"
int CalcResult(object me,string Type,string ValueType)
{
	int BaseValue;
	if (Type=="punish")
	{
		if (me->query_temp(MARK+"/xunshan"))
		BaseValue=(5+random(5));
		if (me->query_temp(MARK+"/xunlian"))
		BaseValue=(7+random(7));
		if (me->query_temp(MARK+"/songxin"))
		BaseValue=(10+random(10));
		BaseValue*=GetSelfFactor(me,"punish",ComMark,ComMark);
	}
	if (Type=="bonus")
	{
		if (me->query_temp(MARK+"/xunshan"))
		BaseValue=20+random(16);
		if (me->query_temp(MARK+"/xunlian"))
		BaseValue=21+random(25);
		if (me->query_temp(MARK+"/songxin"))
		BaseValue=18+random(26)+(int)me->query_temp(MARK+"/songxin/killer")*12;
		if (me->query_temp(MARK+"/target"))
		BaseValue=50+random(40);
		BaseValue*=GetSelfFactor(me,"bonus",ComMark,ComMark);
		BaseValue/=5;
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
        tell_object(me,BLINK+HIY+"你似乎已经领悟了些华山武功的真意，去和掌门讨教一下吧。\n");
    }
    if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("combat_exp")<330000&&me->query("exp/"+MARK)>100000)
    {
        me->set(ComMark,1);
        tell_object(me,BLINK+HIY+"你似乎已经领悟了些华山武功的真意，去和掌门讨教一下吧。\n");
    }
    if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("combat_exp")>=330000&&me->query("exp/"+MARK)>25000)
    {
        me->set(ComMark,1);
        tell_object(me,BLINK+HIY+"你似乎已经领悟了些华山武功的真意，去和掌门讨教一下吧。\n");
    }
	if (!me->query("chushi"))
	{
		if (me->query("combat_exp")<330000)
		percent=to_float(me->query("exp/"+MARK))/100000;
		else
		percent=to_float(me->query("exp/"+MARK))/25000;
	}
	else
	{
		percent=to_float(me->query("exp/"+MARK))/1000;
	}
	if (me->query(ComMark))
	percent=1.0;
	percent=percent*100.0;
	return sprintf("%.2f",percent);
}

int punish(object me)
{
	int exp,pot,rep,neili,jingli,score;
	exp=CalcResult(me,"punish","exp");
	pot=CalcResult(me,"punish","pot");
	rep=CalcResult(me,"punish","rep");
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,-1,"");
	me->delete(MARK+"/start");
	me->delete_temp(MARK);
	return 1;
}

int bonus(object me)
{
	int exp,pot,rep,neili,jingli,score;
	string percent;
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	if (random(100)>40 && me->query("max_neili")<me->query_skill("force")*6)
	neili=1+random(2);
	if (random(100)>90 && me->query("max_jingli")<me->query_skill("force",1)*9)
	jingli=3+random(3);
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete(MARK+"/start");
	me->delete_temp(MARK);
	return 1;
}   

