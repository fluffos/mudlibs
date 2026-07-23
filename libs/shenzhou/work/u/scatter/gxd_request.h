// gxd_request.h
// Code by Scatter
#define SAVE_NPC "/family_job/savenpc"

void tell_player_menpai_gxd(object me, object master)
{
        string strFNameP, strFNameM;
        string strMenpaiP, strMenpaiM;
        string ropen, fname, fnamepk, ropenk;
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

		//RESET CODE
		fnamepk = "family_job/password/"+strMenpaiP;
		ropenk = SAVE_NPC->do_load(fnamepk);
		if(ropenk != "NA")
		{
			if(me->query("family_job/password") != ropenk)
			{
                me->delete("menpai/gxd");
				me->set("menpai/gxd", 0);
				me->set("family_job/password", ropenk);
			}
		}
        
		
		fname = "family_job/"+strMenpaiP;
        ropen = SAVE_NPC->do_load(fname);
        mygxd = me->query("menpai/gxd");
        fropen = atoi(ropen);
        
        message_vision(CYN"$n对$N说道：目前本门派的忠诚度为"+ chinese_number(fropen) + "点。\n", me, master);
        message_vision(CYN"$n对$N说道：你对本门派的忠诚度为"+ chinese_number(mygxd) + "点。你要继续努力，争取在下次门派大会上得到最佳评定。\n", me, master);
        message_vision(CYN"$n说道：当门派忠诚度达到三千五百时，就召开下次的门派大会。\n", me, master);

                if(!master->query_temp("meeting"))
                {
                        if(fropen > 3499)
                        {
                                CHANNEL_D->do_channel(master, "chat", sprintf("全部%s弟子听好了，%s门派大会将在五分钟后开始，如果不出席则当自动弃权。", master->query("family/family_name"), master->query("family/family_name")));
                                master->set_temp("meeting", 1);
                                call_out("do_meeting", 300, master, fropen);
                        }
                }

        return;

}

