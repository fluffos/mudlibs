//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//**********************    Menpai KILLER Star Here  **************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
void menpai_killer(object me, string strName, string strId, string strFName, int intExp)
{
    object npc, pid, *list;
    mapping hp_status, skill_status, map_status, prepare_status;
    mapping my;
    mapping skill_statusb;
    int i, temp, myexp, mylvl, k, count, point;
    int j, total, looptime, m, x;
    string *sname, *mname, *pname, pkid;
    string *snameb;
    string strMsg;


    strMsg = HIR+"$n说到：你这个不要脸的家伙今天让我送你上路\n"+NOR;
    npc = new("/family_job/heyiren");
    
    list = users();
    total = sizeof(list);

    m = 0;

    for(m=0; m!=1; m) 
    {
        j = random(total);
        list[j]->short(1);
        pid = list[j];

        if(pid->query("combat_exp") > 500000)
        {
            m = 1;
        }

        if(looptime > 10)
        {
            m = 1;
            pid = me;               
        }

        looptime = looptime + 1;
    }



    if (mapp(skill_status = npc->query_skills()))
    {
        skill_status = npc->query_skills();
        sname = keys(skill_status);

        temp = sizeof(skill_status);
        for (i = 0; i < temp; i++)
            npc->delete_skill(sname[i]);
    }

    if (mapp(skill_status = pid->query_skills()))
    {
        skill_status = pid->query_skills();
        sname = keys(skill_status);

        for (i = 0; i < sizeof(skill_status); i++)
            npc->set_skill(sname[i], skill_status[sname[i]]);
    }
    
    if (mapp(map_status = npc->query_skill_map()))
    {
        mname = keys(map_status);

        temp = sizeof(map_status);
        for (i = 0; i < temp; i++)
            npc->map_skill(mname[i]);
    }

    if (mapp(map_status = pid->query_skill_map()))
    {
        mname = keys(map_status);

        for(i = 0; i < sizeof(map_status); i++)
            npc->map_skill(mname[i], map_status[mname[i]]);
    }

    if (mapp(prepare_status = npc->query_skill_prepare()))
    {
        pname = keys(prepare_status);

        temp = sizeof(prepare_status);
        for(i = 0; i < temp; i++)
            npc->prepare_skill(pname[i]);
    }

    if (mapp(prepare_status = pid->query_skill_prepare()))
    {
        pname = keys(prepare_status);

        for(i = 0; i < sizeof(prepare_status); i++)
            npc->prepare_skill(pname[i], prepare_status[pname[i]]);
    }


    hp_status = me->query_entire_dbase();
    my = npc->query_entire_dbase();

    my["str"] = hp_status["str"];
    my["int"] = hp_status["int"];
    my["con"] = hp_status["con"];
    my["dex"] = hp_status["dex"];

    my["max_qi"]     = hp_status["max_qi"];
    my["eff_qi"]     = hp_status["eff_qi"];
    my["qi"]     = hp_status["qi"];
    my["max_jing"]   = hp_status["max_jing"];
    my["eff_jing"]   = hp_status["eff_jing"];
    my["max_jingli"]   = hp_status["max_jingli"];
    my["eff_jingli"]   = hp_status["eff_jingli"];
    my["jingli"]       = hp_status["jingli"];
    my["jing"]       = hp_status["jing"];
    my["max_neili"]  = hp_status["max_neili"];
    my["neili"]      = hp_status["neili"];
    my["jiali"]      = hp_status["jiali"];
    my["combat_exp"] = hp_status["combat_exp"];

        
        
        npc->reset_action();
        myexp = npc->query("combat_exp");

        if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)-10);
        
        myexp = npc->query("combat_exp");
        myexp /= 1000;

        if (myexp>50000) myexp = 50000;
    myexp *= 1000;
    mylvl = to_int(pow(myexp*10,0.33333)+1);

    if ( mapp(skill_statusb = npc->query_skills()) ) {
        skill_statusb = npc->query_skills();
        snameb = keys(skill_statusb);
        count = sizeof(skill_statusb);

        for(k=0; k<sizeof(skill_statusb); k++) 
                {
            npc->set_skill(snameb[k],mylvl);
        }
    }

    npc->set("combat_exp",myexp);


    //TEMP SETTING DATA
    npc->set_skill("poison", 100);
    npc->set_skill("qianzhu-wandu", 70);
    npc->set_skill("longzhua-gong", 100);
    //END OF SETTING DATA


    pkid = me->query("id");
    npc->set_temp("pkid", pkid);
    npc->move(environment(me));


    strMsg = strMsg + HIW + vermsg + NOR;
    message_vision(strMsg, me, npc);
    message_vision(HIG"突然$n冲了过来使出天地无双将$N突然震住\n"NOR, me, npc);
    me->start_busy(2);


	//x = 65;

	//General Control Varible
    switch(strFName)
    {
    case "武当派":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 40+x);
        npc->set_temp("apply/speed", 10+x);
        npc->set_temp("apply/armor", 55+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "少林派":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 50+x);
        npc->set_temp("apply/speed", 10+x);
        npc->set_temp("apply/armor", 55+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "丐帮":
    {
        npc->set_temp("apply/dodge", 50+x);
            npc->set_temp("apply/damage", 40+x);
            npc->set_temp("apply/speed", 10+x);
            npc->set_temp("apply/armor", 85+x);
			npc->set_temp("apply/parry", 50+x);
			npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "星宿派":
    {
        npc->set_temp("apply/dodge", 150+x);
            npc->set_temp("apply/damage", 150+x);
            npc->set_temp("apply/speed", 150+x);
            npc->set_temp("apply/armor", 175+x);
			npc->set_temp("apply/parry", 50+x);
			npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "峨嵋派":
    {
        npc->set_temp("apply/dodge", 100+x);
            npc->set_temp("apply/damage", 40+x);
            npc->set_temp("apply/speed", 10+x);
            npc->set_temp("apply/armor", 55+x);
			npc->set_temp("apply/parry", 50+x);
			npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "大理段家":
    {
        npc->set_temp("apply/dodge", 100);
            npc->set_temp("apply/damage", 40+x);
            npc->set_temp("apply/speed", 10+x);
            npc->set_temp("apply/armor", 55+x);
			npc->set_temp("apply/parry", 50+x);
			npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "古墓派":
    {
        npc->set_temp("apply/dodge", 150+x);
            npc->set_temp("apply/damage", 135+x);
            npc->set_temp("apply/speed", 100+x);
            npc->set_temp("apply/armor", 155+x);
			npc->set_temp("apply/parry", 50+x);
			npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "白驼山":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 80+x);
        npc->set_temp("apply/speed", 80+x);
        npc->set_temp("apply/armor", 125+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "华山派":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 80+x);
        npc->set_temp("apply/speed", 80+x);
        npc->set_temp("apply/armor", 125+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "雪山派":
    {
        npc->set_temp("apply/dodge", 150+x);
            npc->set_temp("apply/damage", 40+x);
            npc->set_temp("apply/speed", 10+x);
            npc->set_temp("apply/armor", 55+x);
			npc->set_temp("apply/parry", 50+x);
			npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "桃花岛":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 40+x);
        npc->set_temp("apply/speed", 10+x);
        npc->set_temp("apply/armor", 55+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "全真教":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 40+x);
        npc->set_temp("apply/speed", 10+x);
        npc->set_temp("apply/armor", 55+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    case "昆仑派":
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 40+x);
        npc->set_temp("apply/speed", 10+x);
        npc->set_temp("apply/armor", 55+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
        break;
    }
    default:
    {
        npc->set_temp("apply/dodge", 100+x);
        npc->set_temp("apply/damage", 40+x);
        npc->set_temp("apply/speed", 10+x);
        npc->set_temp("apply/armor", 55+x);
		npc->set_temp("apply/parry", 50+x);
		npc->set_temp("apply/defense", 100+x);
    }
    }

    CHANNEL_D->do_channel(this_object(), "sys", sprintf("杀手目标: %s(%s)  工作NPC: %s  工作型态: 主动刺杀行动", me->query("name"), me->query("id"), npc->query("name")));
    return;
}