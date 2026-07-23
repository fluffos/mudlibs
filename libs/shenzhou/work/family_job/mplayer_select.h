int do_mp_check_user(object ob, string strMenpai) 
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



    if(!ob->query("env/beta_family_job"))
    {
        return 0;
    
    }


    if(environment(ob)->query("no_fight"))
    {
        return 0;
    }
    return 1;
}

void mplayer_get_user()
{
        object me, *players;
    string strName, strId, strFName, strMenpai, *MenpaiList;
        string strJobMsg;
    int i, j, total, intExp, count;


        plist = allocate(13);
        k = 0;
    MenpaiList = ({"武当派","少林派","丐帮","星宿派","峨嵋派","大理段家","古墓派","白驼山","华山派","雪山派","桃花岛","全真教","昆仑派"});

    for(i=0;i<sizeof(MenpaiList);i++)
    {
        write("现在分配"+MenpaiList[i]+"的工作\n");
        players = filter_array(users(), "do_mp_check_user", this_object(), MenpaiList[i]);
        /*
                if(!query("job_enable"))
        {
                        write("门派工作终止\n");
            return;
        }
                */
        if(!sizeof(players))
        {
            write("现在"+MenpaiList[i]+"的工作没有人来做。\n");
            continue;
        }
        else
        {
            total = sizeof(players);
            j = random(total);
                        plist[k] = players[j];
                        k = k + 1;
                }
        }
        do_mp_setup();
}
