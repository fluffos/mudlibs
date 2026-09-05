#include <ansi.h>
#include "/kungfu/class/gaibang/PublicSettingsNewbieJobs.h" // 重新修订的新手任务公共设置放在第一个修改的丐帮任务下 Zine 2014/1/18
#define MARK "gbnewbiejob"
#define FamilyMark "丐帮"
#define ComMark "gaibangnewbiejobdone"
#define ComMark2 "gaibangnewbiejobdone_2"
int CalcResult(object me,string Type,string ValueType)
{
	int BaseValue;
	if (Type=="punish")
	{
		BaseValue=(3+random(16))*GetSelfFactor(me,"punish",ComMark,ComMark2);
	}
	if (Type=="bonus")
	{
		BaseValue=(20+random(11))*GetSelfFactor(me,"bonus",ComMark,ComMark2);
		if (me->query(MARK+"/start")=="beg")
		BaseValue=BaseValue+100+random(60);
		else if (me->query(MARK+"/start")=="steal")
		BaseValue=BaseValue+140+random(65);
		else
		BaseValue=BaseValue+180+random(40);
	}
	if (me->query_temp(MARK+"/extra")==1)
	BaseValue/=2;
	if (ValueType=="exp")
	return BaseValue;
	if (ValueType=="pot")
	return 1+random(BaseValue*3/4);
	if (ValueType=="rep")
	return 1+random(BaseValue/4);
}

string completeness(object me)
{
	float percent,percent2;
	if (me->query("chushi")&&me->query("family/family_name")==FamilyMark&&(me->query("exp/"+MARK)>10000||me->query("exp/"+MARK)>me->query_int()*me->query_str()))
	{
		if (me->query("is_beggar"))
		{
			me->set(ComMark,1);
			tell_object(me,BLINK+HIY+"你似乎已经掌握了妙手空空的真意。\n"NOR);
		}
		if (me->query("is_beggar2"))
		{
			me->set(ComMark2,1);
			tell_object(me,BLINK+HIY+"你似乎已经掌握了叫花绝活的真意。\n"NOR);
		}
	}
	if (!me->query("chushi")&&me->query("family/family_name")==FamilyMark&&(me->query("exp/"+MARK)>100000||me->query("exp/"+MARK)>me->query_int()*me->query_dex()*me->query_con()*me->query_str()/5))
	{
		if (me->query("is_beggar"))
		{
			me->set(ComMark,1);
			tell_object(me,BLINK+HIY+"你似乎已经掌握了妙手空空的真意。\n"NOR);
		}
		if (me->query("is_beggar2"))
		{
			me->set(ComMark2,1);
			tell_object(me,BLINK+HIY+"你似乎已经掌握了叫花绝活的真意。\n"NOR);
		}
	}
	if (!me->query("chushi"))
	{
		percent=to_float(me->query("exp/"+MARK))/to_float(me->query_int())/to_float(me->query_dex())/to_float(me->query_con())/to_float(me->query_str())*5.0;
		percent2=to_float(me->query("exp/"+MARK))/100000;
	}
	else
	{
		percent=to_float(me->query("exp/"+MARK))/to_float(me->query_int())/to_float(me->query_str());
		percent2=to_float(me->query("exp/"+MARK))/10000;
	}
	if (percent<percent2)
	percent=percent2;
	if (me->query(ComMark)||me->query(ComMark2))
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
	return;
}
int bonus(object me)
{
	int pin,count,i,exp,pot,rep,neili,jingli,score;
	int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-10;
	object ob=this_object();
	object target,where,*inv,item;
	string percent,*skill_set=({"force","huntian-qigong","begging","stealing","xiaoyaoyou","checking"});
	me->add("jobs/completed/newbie_gb",1);
	me->add(MARK+"/times",1);
	exp=CalcResult(me,"bonus","exp");
	pot=CalcResult(me,"bonus","pot");
	rep=CalcResult(me,"bonus","rep");
	if (random(100)>50 && me->query("max_neili")<me->query_skill("force")*7)
	neili=1+random(2);
	if (random(100)>90 && me->query("max_jingli")<me->query_skill("force",1)*10)
	jingli=4+random(3);
	if ((me->query(MARK+"/start")=="beg"||me->query(MARK+"/start")=="steal")&&!random(5)&&me->query("score")<900)
	score=1;
	percent=completeness(me);
	IndeedModify(me,exp,pot,rep,neili,jingli,score,MARK,FamilyMark,1,percent);
	if (random(2))
	SkillBonus(me,skill_set[random(sizeof(skill_set))],limit_sk);//奖励技能的函数在公共函数中，这里需要一个*string作为技能池，从中选择。Zine
    //完成度提示
	
	
	me->delete(MARK+"/start");
    me->delete_temp(MARK);
	//附加任务
	if (me->query_temp("gb_newbie_finish")&&!me->query(MARK+"/start"))
	{
		me->delete_temp("gb_newbie_finish");
		if (me->query("is_beggar"))
		item=new(__DIR__"newbie_job/case1");
		if (me->query("is_beggar2"))
		item=new(__DIR__"newbie_job/case2");
		if (item)
		{
			item->move(me);
			command("say 这样"+item->query("name")+"就交给你了。\n");
		}
	}
    if ((int)me->query("jobs/completed/newbie_gb")%10==7)
    {
        while(!target && count < 5)
        {
            where = TASK_D->random_place();
            inv = all_inventory(where);
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
                    continue;
                if(inv[i]->query("uni_target") || inv[i]->query("random_npc"))
                    continue;
                target = inv[i];
            }
            count++;
        }
        if (target)
        {
            command("say 看你办事稳重，让人放心，我就交给你一件大事去做。");
            command("say 丐帮弟子素以消息灵通闻名天下，你去"+TASK_D->place_belong(where)+"的"+where->query("short")+"找"+target->query("name")+"打听一些情报吧。(ask "+target->query("id")+" about rumors)\n");
            pin=random(10000)+1;
            target->set_temp("gb_newbie_extra",pin);
            me->set_temp("gb_newbie_extra",pin);
            tell_object(me,HIG+BLINK+"此任务是丐帮新手任务的穿插福利，奖励远大于平均水准，请尽量不要放弃！\n"+NOR);
        }
    }
    return 1;
}   

int do_answer(string arg)
{
    object me=this_player();
    string word;
    if (!me->query_temp("gb_newbie_finish"))
    {
        return 0;
    }
    if (!arg||sscanf(arg,"%s",word)!=1)
    {
        command("say 你要回复什么？");
        return 1;
    }
    if (word!=me->query_temp("gb_newbie_finish"))
    {
        me->add_temp("gb_newbie_error",1);
        command("say 你在忽悠我吗？");
        if (me->query_temp("gb_newbie_error")>2)
        {
            me->delete_temp("gb_newbie_finish");
            me->delete_temp("gb_newbie_error");
            command("say 试来试去都不对，你下去吧。");
        }
        return 1;
    }
    else
    {
        command("say 原来"+me->query_temp("gb_newbie_finish")+"竟然是这种人！");
        me->delete_temp("gb_newbie_error");
        bonus(me);
        return 1;
    }
}