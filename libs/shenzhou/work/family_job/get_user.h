int do_check_user(object ob, string strMenpai) 
{
    string strSwitch;

    if(ob->query("family/family_name") != strMenpai)
    {
        return 0;
    }

    if(ob->query("combat_exp") < 100000)
    {
        return 0;
    }

    if(!ob->query("env/family_job"))
    {
        return 0;
    
    }
    if(environment(ob)->query("no_fight"))
    {
        return 0;
    }
    return 1;
}


void get_player()
{
    object me, *players;
    string strName, strId, strFName, strMenpai, *MenpaiList;
        string strJobMsg;
    int i, j, total, intExp, count;


        switch(random(7))
        {
        case 0:
                {
                        strJobMsg = "东方";
                        break;
                }
        case 1:
                {
                        strJobMsg = "西方";
                        break;
                }
        case 2:
                {
                        strJobMsg = "南方";
                        break;
                }
        case 3:
                {
                        strJobMsg = "北方";
                        break;
                }
        case 4:
                {
                        strJobMsg = "东南方";
                        break;
                }
        case 5:
                {
                        strJobMsg = "东北方";
                        break;
                }
        case 6:
                {
                        strJobMsg = "西南方";
                        break;
                }
        case 7:
                {
                        strJobMsg = "西北方";
                        break;
                }
        }

        strJobMsg = strJobMsg + "的天空慢慢的";

        switch(random(4))
        {
        case 0:
                {
                        strJobMsg = strJobMsg + "亮了起来";
                        break;
                }
        case 1:
                {
                        strJobMsg = strJobMsg + "暗了下来";
                        break;
                }
        case 2:
                {
                        strJobMsg = strJobMsg + "变成红色";
                        break;
                }
        case 3:
                {
                        strJobMsg = strJobMsg + "布满了乌云";
                        break;
                }
        case 4:
                {
                        strJobMsg = strJobMsg + "出现了一颗流星";
                        break;
                }
        }

        strJobMsg = strJobMsg + "，这暗示著一场屠杀即将展开．";


        switch(random(5))
        {
        case 0:
                {
                        strJobMsg = HIR + strJobMsg;
                        break;
                }
        case 1:
                {
                        strJobMsg = HIC + strJobMsg;
                        break;
                }
        case 2:
                {
                        strJobMsg = HIB + strJobMsg;
                        break;
                }
        case 4:
                {
                        strJobMsg = HIG + strJobMsg;
                        break;
                }
        case 5:
                {
                        strJobMsg = HIW + strJobMsg;
                        break;
                }
        }

        CHANNEL_D->do_channel(this_object(), "rumor", sprintf(strJobMsg));
                
        /*
        if(random(100) > 90)
        {
                write("mark1\n");
                mplayer_get_user();
        }
        else
        {
        */

                MenpaiList = ({"武当派","少林派","丐帮","星宿派","峨嵋派","大理段家","古墓派","白驼山","华山派","雪山派","桃花岛","全真教","昆仑派"});
                for(i=0;i<sizeof(MenpaiList);i++)
                {
                        write("现在分配"+MenpaiList[i]+"的工作\n");
                        players = filter_array(users(), "do_check_user", this_object(), MenpaiList[i]);
                        if(!query("job_enable"))
                        {
                                write("门派工作终止\n");
                                return;
                        }
                        if(!sizeof(players))
                        {
                                write("现在"+MenpaiList[i]+"的工作没有人来做。\n");
                                continue;
                        }
                        else
                        {
                                total = sizeof(players);
                                j = random(total);
                                me = players[j];
                                write(me->query("name")+"\n");
                                write(me->query("id")+"\n");
                                write(me->query("combat_exp")+"\n");
                                write(me->query("family/family_name")+"\n");
                                
                                strName = me->query("name");
                                strId = me->query("id");
                                intExp = me->query("combat_exp");
                                strFName = me->query("family/family_name");

                                switch(random(3))
                                {
                case 0:
                                        {
                                                detect_menpai(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                case 1:
                                        {
                                                menpai_killer(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                                        
                case 2:
                                        {
                                                if ( (int)me->query( "menpai/gxd" ) > 200 )
                                                        menpai_question(me, strName, strId, strFName, intExp);
                                                else
                                                        detect_menpai(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                                        
                default:
                                        {
                                                detect_menpai(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                                }
                        }
                //}
        }
    final_count();
    return;
}

