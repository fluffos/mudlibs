//Cracked by Kafei
//job_searchitem.h
//wzfeng@xkx 2000 7
//assign a job what is search item .
string *item_name=({"内功心法","武功精要","弟子名册","帐薄","机密函件"});
string *main_area=({"中原","江南","南疆","西域","东北"});
void searchitem_job(object master,object player,mapping job)
{
	string area_1,search_item_name;
	area_1=main_area[random(sizeof(main_area))];
	search_item_name="〖"+master->query("family/family_name")+item_name[random(sizeof(item_name))]+"〗";
	get_job_palce_msg(master,player,search_item_name,"search","search_job");
		//add job message in dab_data
	/**************************************************************************/
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	/****get this player job mapping from job data.*/
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	job_map["job_search_frist_chinese"]=area_1;
	job_map["job_search_obj_name"]=search_item_name;
	job_map["job_search_time"]=time();

	map_delete(job_map,"job_askjob"); 
	map_delete(job_map,"job_command_mode"); 
	map_delete(job_map,"job_master_prompt_time"); 
	job_data->modify_job_data(job_map["job_player"],job_map);
	job_data->save();
	//player->set("family_job/search_item",search_item_name);
	/****************************************************************************/
}

void tell_player_search_place(object player,object master)
{
	string *ask_list,two_area,place,room_name,region;
	object room;

	ask_list=({});
	ask_list=player->query_temp("family_job/ask_list");

/*	if(is_attribute(master->query("id"),ask_list))
	{
		message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"刚才不是问过了吗？"
		+RANK_D->query_self(master)+"不能多言。\n" NOR, player, master);
		return;
	}
	*/
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	//
	if(!mapp(job_map)||
		undefinedp(job_map["job_search_frist_chinese"])
		)
	{
		message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"问错人了吧？"
		+RANK_D->query_self(master)+"怎么知道那种事情呢。\n" NOR, player, master);
		ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);

		return;
	}

	message_vision(CYN "$N对$n说道：敢问这位"+RANK_D->query_respect(master)+"是否知道关于"
		+job_map["job_search_obj_name"]+"的下落？\n" NOR, player, master);
	if(master->query("id")==job_map["job_master"])
	{
		message_vision(CYN "$n对$N说道：我不是要你去找了吗？你还呆在这里做什么？还不快去！\n" NOR, player, master);
		return;
	}
	if(undefinedp(job_map["job_search_two_chinese"]))
		if(master->query("family/family_name")==player->query("family/family_name")
			&&random(2)==0)
	{
			
			
		message_vision(CYN "$n对$N说道：这"+job_map["job_search_obj_name"]+"曾听说在"+job_map["job_search_frist_chinese"]+"一带出现过，这位"+
		RANK_D->query_respect(player)+"可去"+job_map["job_search_frist_chinese"]+"打探进一步的消息。\n" NOR, player, master);
		ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);
		
		job_map["job_search_two_chinese"]=1;

		job_data->modify_job_data(job_map["job_player"],job_map);
		job_data->save();
		return;
	}
	else
	{
		message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"问错人了吧？"
		+RANK_D->query_self(master)+"怎么知道那种事情呢。\n" NOR, player, master);
		ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);

		return;
	}
	if(undefinedp(job_map["job_search_three_chinese"])&&
		random(2)==0&&
		(!undefinedp(job_map["job_search_two_chinese"]))
		)
	{
		place=explode(file_name(environment(master)),"/")[1];
		write(place+job_map["job_search_frist_chinese"]);
		switch(job_map["job_search_frist_chinese"])
		{
			
		case "中原":
			if(is_attribute(place,zhongyuan))
				master->set_temp("family_job/nowplace",1);
			break;
		case "南疆":
			if(is_attribute(place,nanjiang))
				master->set_temp("family_job/nowplace",1);

			break;
		case "西域":
			if(is_attribute(place,xiyu))
				master->set_temp("family_job/nowplace",1);

			break;
		case "江南":
			if(is_attribute(place,jiangnan))
				master->set_temp("family_job/nowplace",1);

			break;
		case "东北":
			if(is_attribute(place,dongbei))
				master->set_temp("family_job/nowplace",1);

			break;
		}
		if(!master->query_temp("family_job/nowplace"))
		{
		message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"问错人了吧？"
		+RANK_D->query_self(master)+"怎么知道那种事情呢。\n" NOR, player, master);
		ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);

		return;
		}
		room_name=get_room(job_map["job_search_frist_chinese"]);
		if(!room_name)
		{
		//printf("房间没有找到，请联系wiz.\n");
		return;
		}
		if(!room=find_object(room_name))
			room=load_object(room_name);
		if(!objectp(room))
			{
			//printf("房间%s创建错误，请联系wiz.\n",room_name);
			return;
			}
		//confirm room area by region.
		if ( strsrch(file_name(room), "/d/") != 0       
			||  undefinedp(region = region_names[explode(file_name(room), "/")[1]]))
					region = "";
		message_vision(CYN "$n对$N说道：这"+job_map["job_search_obj_name"]+"曾听说在"+region+"一带出现过，这位"+
		RANK_D->query_respect(player)+"可去"+region+"打探进一步的消息。\n" NOR, player, master);
		ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);
		
		job_map["job_search_three_chinese"]=room_name;

		job_data->modify_job_data(job_map["job_player"],job_map);
		job_data->save();
		return;
	}
	if(undefinedp(job_map["job_search_start"])&&
		random(2)==0&&
		(!undefinedp(job_map["job_search_three_chinese"]))
		)
	{
		place=explode(file_name(environment(master)),"/")[1];
		room_name=job_map["job_search_three_chinese"];
		write(place+explode(room_name,"/")[1]);
		if(place!=explode(room_name,"/")[1])
		{
		message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"问错人了吧？"
		+RANK_D->query_self(master)+"怎么知道那种事情呢。\n" NOR, player, master);
		ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);

		return;

		}
		if(!room=find_object(room_name))
			room=load_object(room_name);
		if(!objectp(room))
			{
			printf("房间%s创建错误，请联系wiz.\n",room_name);
			return;
			}

		message_vision(CYN "$n对$N说道：这件事情你问我算是找对人了，这"+job_map["job_search_obj_name"]+
			"在一个行踪诡异的蒙面人手上，我估计他现在正在"+room->query("short")+"附近。\n"+
			RANK_D->query_respect(player)+"要是立刻赶去，说不定还能见到。\n" NOR, player, master);
		player->set_temp("family_job/ask_list",ask_list);
		job_map["job_search_start"]=1;
		job_data->modify_job_data(job_map["job_player"],job_map);
		job_data->save();
		return;
	}
	message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"问错人了吧？"
		+RANK_D->query_self(master)+"怎么知道那种事情呢。\n" NOR, player, master);
	ask_list=add_string(master->query("id"),ask_list);
		player->set_temp("family_job/ask_list",ask_list);

		return;

}

