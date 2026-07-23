//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//**********************    Menpai Job Star Here  *****************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void detect_menpai(object me, string strName, string strId, string strFName, int intExp)
{
        string strMenpai, strMsg, strDir, strCPlace;
        int intRnd;

        switch(strFName)
        {
        case "武当派":
                {
                        strMenpai = "wd";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "少林派":
                {
                        strMenpai = "sl";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "丐帮":
                {
                        strMenpai = "gb";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "星宿派":
                {
                        strMenpai = "xx";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "峨嵋派":
                {
                        strMenpai = "em";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "大理段家":
                {
                        strMenpai = "dl";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "古墓派":
                {
                        strMenpai = "gm";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "白驼山":
                {
                        strMenpai = "bt";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "华山派":
                {
                        strMenpai = "hs";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "雪山派":
                {
                        strMenpai = "xs";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "桃花岛":
                {
                        strMenpai = "th";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "全真教":
                {
                        strMenpai = "qz";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "昆仑派":
                {
                        strMenpai = "kl";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        default:
                {
                        write("错误资讯 "+strFName+"\n");
                        get_player();
                        return;
                }
        }

        switch(random(13))
        {
        case 0:
                {
                        strDir = "baituo";
                        strCPlace = "白驼";
                        break;
                }
        case 1:
                {
                        strDir = "beijing";
                        strCPlace = "北京";
                        break;
                }
        case 2:
                {
                        strDir = "changan";
                        strCPlace = "长安";
                        break;
                }
        case 3:
                {
                        strDir = "changbai";
                        strCPlace = "长白";
                        break;
                }
        case 4:
                {
                        strDir = "city";
                        strCPlace = "扬洲城";
                        break;
                }
        case 5:
                {
                        //strDir = "taohua";
                        //strCPlace = "桃花";
						strDir = "city";
                        strCPlace = "扬洲城";
                        break;
                }
        case 6:
                {
                        strDir = "gumu";
                        strCPlace = "古墓";
                        break;
                }
        case 7:
                {
                        strDir = "huashan";
                        strCPlace = "华山";
                        break;
                }
        case 8:
                {
                        //strDir = "wudang";
                        //strCPlace = "武当";
						strDir = "huashan";
                        strCPlace = "华山";
                        break;
                }
        case 9:
                {
                        strDir = "xingxiu";
                        strCPlace = "星宿";
                        break;
                }
        case 10:
                {
                        strDir = "xixia";
                        strCPlace = "西夏";
                        break;
                }
		case 11:
				{
						strDir = "emei";
						strCPlace = "峨嵋";
						break;
				}
		case 12:
				{
						strDir = "xueshan";
						strCPlace = "雪山";
						break;
				}
        default:
                {
                        strDir = "taishan";
                        strCPlace = "泰山";
                        break;
                }
        }

        strDir = "/d/"+strDir+"/";

        create_path(me, strName, strId, strFName, intExp, strMenpai, strMsg, strDir, strCPlace);
        return;
}

void create_path(object me, string strName, string strId, string strFName, int intExp, string strMenpai, string strMsg, string strDir, string strCPlace)
{
        string *dir, *dirx, roomx;
        object npc, room;
        int i, j;

                dirx = get_dir(strDir);
        
                j = random(sizeof(dirx) - 1);
				roomx = strDir+dirx[j];
                write(HIC"\n现在的随机房间是"+roomx+"。\n"NOR);
        if ( !(room = find_object(roomx)) )
                {
                        room = load_object(roomx);
                }
        if(room==0)
        {
                write(HIR"error : room = 0\nSELF RESTART\n"NOR);
        	create_path(me, strName, strId, strFName, intExp, strMenpai, strMsg, strDir, strCPlace);
                return ;
        }
	do_set_skill(me, room, strMsg, strDir, strCPlace, roomx);
        return;
}


void do_set_skill(object me, object room, string strMsg, string strDir, string strCPlace, string roomx)
{
        object ob, npc;
        string pkid;
        write("skill_set\n");

        npc = new("/family_job/heyiren");
        if (!objectp(npc))
        {
                write(HIC"\nNPC error!\n");
                final_count();
                return;
        }

        copy_skill(npc, me);
        pkid = me->query("id");
        npc->set_temp("pkid", pkid);
        npc->move(room);

        create_msg(me, room, strMsg, strDir, npc, strCPlace);
        return;
}

private int copy_skill(object npc, object me)
{
        object pid, *list;
        mapping hp_status, skill_status, map_status, prepare_status;
		mapping my;
        mapping skill_statusb;
        string *sname, *mname, *pname;
        string *snameb;
    int i, temp, myexp, mylvl, k, count, point;
        int j, total, looptime, m;
        
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
        my["qi"]         = hp_status["qi"];
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

        return 1;
}


void create_msg(object me, object room, string strMsg, string strDir, object npc, string strCPlace)
{
        if(me==0)
        {
                write(HIR"error : me = 0\nSELF RESTART\n"NOR);          
                return;
        }

        //strMsg = strMsg + HIW"掌门人要$N去" + room->query("short") + "位于"+strCPlace+"把" + npc->query("name") + "杀掉\n\n(V 4.0 正式版)\n"NOR;
		strMsg = strMsg + HIW"掌门人要$N去" + room->query("short") + "位于"+strCPlace+"把" + npc->query("name") + "杀掉" + HIW + vermsg + NOR;
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("工作玩家: %s(%s)  工作NPC: %s  工作地点: %s位于%s。", me->query("name"), me->query("id"), npc->query("name"), room->query("short"), strCPlace));
        write(strMsg);
        message_vision(strMsg, me);
        return;
}
