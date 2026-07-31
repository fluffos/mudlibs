//Cracked by Kafei
//job_message.h
//处理各种信息的函数
//根据任务的势力区域，产生一个杀人的任务。
//#include "job_family_master.h"

void get_job_palce_msg(object master,object player,string place,string state,string command_mode)
{
	string rmsg,pmsg,job_menpai,master_msg;

	job_menpai=job_map["job_menpai"];
	

	master_msg=get_family_master_massage(command_mode,job_menpai,state);
	rmsg=replace_string(master_msg,"$N",master->query("name"));
	rmsg=replace_string(rmsg,"$n",player->query("name"));
	rmsg=replace_string(rmsg,"$P",player->query("name"));
	rmsg=replace_string(rmsg,"$ROOM",place);


	pmsg=replace_string(master_msg,"$N",master->query("name"));
	pmsg=replace_string(pmsg,"$n","你");
	pmsg=replace_string(pmsg,"$P",player->query("name"));
	pmsg=replace_string(pmsg,"$ROOM",place);

	
	tell_room(environment(master),rmsg,({master,player}));
	tell_object(player,pmsg);
}

//任务的下达者对任务执行者告诉的信息
//The message that job master command to job executant
//如果位置不在master位置，出现的提示信息。
//show the message taht job executant not in master room
string get_family_master_massage(string command_mode,string menpai,string state)
{
	string talk_msg;
	talk_msg="";
	switch(menpai)
				{

				case "武当派" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,wudang_message);
					break;
				case "星宿派" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,xingxiu_message);
					break;
				case "华山派" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,huashan_message);
					break;
				case "桃花岛" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,taohua_message);
					break;
				case "丐帮" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,gaibang_message);
					break;
				case "峨嵋派" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,emei_message);
					break;
				case "白驼山" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,baituo_message);
					break;
				case "全真教" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,quanzhen_message);
					break;
				case "雪山派" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,xueshan_message);
					break;
				case "大理段家" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,dali_message);
					break;
				case "少林派" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,shaolin_message);
					break;
				default :
					talk_msg+="$N对$n点了点头,说道：“$P，你来的正好。”\n";
				}
	return talk_msg;
}
	

int job_class_prompt(object player)
{
	string state;
	mapping job_map;
	state="";

	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	switch(job_map["job_command_mode"])
		{
		case "传话"   :  
			state+=job_map["job_master_cname"]+"已传令要召见你，你还是快点去吧。\n";
			
			break;
			default  : 
				state="任务类型错误。\n";
				//break;
				return 0;
		}
	tell_object(player,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	tell_object(player,job_map["job_master_place"]);
	return 1;
}
int job_start_prompt(object player)
{
	string state;
	state="";
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	switch(job_map["job_oppose_pker_mode"])
		{
		
		case "npc":  
			
			state+=job_map["job_master_cname"]+"已派你去"+job_map["job_oppose_pker_place_chinses"]+"附近完成重要任务，赶快去执行吧。\n";
			
			break;
			default  : 
				state="job_oppose_pker_mode error。\n";
				//break;
				return 0;
		}
/*		switch(job_map["job_protect_mode"])
		{
		case "npc":  
			state+=job_map["job_master_cname"]+"已派你去"+job_map["job_oppose_pker_place_chinses"]+"附近去等人，赶快去那里吧。\n";
			
			break;
			default  : 
				state="job_oppose_pker_mode error。\n";
				//break;
				return 0;
		}
*/	
	tell_object(player,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	tell_object(player,job_map["job_oppose_pker_place"]);
	return 1;
}

//message of master tell player.I put all message in a database .now load only base on database.
int master_msg(object master,object player,string state,string command_mode)
{
	string rmsg,pmsg,job_menpai,master_msg;

	job_menpai=job_map["job_menpai"];
	master_msg=get_family_master_massage(command_mode,job_menpai,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	{
	tell_object(player,"command_mode="+command_mode+"job_menpai="+job_menpai+"state="+state+"\n");
	tell_object(player,"master_msg="+master_msg+"\n");
	}
	rmsg=replace_string(master_msg,"$N",master->query("name"));
	rmsg=replace_string(rmsg,"$n",player->query("name"));
	rmsg=replace_string(rmsg,"$P",player->query("name"));

	pmsg=replace_string(master_msg,"$N",master->query("name"));
	pmsg=replace_string(pmsg,"$n","你");
	pmsg=replace_string(pmsg,"$P",player->query("name"));
	
	tell_room(environment(master),rmsg,({master,player}));
	tell_object(player,pmsg);
	return 1;
}

int assess_msg(object master,object player,string state,string command_mode,string family,object place)
{
	string rmsg,pmsg,job_menpai,master_msg;

	job_menpai=family;
	master_msg=get_family_master_massage(command_mode,job_menpai,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	{
	tell_object(player,"command_mode="+command_mode+"job_menpai="+job_menpai+"state="+state+"\n");
	tell_object(player,"master_msg="+master_msg+"\n");
	}
	rmsg=replace_string(master_msg,"$N",master->query("name"));
	rmsg=replace_string(rmsg,"$n",player->query("name"));
	rmsg=replace_string(rmsg,"$P",player->query("name"));

	pmsg=replace_string(master_msg,"$N",master->query("name"));
	pmsg=replace_string(pmsg,"$n","你");
	pmsg=replace_string(pmsg,"$P",player->query("name"));
	tell_room(place,rmsg,({player}));
	tell_object(player,pmsg);
	return 1;
}


