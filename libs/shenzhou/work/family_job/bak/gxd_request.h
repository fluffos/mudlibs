// gxd_request.h
// Code by Scatter
#define SAVE_NPC "/family_job/savenpc"
inherit F_CLEAN_UP;

void tell_player_menpai_gxd(object me, object master)
{
        string strFNameP, strFNameM;
        string strMenpaiP, strMenpaiM;
        string ropen, fname;
        int mygxd;
        int fmygxd, fropen;

        strFNameP = me->query("family/family_name");
        strFNameM = master->query("family/family_name");

        switch(strFNameP)
        {
        case "武当派":
                {
                        strMenpaiP = "wd";
                        break;
                }
        case "少林派":
                {
                        strMenpaiP = "sl";
                        break;
                }
        case "丐帮":
                {
                        strMenpaiP = "gb";
                        break;
                }
        case "星宿派":
                {
                        strMenpaiP = "xx";
                        break;
                }
        case "峨嵋派":
                {
                        strMenpaiP = "em";
                        break;
                }
        case "大理段家":
                {
                        strMenpaiP = "dl";
                        break;
                }
        case "古墓派":
                {
                        strMenpaiP = "gm";
                        break;
                }
        case "白驼山":
                {
                        strMenpaiP = "bt";
                        break;
                }
        case "华山派":
                {
                        strMenpaiP = "hs";
                        break;
                }
        case "雪山派":
                {
                        strMenpaiP = "xs";
                        break;
                }
        case "桃花岛":
                {
                        strMenpaiP = "th";
                        break;
                }
        case "全真教":
                {
                        strMenpaiP = "qz";
                        break;
                }
        case "昆仑派":
                {
                        strMenpaiP = "kl";
                        break;
                }
        default:
                {
                        strMenpaiP = "error";
                }
        }



        switch(strFNameM)
        {
        case "武当派":
                {
                        strMenpaiM = "wd";
                        break;
                }
        case "少林派":
                {
                        strMenpaiM = "sl";
                        break;
                }
        case "丐帮":
                {
                        strMenpaiM = "gb";
                        break;
                }
        case "星宿派":
                {
                        strMenpaiM = "xx";
                        break;
                }
        case "峨嵋派":
                {
                        strMenpaiM = "em";
                        break;
                }
        case "大理段家":
                {
                        strMenpaiM = "dl";
                        break;
                }
        case "古墓派":
                {
                        strMenpaiM = "gm";
                        break;
                }
        case "白驼山":
                {
                        strMenpaiM = "bt";
                        break;
                }
        case "华山派":
                {
                        strMenpaiM = "hs";
                        break;
                }
        case "雪山派":
                {
                        strMenpaiM = "xs";
                        break;
                }
        case "桃花岛":
                {
                        strMenpaiM = "th";
                        break;
                }
        case "全真教":
                {
                        strMenpaiM = "qz";
                        break;
                }
        case "昆仑派":
                {
                        strMenpaiM = "kl";
                        break;
                }
        default:
                {
                        strMenpaiM = "error";
                }
        }


        if( strMenpaiM == "error" )
        {
                message_vision(CYN"$n对$N说道：这位壮士问错人了吧？我怎么知道那种事情呢。\n", me, master);
                return;
        }

        if( strMenpaiP == "error" )
        {
                message_vision(CYN"$n对$N说道：这位壮士问错人了吧？我怎么知道那种事情呢。\n", me, master);
                return;
        }

        if( strMenpaiM != strMenpaiP )
        {
                message_vision(CYN"$n对$N说道：这位壮士问错人了吧？我怎么知道那种事情呢。\n", me, master);
                return;
        }

        fname = "family_job/"+strMenpaiP;
        ropen = SAVE_NPC->do_load(fname);
        mygxd = me->query("menpai/gxd");
        fropen = atoi(ropen);

        
        message_vision(CYN"$n对$N说道：目前本门派的贡献度为"+ chinese_number(fropen) + "点。\n", me, master);
        message_vision(CYN"$n对$N说道：你为本门派所做的贡献为"+ chinese_number(mygxd) + "点。你要继续努力，争取在下次门派大会上得到最佳评定。\n", me, master);
        message_vision(CYN"$n说道：当门派贡献度达到三千五百时，就召开下次的门派大会。\n", me, master);

                if(!master->query_temp("meeting"))
                {
                        if(fropen > 3499)
                        {
                                CHANNEL_D->do_channel(master, "chat", sprintf("全部%s弟子听好了，%s门派大会将在五分钟后开始，如果不出席则当自动弃权。", master->query("family/family_name"), master->query("family/family_name")));
                                master->set_temp("meeting", 1);
                                call_out("do_meeting", 300, master);
                        }
                }

        return;

}

