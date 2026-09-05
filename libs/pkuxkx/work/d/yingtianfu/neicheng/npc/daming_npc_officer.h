int npc_to_player();
int setup_player_name()
{
    npc_to_player();
}

int npc_renew(object me,object ob)
{
    mapping hp_status, skill_status, map_status, prepare_status;
    mapping my;
    string *sname, *mname, *pname;
    int i, temp;
    if (mapp(skill_status = me->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
    {
        skill_status = me->query_skills();
        sname = keys(skill_status);//传回所有自己的功夫阵列
        temp = sizeof(skill_status);
        for (i = 0; i < temp; i++)
        me->delete_skill(sname[i]);//删除自己所有功夫
    }

    if (mapp(skill_status = ob->query_skills()))//判断对象是否有功夫，如有将用这个函数复制全部功夫
    {
        skill_status = ob->query_skills();
        sname = keys(skill_status);//传回所有对象功夫阵列
        for (i = 0; i < sizeof(skill_status); i++)
        me->set_skill(sname[i], skill_status[sname[i]]);//为自己复制所有功夫
    }
    if (mapp(map_status = me->query_skill_map()))//判断自己是否有已装配的基本功夫
    {
        mname = keys(map_status);
        temp = sizeof(map_status);
        for (i = 0; i < temp; i++)
        me->map_skill(mname[i]);
    }
    if (mapp(map_status = ob->query_skill_map()))//判断对象所装配的基本功夫，如有将用这个函数复制
    {
        mname = keys(map_status);
        for(i = 0; i < sizeof(map_status); i++)
        me->map_skill(mname[i], map_status[mname[i]]);
    }
    if (mapp(prepare_status = me->query_skill_prepare()))//判断自己是否有已装配的特殊功夫
    {
        pname = keys(prepare_status);
        temp = sizeof(prepare_status);
        for(i = 0; i < temp; i++)
        me->prepare_skill(pname[i]);
    }
    if (mapp(prepare_status = ob->query_skill_prepare()))//判断对象所装配的特殊功夫，如有将用这个函数复制
    {
        pname = keys(prepare_status);
        for(i = 0; i < sizeof(prepare_status); i++)
        me->prepare_skill(pname[i], prepare_status[pname[i]]);
    }
    hp_status = ob->query_entire_dbase();//得到对象现有状态
    my = me->query_entire_dbase();//得到自己现有状态
    my["str"] = hp_status["str"];//开始复制状态
    my["int"] = hp_status["int"];
    my["con"] = hp_status["con"];
    my["cor"] = hp_status["cor"];
    my["kar"] = hp_status["kar"];
    my["per"] = hp_status["per"];
    my["max_qi"] = hp_status["max_qi"];
    my["eff_qi"] = hp_status["eff_qi"];
    my["qi"] = hp_status["qi"];
    my["max_jing"] = hp_status["max_jing"];
    my["eff_jing"] = hp_status["eff_jing"];
    my["jing"] = hp_status["jing"];
    my["max_jingli"] = hp_status["max_jingli"];
    my["jingli"] = hp_status["jingli"];
    my["shen"] = hp_status["shen"];
    my["max_neili"] = hp_status["max_neili"];
    my["neili"] = hp_status["neili"];
    my["combat_exp"] = hp_status["combat_exp"];//结束复制状态
    me->reset_action();//更新身体
    return 1;
}

int npc_update(mapping ming,object npc)
{
    string name,title,npc_file;
    object pl;
    int i;
    name=ming["owner_name"];
    title=ming["title"];
    npc->set("name",name);
    npc->set("title",HIW"大明 "+title+NOR);
    if (find_player(ming["owner"]))
    {
        pl=find_player(ming["owner"]);
        npc_renew(npc,pl);
    }
    return 1;
}
int npc_to_player()
{
    int i;
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi"),npc=this_object(),*npcs;
    mapping *give_outs;
    ob->restore();
    if (ob->query("give_titles"))
    {
        give_outs=ob->query("give_titles");
    }
    else
    {
        return 1;
    }
    for (i=0;i<sizeof(give_outs);i++)
    {
        npcs=children(give_outs[i]["npc"]);
        if (give_outs[i]["owner"]!=""&&member_array(npc,npcs)!=-1)
        {
            npc_update(give_outs[i],npc);
        }
    }
    
    return 1;
}

string if_give_task(object me)
{
	mixed tm=localtime(time());
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]),depart;
	if (!me->query("mingpin"))
    {
        return this_object()->name()+"道：“老夫在朝二十余年，大明官员都见过，怎么不认识你？”\n";
    }
	depart=this_object()->query("depart");
	if (!me->query_temp("mingtasks/"+depart+"/start")&&me->query("mingpin")!=1)
    {
        return this_object()->name()+"道：“我这里暂时没有什么事，你去别的衙门看看哪里需要帮忙吧。”\n";
    }
	if (me->query("mingpin")==1&&day!=me->query("ming/1pintask/date"))
	{
		me->set("ming/1pintask/date",day);
		me->set("ming/1pintask/times",0);
		me->set("ming/1pintask/departs",({}));
	}
	if (me->query("mingpin")==1&&me->query("ming/1pintask/times")>3)
	{
		return "今日你已经很辛苦了，明天再继续吧。\n";
	}
	if (me->query("mingpin")==1&&member_array(depart,me->query("ming/1pintask/departs"))!=-1)
	{
		return "今日你已经指导过"+depart+"了，再去看看其他的衙门吧。\n";
	}
    if (me->is_busy() || me->is_fighting())
    {
		return "你正忙着哪！\n";
    }
    if (me->query("mingpin")>6)
    {
        return this_object()->name()+"道：“你只是一个芝麻小官，恐怕不能胜任本部的任务。”\n";
    }
	if (me->query_temp("mingtasks/"+depart+"/task"))
    {
        return "你领了任务，就赶紧去做吧。\n";
    }
	return "approve";
}

int pre_1pin(object me)
{
	string *departs=({}),depart=this_object()->query("depart");
	if (me->query("ming/1pintask/departs"))
	{
		departs=me->query("ming/1pintask/departs");
	}
	departs+=({depart});
	me->add("ming/1pintask/times",1);
	me->set("ming/1pintask/departs",departs);
	command("say 恭送"+me->query("name")+"大人。");
	return 1;
}

int task_finish(object me,int reward,string comment)
{
	int n;
	if (me->query("mingpin")!=1)
	{
		n=reward;
		command("say "+comment);
		command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
	}
	else
	{
		n=reward*3/2;
		command("flatter "+me->query("id"));
		tell_object(me,"你的大明功勋增加了"+chinese_number(n)+"点。\n");
	}
	me->add("ming/credit",n);
	me->delete_temp("mingtasks");
	return 1;
}

int task_pending(object me,object ob)
{
	if (me->query("mingpin")!=1)
	command("say 你完成了吗？\n");
	else
	message_vision("$N一副欲言又止的样子。\n",ob);
	return 1;
}