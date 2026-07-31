//Cracked by Kafei
//oppose_pker.h
//author wzfeng@xkx 2000 6
//create a oppose job.


void oppose_pker(object master,object player,mapping job)
{
	string area,room_name,region;
	object room;
	int ret;
	ret=0;
	area=job["job_area"];
	room_name=get_room(area);
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

	get_job_palce_msg(master,player,region+room->query("short"),"pk_npc","oppose_pker");
	//add job message in dab_data
	/**************************************************************************/
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	/****get this player job mapping from job data.*/
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	job_map["job_oppose_pker_place"]=room_name;
	job_map["job_oppose_pker_time"]=time();
	job_map["job_oppose_pker_mode"]="npc";
	job_map["job_oppose_pker_place_chinses"]=region+room->query("short");

	map_delete(job_map,"job_askjob"); 
	map_delete(job_map,"job_command_mode"); 
	map_delete(job_map,"job_master_prompt_time"); 
	job_data->modify_job_data(job_map["job_player"],job_map);
	
	
	job_data->save();
	/****************************************************************************/
	//destruct(room);


}
void out_killer(object player,object place)
{
	object killer;

	if(file_name(environment(player))==file_name(place))
	{
	
	killer=new("/clone/obj/job/job_s_opker");
	if(!objectp(killer)) return;
	killer->set_status(player);
	if(!killer->move(environment(player)))
		return;
	
	message("vision", HIR"突然间一个"+killer->name(1)+"不知从哪里跳了出来。\n"
		"“受死吧，"+player->query("name")+"！”"+killer->name(1)+"大声吼道。\n"NOR, environment(player), killer);
	killer->kill_ob(player);
	player->kill_ob(killer);
	player->set_temp("job_system/kill_killer",1);

	}
	else
		tell_object(player,HIB"你觉得四周的气氛恢复了正常。\n"NOR);
}

//start oppose job.
void job_oppsse_pker_start(object player)
{
	if(player->query_temp("job_system/start_prompt"))
	{
		return;
	}
	tell_object(player,HIB"你察觉四周好像有些不对劲......\n"NOR);
	player->set_temp("job_system/start_prompt",1);
//	remove_call_out("out_killer");
//	call_out( "out_killer",5+random(5),player,environment(player)); 
	out_killer(player,environment(player));

}
void award_oppose_pker(object player)
{
	object master,place,menpai_ob;
	
	string mname,pname,msg_room,msg_player;
	int time1,time2,luck;
	
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	msg_room="";
	msg_player="";
	
	if(!(place=find_object(job_map["job_master_place"])))
		place=load_object(job_map["job_master_place"]);

	if(!objectp(place))
		return;
	if(!objectp(master = present(job_map["job_master"],
						 place
						 )))
                return;
	mname=master->query("name");
	pname=player->query("name");
	master_msg(master,player,"opposepk_award","award");
	
	//******************award***************************
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	if(!objectp(menpai_ob)) return;
	menpai_ob->restore();
	
	if(!luck=menpai_ob->query_luck(player->query("family/family_name")))
		luck=random(5);
	
	time1=job_map["job_oppose_pker_time"];
	time2=job_map["job_oppose_pker_finish_time"];
	award_job(300+random(300),
			120,
			time1,
			time2,
			luck,
			0,
			0,
			0,
			player,
			master,
			"oppose_pker");
	
}