int do_meeting(object master, int fropen)
{

	// DEFINE VARIBLES
        object obj, *inv, pid1, pid2, pid3;
        mapping skill_status;
        int i, j, z, gxd1=0, gxd2=0, gxd3=0, gxd;
        string *id, straward;
        string *sname;
        string fname, ropen, strFNameP, strMenpaiP, rndnums;
        int k, point, count, new_shen, new_exp, new_pot, rndnum;

        inv = all_inventory(environment(master));
        if( !sizeof(inv) )
                return notify_fail("这里没有任何东西。\n");
        

		if(fropen < 3499)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("全部%s弟子听好了，由于%s门派大会已经开过了，所以取消重复会议。", master->query("family/family_name"), master->query("family/family_name")));
			return 1;
		}


		// Find the Rank
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

                if(gxd1==0)
                {
                        gxd1=inv[i]->query("menpai/gxd");
                        pid1 = inv[i];
                        continue;
                }


				gxd = inv[i]->query("menpai/gxd");


				if(gxd > gxd1)
				{
						gxd2=gxd1;
						gxd1=inv[i]->query("menpai/gxd");
						pid2=pid1;
						pid1 = inv[i];
						continue;
				}

				if(gxd2==0)
				{
						gxd2=inv[i]->query("menpai/gxd");
						pid2 = inv[i];
						continue;
				}

				if(gxd > gxd2)
				{
						gxd3=gxd2;
						gxd2=inv[i]->query("menpai/gxd");
						pid3=pid2;
						pid2 = inv[i];
						continue;
				}

				if(gxd3==0)
				{
						gxd3=inv[i]->query("menpai/gxd");
						pid3 = inv[i];
						continue;
				}
         
		}



		// RESET EVERYONE'S GXD on PRESENT
		for(z=0; z<sizeof(inv); z++) 
        {
			inv[z]->set("menpai/gxd", 0);
        }



		// ERROR CHECKING, IF NO SUCH ID
		if(gxd1!=0)
		{
			if(pid1->query("id") == master->query("id"))
			{
				gxd1=0;
			}
		}

        // ERROR CHECKING, IF NO SUCH ID
		if(gxd2!=0)
		{
			if(pid2->query("id") == master->query("id"))
			{
				gxd2=0;
			}
		}


		// ERROR CHECKING, IF NO SUCH ID
		if(gxd3!=0)
		{
			if(pid3->query("id") == master->query("id"))
			{
				gxd3=0;
			}
		}


		// DISPLAY MESSAGE
		if(gxd1==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("第一名无人获得。"));
		}
		else
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("恭喜%s弟子%s(%s)获得第一名。", master->query("family/family_name"), pid1->query("name"), pid1->query("id")));
		}


		if(gxd2==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("第二名无人获得。"));
		}
		else
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("恭喜%s弟子%s(%s)获得第二名。", master->query("family/family_name"), pid2->query("name"), pid2->query("id")));
		}

		if(gxd3==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("第三名无人获得。"));
		}
		else
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("恭喜%s弟子%s(%s)获得第三名。", master->query("family/family_name"), pid3->query("name"), pid3->query("id")));
		}
		

		if(gxd1==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("很可惜的这次%s没有人出席门派会议。", master->query("family/family_name")));
		}
		else
		{

			// START TO REWARD Player
        if(gxd1 > 2800)
        {
                straward="第一名奖励一万点经验直，三千点潜能，二十点内力，以及武功等级全部上升三级\n";
                
                if ( mapp(skill_status = pid1->query_skills()) ) 
                {
                        skill_status = pid1->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
                }

                pid1->add("max_neili", 20);
                pid1->add("combat_exp", 10000);
                pid1->add("potential", 3000);
                
        }


        else if(gxd1 > 2200)
        {
                straward="第一名奖励七千点经验直，两千五百点潜能，十五点内力，以及武功等级全部上升两级\n";
                
                if ( mapp(skill_status = pid1->query_skills()) ) 
                {
                        skill_status = pid1->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+2); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }

                }

                pid1->add("max_neili", 15);
                pid1->add("combat_exp", 7000);
                pid1->add("potential", 2500);
                
        }

        else if(gxd1 > 1300)
        {
                straward="第一名奖励五千点经验直，一千五百点潜能，十点内力，以及武功等级全部上升一级\n";
                
                if ( mapp(skill_status = pid1->query_skills()) ) 
                {
                        skill_status = pid1->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
                }

                pid1->add("max_neili", 10);
                pid1->add("combat_exp", 5000);
                pid1->add("potential", 1500);
                
        }


        else if(gxd1 > 670)
        {
                straward="第一名奖励三千点经验直，五百点潜能，以及五点内力\n";

                pid1->add("max_neili", 5);
                pid1->add("combat_exp", 3000);
                pid1->add("potential", 500);
        }


        else if(gxd1 > 150)
        {
                straward="第一名奖励一千点经验直，以及五百点潜能\n";

                pid1->add("combat_exp", 1000);
                pid1->add("potential", 500);
                
        }


        else
        {
                straward="第一名奖励五百点经验直，以及两百五十点潜能\n";

                pid1->add("combat_exp", 500);
                pid1->add("potential", 250);
                
        }
		
}
		
		//第二名开始

		if(gxd2==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("很可惜的这次%s没有人出席门派会议。", master->query("family/family_name")));
		}
		else
		{
		if(gxd2 > 2800)
        {
                straward = straward + "第二名奖励一万点经验直，三千点潜能，二十点内力，以及武功等级全部上升三级\n";
                
                if ( mapp(skill_status = pid2->query_skills()) ) 
                {
                        skill_status = pid2->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+3); 
                        }
                }

                pid2->add("max_neili", 20);
                pid2->add("combat_exp", 10000);
                pid2->add("potential", 3000);
                
        }


        else if(gxd2 > 2200)
        {
                straward = straward + "第二名奖励七千点经验直，两千五百点潜能，十五点内力，以及武功等级全部上升两级\n";
                
                if ( mapp(skill_status = pid2->query_skills()) ) 
                {
                        skill_status = pid2->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+2); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+2); 
                        }
                }

                pid2->add("max_neili", 15);
                pid2->add("combat_exp", 7000);
                pid2->add("potential", 2500);
                
        }

        else if(gxd2 > 1300)
        {
                straward = straward + "第二名奖励五千点经验直，一千五百点潜能，十点内力，以及武功等级全部上升一级\n";
                
                if ( mapp(skill_status = pid2->query_skills()) ) 
                {
                        skill_status = pid2->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+1); 
                        }
                }

                pid2->add("max_neili", 10);
                pid2->add("combat_exp", 5000);
                pid2->add("potential", 1500);
                
        }


        else if(gxd2 > 670)
        {
                straward = straward + "第二名奖励三千点经验直，五百点潜能，以及五点内力\n";

                pid2->add("max_neili", 5);
                pid2->add("combat_exp", 3000);
                pid2->add("potential", 500);
        }


        else if(gxd2 > 150)
        {
                straward = straward + "第二名奖励一千点经验直，以及五百点潜能\n";

                pid2->add("combat_exp", 1000);
                pid2->add("potential", 500);
                
        }


        else
        {
                straward = straward + "第二名奖励五百点经验直，以及两百五十点潜能\n";

                pid2->add("combat_exp", 500);
                pid2->add("potential", 250);
                
        }

		}




		//第三名开始

		if(gxd3==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("很可惜的这次%s没有人出席门派会议。", master->query("family/family_name")));
		}
		else
		{

		if(gxd3 > 2800)
        {
                straward = straward + "第三名奖励一万点经验直，三千点潜能，二十点内力，以及武功等级全部上升三级\n";
                
                if ( mapp(skill_status = pid3->query_skills()) ) 
                {
                        skill_status = pid3->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+3); 
                        }
                }

                pid3->add("max_neili", 20);
                pid3->add("combat_exp", 10000);
                pid3->add("potential", 3000);
                
        }


        else if(gxd3 > 2200)
        {
                straward = straward + "第三名奖励七千点经验直，两千五百点潜能，十五点内力，以及武功等级全部上升两级\n";
                
                if ( mapp(skill_status = pid3->query_skills()) ) 
                {
                        skill_status = pid3->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+2); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+2); 
                        }
                }

                pid3->add("max_neili", 15);
                pid3->add("combat_exp", 7000);
                pid3->add("potential", 2500);
                
        }

        else if(gxd3 > 1300)
        {
                straward = straward + "第三名奖励五千点经验直，一千五百点潜能，十点内力，以及武功等级全部上升一级\n";
                
                if ( mapp(skill_status = pid3->query_skills()) ) 
                {
                        skill_status = pid3->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+1); 
                        }
                }

                pid3->add("max_neili", 10);
                pid3->add("combat_exp", 5000);
                pid3->add("potential", 1500);
                
        }


        else if(gxd3 > 670)
        {
                straward = straward + "第三名奖励三千点经验直，五百点潜能，以及五点内力\n";

                pid3->add("max_neili", 5);
                pid3->add("combat_exp", 3000);
                pid3->add("potential", 500);
        }


        else if(gxd3 > 150)
        {
                straward = straward + "第三名奖励一千点经验直，以及五百点潜能\n";

                pid3->add("combat_exp", 1000);
                pid3->add("potential", 500);
                
        }


        else
        {
                straward = straward + "第三名奖励五百点经验直，以及两百五十点潜能\n";

                pid3->add("combat_exp", 500);
                pid3->add("potential", 250);
                
        }
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

        fname = "family_job/password/"+strMenpaiP;
        rndnums = "" + rndnum;
		SAVE_NPC->do_save(fname, rndnum);
        
		fname = "family_job/"+strMenpaiP;
        rndnums = "0";

	    SAVE_NPC->do_save(fname, rndnum);
        return 1;
}