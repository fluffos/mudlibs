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
			strSwitch = environment(ob)->query("no_fight");
		}
		else
		{
			strSwitch = "0";
		}


		if(strSwitch == "1")
		{
			return 0;
		}


        return 1;
}


void get_player()
{
        object me, *players;
        string strName, strId, strFName, strMenpai, *MenpaiList;
        int i, j, total, intExp, count;

        MenpaiList = ({"武当派","少林派","丐帮","星宿派","峨嵋派","大理段家","古墓派","白驼山","华山派","雪山派","桃花岛","全真教","昆仑派"});
        
        for(i=0;i<sizeof(MenpaiList);i++){
                write("现在分配"+MenpaiList[i]+"的工作\n");
                players = filter_array(users(), "do_check_user", this_object(), MenpaiList[i]);
                if(!query_temp("job_enable")){
                        write("工作终止\n");
                        return;
                }
                if(!sizeof(players)){
                        write("现在"+MenpaiList[i]+"的工作没有人来做。\n");
                         continue;
                }else{
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
                                                menpai_question(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                
                                default:
                                        {
                                                detect_menpai(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                        }
                }
        }
        final_count();
        return;
}