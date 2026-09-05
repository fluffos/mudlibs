#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "taohuanewbie"
#define FamilyMark "桃花岛"
#define ComMark "NoNeed"
int CalcResult(object me,string Type,string ValueType,string Giver)
{
	int BaseValue,TaskFactor,tmp;
	if (Giver=="luguanying")
	BaseValue=(200+random(200))*BuffInc()/6;
	if (Giver=="killer")
	BaseValue=(500+random(250))*BuffInc()/6;
	if (me->query("exp/taohuanewbie")>400000)
	BaseValue/=3;
	if (me->query("exp/taohuanewbie")>1000000)
	BaseValue=10;
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	return 1+random(BaseValue/2);
	if (ValueType=="rep")
	return 1+random(BaseValue/4);
}
string completeness(object me)
{
	return "NoNeed";
}

int bonus(object me,string BonusGiver)
{
	int BaseValue,exp,pot,rep,neili,jingli,score,limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-10;
	string percent,notice,skill="";
	if (BonusGiver=="taohuazhen")
	{
		if (me->query("combat_exp")>80000&&me->query("combat_exp")<=300000)
		{
			BaseValue=8;
			notice="你渐渐发现，桃林的路径你烂熟于心，对你已不是挑战。\n";
			if (me->query("combat_exp")>300000&&random(100)<=84)
			{
				BaseValue=1;
				notice="桃林的路径对你简直是掌上观纹，轻而易举。\n";
			}
		}
		else
		{
			notice="你顺利地回到了起点。\n";
			BaseValue=8+random(10);
			if (me->query("combat_exp")<20000)
			BaseValue-=4;
			else if (me->query("combat_exp")<30000)
			BaseValue-=2;
			else if (me->query("combat_exp")<45000)
			BaseValue+=1;
			else if (me->query("combat_exp")<60000)
			BaseValue+=random(4);
			else
			BaseValue+=random(BaseValue);
		}
		tell_object(me,notice);
		exp=REWARD_D->add_exp(me,BaseValue);
		tell_object(me,HIC"你获得了"+chinese_number(exp)+"点经验。\n"NOR);
		pot=REWARD_D->add_pot(me,BaseValue);
		tell_object(me,HIC"你获得了"+chinese_number(pot)+"点潜能。\n"NOR);
		if (!random(4))
		skill="dodge";
		if (!random(5)&&me->query("family/family_name")=="桃花岛")
		skill="luoying-shenfa";
		if (skill!="")
		{
			me->improve_skill(skill,random((int)me->query("dex"))+(int)me->query("con"));
			tell_object(me,"穿越桃花阵的过程中，你的"+CHINESE_D->chinese(skill)+"也获得了些许进步。\n");
		}
		return 1;
	}
	exp=CalcResult(me,"bonus","exp",BonusGiver);
	pot=CalcResult(me,"bonus","pot",BonusGiver);
	rep=CalcResult(me,"bonus","rep",BonusGiver);
	if (random(100)>75 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=3500)
	neili=6+random(3);
	if (random(100)>70 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=6500)
	jingli=1+random(10);
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	if (BonusGiver=="luguanying")
	{
		if (random(3)&&me->query_skill("identification",1)<20)
			skill="identification";
		if (!random(4)&&me->query_skill("anti-disguise",1)<10)
			skill="anti-disguise";
		if (skill!="")
		{
			me->improve_skill(skill,random((int)me->query("kar"))+(int)me->query("int"));
			tell_object(me,"完成鉴定任务后，你的"+CHINESE_D->chinese(skill)+"也获得了些许进步。\n");
		}
	}
	return 1;
}   

