int ask_tasks();
int ask_task();
int ask_fail();
int ask_finish();
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

int npc_update(mapping song,object npc,int flag)
{
    object pl;
	if (flag==0)
	return 1;
	if (flag==-1&&song["owner"]!="")
	{
		npc->set_name(song["owner_name"],({song["owner"]+" npc"}));
		pl=find_player(song["owner"]);
	}
	else
	{
		if (arrayp(song["owner_name"])&&sizeof(song["owner_name"])>=flag&&stringp(song["owner_name"][flag-1])&&stringp(song["owner"][flag-1])&&song["owner"][flag-1]!="")
		{
			npc->set_name(song["owner_name"][flag-1],({song["owner"][flag-1]+" npc"}));
			pl=find_player(song["owner"][flag-1]);
		}
	}
	if (pl&&userp(pl))
	npc_renew(npc,pl);
	return 1;
}

void wear_guanfu(int pin,string pro,string title)
{
	object cloth;
	if (pin<=0&&!query("eunuch"))
	return;
	if (pro=="武")
	{
		if (pin<=5)
		cloth=new("/d/city/npc/items/cloth");
		else
		cloth=new("/d/dalunsi/npc/obj/pijia");
	}
	else if (pro=="文")
	{
		if (pin<=3)
		cloth=new(__DIR__"obj/cloth1");
		else if (pin<=5)
		cloth=new(__DIR__"obj/cloth2");
		else
		cloth=new(__DIR__"obj/cloth3");
	}
	else
	{
		cloth=new("/d/hangzhou/npc/obj/tjfu");
		cloth->adv_eunuch();
	}
	cloth->move(this_object());
	"/cmds/std/wear"->do_wear(this_object(),cloth);
	return;
}
int npc_to_player(string title,int age,int npc_serial)
{
    int i;
    object ob=load_object("/d/song/record/positions"),npc=this_object();
    mapping *give_outs;
	string *task_giver=({"同中书门下平章事","参知政事","门下侍郎","中书侍郎","枢密使","枢密副使","知枢密院事","同知枢密院事","入内内侍省都都知"});
	string *lower_task_giver=({"三司使","御史中丞","兵部尚书","吏部尚书","刑部尚书","礼部侍郎","工部尚书","户部尚书","左司谏","鸿胪寺卿",
		"翰林学士","太医局丞","太常寺卿","大理寺卿","宗正寺卿","司农寺卿","太府寺卿","将做监判监事","军器监判监事","太常寺卿","临安府尹","都水监使者","殿前司都指挥使","天武卫上护军",
		"捧日卫上护军","神卫上护军","龙卫上护军","马军司都指挥使","步军司都指挥使","水师大都督","提举御药院","勾管内东门司","勾管合同凭由司","勾管后苑造作所","勾管军头引见司","勾管往来国信","提举翰林院"});
	set("posi",title);
	if (member_array(title,task_giver)!=-1)
	{
		set("inquiry", ([
	
		 "工作": (: ask_tasks :),
		 "job": (: ask_tasks :),
		 "失败": (: ask_fail :),
		 "fail": (: ask_fail :),
		]));
	}
	if (member_array(title,lower_task_giver)!=-1)
	{
		set("inquiry", ([
	
		 "帮助": (: ask_task :),
		 "help": (: ask_task :),
		 "完成": (: ask_finish :),
		 "finish": (: ask_finish :),
		]));
	}
	DASONG_D->record_npc(npc,title);
	set("title", "大宋 "+HIR+title+NOR);
	set("age",age);
	set("long","他就是当今朝廷的"+title+"。\n");
	if (member_array(title,({"入内内侍省都都知","提举御药院","勾管内东门司","勾管合同凭由司","勾管后苑造作所","勾管军头引见司","勾管往来国信","提举翰林院"}))!=-1)
	{
		set("gender","无性");
		set("eunuch",1);
	}
	if (!ob->query("give_titles"))
    give_outs=DASONG_D->upper_title();
	else
    give_outs=ob->query("give_titles");
    for (i=0;i<sizeof(give_outs);i++)
    {
		if (give_outs[i]["title"]==title)
		{
			if (give_outs[i]["no_promote"]&&(give_outs[i]["owner"]==({})||give_outs[i]["owner"]==""))
			{
				message_vision("$N匆匆忙忙地离开了。\n",npc);
				destruct(npc);
				return 1;
			}
			npc->set("song/pin",give_outs[i]["pin"]);
			wear_guanfu(give_outs[i]["pin"],give_outs[i]["pro"],title);
			if (arrayp(give_outs[i]["owner"]))
			npc_update(give_outs[i],npc,npc_serial);
			else
			npc_update(give_outs[i],npc,-1);
			return 1;
		}
    }
	if (!ob->query("give_mediate_titles"))
    give_outs=DASONG_D->lower_title();
	else
    give_outs=ob->query("give_mediate_titles");
	for (i=0;i<sizeof(give_outs);i++)
    {
		if (give_outs[i]["title"]==title)
		{
			npc->set("song/pin",give_outs[i]["pin"]);
			wear_guanfu(give_outs[i]["pin"],give_outs[i]["pro"],title);
			return 1;
		}
    }
	give_outs=DASONG_D->lowest_title();
	for (i=0;i<sizeof(give_outs);i++)
    {
		if (give_outs[i]["title"]==title)
		{
			npc->set("song/pin",give_outs[i]["pin"]);
			wear_guanfu(give_outs[i]["pin"],give_outs[i]["pro"],title);
			return 1;
		}
    }
	wear_guanfu(6,"宦",title);
	return 1;
}