int do_meeting(object master)
{
        object obj, *inv, pid;
        mapping skill_status;
        int i, j, gxd1, gxd2, gxd;
        string *id, straward;
        string *sname;
        string fname, ropen, strFNameP, strMenpaiP, rndnums;
        int k, point, count, new_shen, new_exp, new_pot, rndnum;

        inv = all_inventory(environment(master));
        if( !sizeof(inv) )
                return notify_fail("这里没有任何东西。\n");
        
        for(i=0; i<sizeof(inv); i++) 
        {
                if( !master->visible(inv[i]) )
                {
                        continue;
                }

                if(inv[i]->query("family/family_name") != master->query("family/family_name"))
                {
                        continue;
                }

                if(!gxd1)
                {
                        gxd1=inv[i]->query("menpai/gxd");
                        pid = inv[i];
                        continue;
                }

                gxd2 = inv[i]->query("menpai/gxd");
                
                if(gxd2 > gxd1)
                {
                        pid = inv[i];
                        continue;
                }
                
        }

        CHANNEL_D->do_channel(master, "chat", sprintf("恭喜%s弟子%s(%s)获得奖励。", master->query("family/family_name"), pid->query("name"), pid->query("id")));

        gxd = pid->query("menpai/gxd");


        if(gxd > 3000)
        {
                straward="奖励一万点经验直，三千点潜能，二十点内力，以及武功等级全部上升三级";
                
                if ( mapp(skill_status = pid->query_skills()) ) 
                {
                        skill_status = pid->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)/2+1;
                                while ( (point /= 2) > 0 )
                                        pid->improve_skill(sname[k], point+3); 
                        }
                }

                pid->add("max_neili", 20);
                pid->add("combat_exp", 10000);
                pid->add("potential", 3000);
                
        }


        else if(gxd > 2400)
        {
                straward="奖励七千点经验直，两千五百点潜能，十五点内力，以及武功等级全部上升两级";
                
                if ( mapp(skill_status = pid->query_skills()) ) 
                {
                        skill_status = pid->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)/2+1;
                                while ( (point /= 2) > 0 )
                                        pid->improve_skill(sname[k], point+2); 
                        }
                }

                pid->add("max_neili", 15);
                pid->add("combat_exp", 7000);
                pid->add("potential", 2500);
                
        }

        else if(gxd > 1500)
        {
                straward="奖励五千点经验直，一千五百点潜能，十点内力，以及武功等级全部上升一级";
                
                if ( mapp(skill_status = pid->query_skills()) ) 
                {
                        skill_status = pid->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)/2+1;
                                while ( (point /= 2) > 0 )
                                        pid->improve_skill(sname[k], point+1); 
                        }
                }

                pid->add("max_neili", 10);
                pid->add("combat_exp", 5000);
                pid->add("potential", 1500);
                
        }


        else if(gxd > 870)
        {
                straward="奖励三千点经验直，五百点潜能，以及五点内力";

                pid->add("max_neili", 5);
                pid->add("combat_exp", 3000);
                pid->add("potential", 500);
        }


        else if(gxd > 350)
        {
                straward="奖励一千点经验直，以及五百点潜能";

                pid->add("combat_exp", 1000);
                pid->add("potential", 500);
                
        }


        else
        {
                straward="奖励五百点经验直，以及两百五十点潜能";

                pid->add("combat_exp", 500);
                pid->add("potential", 250);
                
        }

        rndnum = random(5999);

        strFNameP = master->query("family/family_name");
                        switch(strFNameP)
                        {
                        case "武当派":
                                {
                                        strMenpaiP = "wd";
                                        break;
                                }
                        case "少林派":
                                {
                                        strMenpaiP = "sl";
                                        break;
                                }
                        case "丐帮":
                                {
                                        strMenpaiP = "gb";
                                        break;
                                }
                        case "星宿派":
                                {
                                        strMenpaiP = "xx";
                                        break;
                                }
                        case "峨嵋派":
                                {
                                        strMenpaiP = "em";
                                        break;
                                }
                        case "大理段家":
                                {
                                        strMenpaiP = "dl";
                                        break;
                                }
                        case "古墓派":
                                {
                                        strMenpaiP = "gm";
                                        break;
                                }
                        case "白驼山":
                                {
                                strMenpaiP = "bt";
                                break;
                                }
                        case "华山派":
                                {
                                        strMenpaiP = "hs";
                                        break;
                                }
                        case "雪山派":
                                {
                                        strMenpaiP = "xs";
                                        break;
                                }
                        case "桃花岛":
                                {
                                        strMenpaiP = "th";
                                        break;
                                }
                        case "全真教":
                                {
                                        strMenpaiP = "qz";
                                        break;
                                }
                        case "昆仑派":
                                {
                                        strMenpaiP = "kl";
                                        break;
                                }
                        default:
                                {
                                        strMenpaiP = "error";
                                }
                        }


        CHANNEL_D->do_channel(master, "chat", straward);
        master->delete_temp("meeting");

        write("mark1\n");
        fname = "family_job/password/"+strMenpaiP;
        rndnums = "" + rndnum;
    SAVE_NPC->do_save(fname, rndnum);
        
        
        write("mark2\n");
        fname = "family_job/"+strMenpaiP;
        rndnums = "0";
        
        write("mark3\n");
    SAVE_NPC->do_save(fname, rndnum);
        write("mark4\n");

        return 1;
}