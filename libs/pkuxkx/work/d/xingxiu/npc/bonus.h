#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "xxnewbiejob"
#define FamilyMark "星宿派"
#define ComMark "NoNeed"
int CalcResult(object me,int flag,string ValueType)
{
	int BaseValue,*Basics=({0,450,1125,2250,1120}),*extras=({0,10000,40000,70000,-1});
	BaseValue=Basics[flag]+random(225);
	if (me->query("combat_exp")>extras[flag]&&extras[flag]!=-1)
	BaseValue+=225;
	if (me->query("combat_exp")>(extras[flag]+10000)&&extras[flag]!=-1)
	BaseValue+=225;
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	return BaseValue/2;
	if (ValueType=="rep")
	return 1+random(BaseValue*2/3);
	if (ValueType=="neili")
	{
		if (random(100)>60 && me->query("max_neili")<me->query_skill("force")*10)
        return flag+2+random(flag+2);
		return 0;
	}
	if (ValueType=="jingli")
	{
		if (random(100)>75 && me->query("max_jingli")<me->query_skill("force",1)*12)
        return flag+2+random(flag+1);
		return 0;
	}
}
string completeness(object me)
{
	return "NoNeed";
}

void bonus(object me,int flag,string skill,int posibility)
{
	object ob=this_object();
	int exp,pot,rep,neili,score,jingli;
	int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-10;
	string percent,*skill_set=({"tiangang-zhi","jinding-mianzhang","fuliu-jian","yanxing-dao","zhutian"});
	exp=CalcResult(me,flag,"exp");
	pot=CalcResult(me,flag,"pot");
	rep=CalcResult(me,flag,"rep");
	neili=CalcResult(me,flag,"neili");
	jingli=CalcResult(me,flag,"jingli");
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete_temp(MARK);
	if(random(100)>posibility)
	{
		me->improve_skill(skill,1+(int)(me->query_skill("poison",1)*me->query("int")/10));
		write(HIG+ob->name()+"很高兴，传授了你一些有关"+CHINESE_D->chinese(skill)+"的心得。\n"NOR);
	}
	return;
}   

