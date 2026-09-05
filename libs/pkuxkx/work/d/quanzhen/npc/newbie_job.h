int bonus(object me,int task_factor)
{
    object ob=this_object();
    int self_factor,exp,pot,rep,neili,jingli,n;
    
	if (!task_factor)
	{
		task_factor=2+random(2);
	}
    if (task_factor==1&&me->query("combat_exp")>7000)
    {
        task_factor=1+random(2);
    }
    if (me->query("combat_exp")<10000)
    {
        self_factor=5;
    }
    if (me->query("combat_exp")>=10000 && me->query("combat_exp")<15000)
    {
        self_factor=6;
    }
    if (me->query("combat_exp")>=15000 && me->query("combat_exp")<22000)
    {
        self_factor=7;
    }
    if (me->query("combat_exp")>=22000 && me->query("combat_exp")<30000)
    {
        self_factor=8;
    }
    if (me->query("combat_exp")>=30000 && me->query("combat_exp")<55000)
    {
        self_factor=10;
    }
    if (me->query("combat_exp")>=55000 && me->query("combat_exp")<85000)
    {
        self_factor=11;
    }
    if (me->query("combat_exp")>=85000 && me->query("combat_exp")<120000)
    {
        self_factor=13+random(3);
    }
    if (me->query("combat_exp")>=120000 && me->query("combat_exp")<180000)
    {
        self_factor=10;
    }
    if (me->query("combat_exp")>=180000 && me->query("combat_exp")<250000)
    {
        self_factor=7;
    }
    if (me->query("combat_exp")>=250000 && me->query("combat_exp")<330000)
    {
        self_factor=4;
    }
    if (me->query("combat_exp")>=330000)
    {
        self_factor=1;
    }
    if (me->query("combat_exp")>=50000000)
    {
        self_factor=5;
    }
    exp=task_factor*self_factor*(16+random(10));
    pot=1+random(exp/2)+random(exp/2);
    if (me->query("combat_exp")<20000)
    {pot=pot+random(pot);}
    rep=1+random(exp/4);
	
    exp=REWARD_D->add_exp(me,exp);
    me->add("exp/qznewbiejob", exp);
    pot=REWARD_D->add_pot(me,pot);
    me->add("pot/qznewbiejob", pot);
    rep=REWARD_D->add_rep(me,rep);
    me->add("rep/qznewbiejob", rep);
    me->delete_temp("qznewbiejob");
    if (living(ob))
    {
        CHANNEL_D->do_channel(ob, "sys_misc",
                        sprintf("%s在全真入门任务中获得经验：%d、潜能：%d、声望：%d。", me->name(), exp, pot, rep));
    }
    
    tell_object(me,HIR+"你被奖励了：\n");
    tell_object(me,"\t"+chinese_number(exp)+"点经验；\n");
    tell_object(me,"\t"+chinese_number(pot)+"点潜能；\n");
    tell_object(me,"\t"+chinese_number(rep)+"点江湖声望。\n"+NOR);
    
    if (random(100)>60 && me->query("max_neili")<me->query_skill("force")*10&&me->query("combat_exp")>=10000)
        {
            neili=3+random(3);
            me->add("max_neili",neili);
            tell_object(me,HIR+"\t"+chinese_number(neili)+"点内力。\n"+NOR);
        }
        if (random(100)>70 && me->query("max_jingli")<me->query_skill("force",1)*12&&me->query("combat_exp")>=15000)
        {
            jingli=3+random(5);
            me->add("max_jingli",jingli);
            tell_object(me,HIR+"\t"+chinese_number(jingli)+"点精力。\n"+NOR);
        }
    
    
    tell_object(me,HIG+"你已经通过全真入门任务获得了"+chinese_number((int)me->query("exp/qznewbiejob"))+"点经验。\n"+NOR);
        
    return 1;
}   


int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("qznewbiejob/task1"))
    {
        command("sign2");
        return 1;
    }
    me->delete_temp("qznewbiejob/task1");
    me->set("qznewbiejob_time",time());
    command("robot "+me->query("id"));
    return 1;
}

int ask_job()
{
    object me=this_player();
    object saoba;
    
    if (me->query("family/family_name")!="全真派")
    {
        command("say 我派弟子众多，不需要外人帮忙。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (time()-me->query("qznewbiejob_time")<150&&me->query("combat_exp")>40000)
    {
        tell_object(me,"你刚刚才来过，歇息一会吧。\n");
        return 1;
    }
    if (me->query_temp("qznewbiejob/task1/start"))
    {
        command("say 我不是让你去清扫石阶了吗？");
        return 1;
    }
    me->set("qznewbiejob_time",time());
    if (me->query("combat_exp")<(int)me->query("int")*600)
    {
        command("say 你去把从山下石阶到宫门的一段路去扫(sao)干净。");
        me->set_temp("qznewbiejob/task1/start",1);
        if (!present("da saoba",me))
        {
            saoba=new(__DIR__"obj/saoba");
            saoba->move(me);
            tell_object(me,this_object()->query("name")+"给你一把大扫把。\n");
        }
        return 1;
    }
    else
    {
        command("say 你的经验够多了，去别处看看吧。");
        return 1;
    }
    
}

void init()
{
    object me=this_player();
    object ob=this_object();
    int task_factor;
    ob->set("inquiry", ([
        "job":   (: ask_job() :),
        "工作":   (: ask_job() :),
        "任务":   (: ask_job() :),
        "fail":   (: ask_fail() :),
        "失败":   (: ask_fail() :),
    ]));
    if (me->query_temp("qznewbiejob/task1/start"))
    {
        if (me->query_temp("qznewbiejob/task1/1/finish")
            &&me->query_temp("qznewbiejob/task1/2/finish")
            &&me->query_temp("qznewbiejob/task1/3/finish")
            &&me->query_temp("qznewbiejob/task1/4/finish")
            &&me->query_temp("qznewbiejob/task1/5/finish")
            &&me->query_temp("qznewbiejob/task1/6/finish")
            &&me->query_temp("qznewbiejob/task1/7/finish"))

        {
            command("say 这么快就打扫完了？后生可畏啊。");
            task_factor=2;
            bonus(me,task_factor);
            me->delete_temp("qznewbiejob/task1");
            return;
        }
    }
}