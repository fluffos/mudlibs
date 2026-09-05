#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "mjnewbiejob"
#define FamilyMark "明教"
#define ComMark "mingjiaonewbiejobdone"
int CalcResult(object me,string Type,string ValueType)
{
	int BaseValue;
	if (Type=="punish")
	{
		BaseValue=(3+random(16))*GetSelfFactor(me,"punish",ComMark,ComMark);
	}
	if (Type=="bonus")
	{
		BaseValue=(this_object()->query("bonus")-(int)me->query("mingjiaonewbiejob/lucky")*5)*GetSelfFactor(me,"bonus",ComMark,ComMark)*6;
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
	if (me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("exp/"+MARK)>10000)
	{
		me->set(ComMark,1);
		tell_object(me,BLINK+HIR+"你似乎已经可以掌握圣火真意了，对你的今后的修为有极大帮助。\n");
	}
	if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark&&me->query("exp/"+MARK)>80000)
	{
		me->set(ComMark,1);
		tell_object(me,BLINK+HIR+"你似乎已经可以掌握圣火真意了，对你的今后的修为有极大帮助。\n");
	}
	if (me->query("chushi"))
	percent=to_float(me->query("exp/"+MARK))/10000;
	else
	percent=to_float(me->query("exp/"+MARK))/80000;
	if (me->query(ComMark))
	percent=1.0;
	percent=percent*100.0;
	return sprintf("%.2f",percent);
}
int bonus(object me)
{
	object ob=this_object();
	int exp,pot,rep,neili,jingli,score,limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-5;
	string percent,*skill_set=({"force","parry","dodge","sword","guangming-shenghuogong","datengnuo-bufa","shenghuo-lingfa","literate"});
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	if (me->query("combat_exp")<10000)
	{
		if (me->query("max_neili")<me->query_skill("force")*9)
		neili=5+random(6);
		if (me->query("max_jingli")<me->query_skill("force",1)*12)
		jingli=6+random(5);
		if (me->query("combat_exp")>3000)
		for (int i=0;i<5;i++)
		if (random(3))
		SkillBonus(me,skill_set[random(sizeof(skill_set))],limit_sk);//奖励技能的函数在公共函数中，这里需要一个*string作为技能池，从中选择。Zine
	}
	else
	{
		if (random(100)>90 && me->query("max_neili")<me->query_skill("force")*10)
		neili=5+random(3);
		if (random(100)>70 && me->query("max_jingli")<me->query_skill("force",1)*12)
		jingli=2+random(2);
	}
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	me->delete_temp("mingjiao/tasks");
	return 1;
}   

void die()
{
    object ob=this_object();
    object killer=ob->get_damage_origin_object();
	if (killer)
	{
    if (time()-killer->query("mingjiao_kill_master")<120)
        {
            if (killer->query("family/family_name")!="明教")
            {
                message_vision("$N道：好啊，终于被我抓住了残害明教教众的恶徒。\n",ob);
                tell_object(killer,"你赫然发现"+ob->name()+"竟是旁人假扮的。\n");
                tell_object(killer,"你被周围埋伏的明教教众乱拳打晕。\n");
            }
            else
            {
                message_vision("$N道：好啊，原来混入我教，残害我教徒的叛徒就是你，来人啊，拿下。\n",ob);
                tell_object(killer,"你赫然发现"+ob->name()+"竟是旁人假扮的。\n");
                tell_object(killer,"你被周围埋伏的明教教众乱拳打晕。\n");
            }
            killer->unconcious();
            killer->move("/d/mingjiao/prison");
            killer->apply_condition("mj_pantu",40);
            return;
        }
    killer->set("mingjiao_kill_master",time());
    }
	::die();
    return;
}