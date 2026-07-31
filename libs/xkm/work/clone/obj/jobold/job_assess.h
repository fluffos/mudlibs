//Cracked by Kafei
//job assess.h
//wzfeng@xkx 2000 7
//获得活着的master
object master_living(string master_name,string id)
{
	object master,*ob_list;
	int i;
	ob_list=children(master_name);
	i=sizeof(ob_list);
	while (i--)
	if (!environment(ob_list[i]))  {
      reset_eval_cost();
      
      destruct(ob_list[i]);
    }
	ob_list=children(master_name);

	for(i=0;i<sizeof(ob_list);i++)
	{
		if(environment(ob_list[i])&&
			ob_list[i]->query("id")==id)
		{

			return ob_list[i];
		}
	}



}

int filter_family(object ob,string family,string place)
{
	if(!userp(ob)
		||!interactive(ob)
		 ||!living(ob)
		 //||query_idle(ob)
		 ||ob->query("family/family_name")!=family
		 ||file_name(environment(ob))==place
		 )
		 return 0;
	return 1;
	 
}
void prompt_assess_player(string family,int time_old,string place)
{
	object* ob;
	string msg;
	int i;
	ob=filter_array(users(), "filter_family", this_object(),family,place);
	if(!sizeof(ob))
		return;
	msg=get_family_master_massage("assess",family,"prompt");
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("assess_prompt")>12)
		{
			tell_object(ob[i],msg);
			ob[i]->delete_temp("assess_prompt");
		}
		else
			ob[i]->add_temp("assess_prompt",1);

	}
}
string get_award_player(string family)
{
	string *name;
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	name=job_data->choose_of_player(family,"good");
	if(sizeof(name)!=1)
		return 0;
	return name[0];
}
string *get_punish_player(string family)
{
	string *name;
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	name=job_data->choose_of_player(family,"bad");
	if(!sizeof(name))
		return 0;
	return name;
}
//
mapping make_pubish(object player,object master,string family)
{
	int exp,skills_lvl,max_neili,max_jingli,max_qi,max_jing,luck;
	object menpai_ob;
	mapping p_data;
	p_data=([]);
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	if(!objectp(menpai_ob)) return 0;
	menpai_ob->restore();
	//write(family);

	//printf("luck=%d",menpai_ob->query_luck(family));
	if(!luck=menpai_ob->query_luck(family))
		luck=random(5);
	//printf("幸运点数为%d\n",luck);

	exp=player->query("combat_exp")/150;
	if(exp>100000)
		exp=100000;
	exp=exp+exp*luck/10;
	skills_lvl=3+luck/2;
	if(skills_lvl>5)
		skills_lvl=5;
	max_neili=luck*2/3;
	max_jingli=luck*2/3;
	if(max_neili>5) max_neili=5;
	if(max_jingli>5) max_jingli=5;
	p_data["exp"]=exp;
	p_data["skills_lvl"]=skills_lvl;
	p_data["max_neili"]=max_neili;
	p_data["max_jingli"]=max_jingli;
	p_data["skills_name"]=family_skills_award[family];

	return p_data;


}

mapping make_assess_award(object player,object master,string family)
{
	int exp,skills_lvl,max_neili,max_jingli,max_qi,max_jing,luck;
	object menpai_ob;
	mapping p_data;
	p_data=([]);
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	if(!objectp(menpai_ob)) return 0;
	menpai_ob->restore();
	//write(family);

	//printf("luck=%d",menpai_ob->query_luck(family));
	if(!luck=menpai_ob->query_luck(family))
		luck=random(5);
	

	exp=player->query("combat_exp")/100;

	if(exp<10000)
		exp=10000;
	if(exp>100000)
		exp=100000;
	exp=exp+exp*luck/10;
	skills_lvl=3+luck/2;
	if(skills_lvl>10)
		skills_lvl=10;
	max_neili=luck*2/3;
	max_jingli=luck*2/3;
	if(max_neili>10) max_neili=10;
	if(max_jingli>10) max_jingli=10;
	p_data["exp"]=exp;
	p_data["skills_lvl"]=skills_lvl;
	p_data["max_neili"]=max_neili;
	p_data["max_jingli"]=max_jingli;
	p_data["skills_name"]=family_skills_award[family];

	return p_data;



}

//award family assess good.
void family_assess_award(object player,object master,string family)
{
	object place;
	mapping award_assess_best;
	int i,skills_add,skills_lvl,exp;
	string *skills_name,msg;
	award_assess_best=([]);
	msg=HIC"\n";
	place=environment(player);
	assess_msg(master,player,"assess_award_best","assess",family,place);
	job_data->remove_assess_player(player->query("id"),family);
	////////////////////////////////////////////////////////////
	award_assess_best=make_assess_award(player,master,family);
	skills_name=award_assess_best["skills_name"];
	player->add("combat_exp",award_assess_best["exp"]);
	msg+="你的经验提高了"+award_assess_best["exp"]+"点\n";
	player->add("max_neili",award_assess_best["max_neili"]);
	msg+="你的最大内力提高了"+award_assess_best["max_neili"]+"点\n";
	player->add("eff_jingli",award_assess_best["max_jingli"]);
	player->add("max_jingli",award_assess_best["max_jingli"]);
	msg+="你的最大精力提高了"+award_assess_best["max_jingli"]+"点\n";
	//add skills
	for(i=0;i<sizeof(skills_name);i++)
	{
		skills_lvl=(int)player->query_skill(skills_name[i],1);
		skills_lvl+=award_assess_best["skills_lvl"];
		exp=player->query("combat_exp");
		if(skills_lvl*skills_lvl*skills_lvl/10>exp)
			continue;
		player->set_skill(skills_name[i],skills_lvl);
		msg+="你的"+to_chinese(skills_name[i])+"提高了"+award_assess_best["skills_lvl"]+"级\n";
	}
	
	msg+="望你再接再厉，加油！\n"NOR;
	tell_object(player,msg);
	


	return;
}
void family_assess_common(object player,object master,string family)
{
	int exp;
	string msg;
	msg=HIC"";
	exp=1000+random(1000);
	player->add("combat_exp",exp);
	msg+="你的经验提高了"+exp+"点\n"NOR;
	tell_object(player,msg);
	return;
}
void family_assess_punish(object player,object master,string family)
{
	object place;
	mapping punish_assess;
	int i,skills_add,skills_lvl,exp;
	string *skills_name,msg;
	punish_assess=([]);
	msg=HIB"\n";
	place=environment(player);
	assess_msg(master,player,"assess_punish","assess",family,place);
	job_data->remove_assess_player(player->query("id"),family);
	////////////////////////////////////////////////////////////
	exp=player->query("combat_exp");
	punish_assess=make_pubish(player,master,family);
	skills_name=punish_assess["skills_name"];
	if(exp<punish_assess["exp"])
		punish_assess["exp"]=exp;
	player->add("combat_exp",-punish_assess["exp"]);
	msg+="你的经验降低了"+punish_assess["exp"]+"点\n";
	if(player->query("max_neili")<punish_assess["max_neili"])
		punish_assess["max_neili"]=player->query("max_neili");
	
	player->add("max_neili",-punish_assess["max_neili"]);
	
	msg+="你的最大内力降低了"+punish_assess["max_neili"]+"点\n";
	
	if(player->query("max_jingli")<punish_assess["max_jingli"])
		punish_assess["max_jingli"]=player->query("max_jingli");


	player->add("eff_jingli",-punish_assess["max_jingli"]);
	player->add("max_jingli",-punish_assess["max_jingli"]);
	msg+="你的最大精力降低了"+punish_assess["max_jingli"]+"点\n";

	for(i=0;i<sizeof(skills_name);i++)
	{
		skills_lvl=(int)player->query_skill(skills_name[i],1);
		if(!skills_lvl) continue;
		if(skills_lvl<punish_assess["skills_lvl"])
			punish_assess["skills_lvl"]=skills_lvl;
		skills_lvl-=punish_assess["skills_lvl"];
		player->set_skill(skills_name[i],skills_lvl);
		msg+="你的"+to_chinese(skills_name[i])+"降低了"+punish_assess["skills_lvl"]+"级\n";
	}
	
	msg+="下次再要如此，必当重罚！\n"NOR;
	tell_object(player,msg);
	
	return;
}

mapping make_assess_playermap(object player,string mode)
{
	mapping player_map;
	player_map=([]);
	
	player_map["player_name"]=player->query("id");
	player_map["family_name"]=player->query("family/family_name");
	player_map["master_name"]=explode(family_master[player->query("family/family_name")], "/")[2];
	player_map["master_place"]=family_master_place[player->query("family/family_name")];
	player_map["mode"]=mode;


	return player_map;
}
void set_family_assess_data(object master,string family)
{
	mapping assess ,*family_assess;
	assess=([]);
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_assess=job_data->query_family_assess_data();
	if(is_attr_mapping(family,"family",family_assess))
		return;		
	//write(HIC"设置assess_data\n"NOR);
	assess["family"]=family;
	assess["master"]=base_name(master);
	assess["master_id"]=master->query("id");
	assess["place"]=assess_place[family];
	assess["time"]=time();
	assess["assess_start"]=0;
	family_assess=add_string(assess,family_assess);
	job_data->set_family_assess(family_assess);
//	destruct(master);
	
	return;
}
//send assess message to player.
void send_assess_msg(object master,string family)
{
	string master_say;
	mapping assess=([]);

	
	master_say=get_family_master_massage("assess",family,"send_to");
	if(!master_say)
		return;
	CHANNEL_D->do_channel(master, "chat",master_say);
	CHANNEL_D->do_channel(master, "menpai",master_say);
	
	master_say=get_family_master_massage("assess",family,"send_to1");
	if(!master_say)
	{
		write("send_to1 error\n");
		return;
	}
	CHANNEL_D->do_channel(master, "chat",master_say);
	CHANNEL_D->do_channel(master, "menpai",master_say);
	write("send_to1 ok\n");
		//save assess data.
	set_family_assess_data(master,family);
	return;
}
int filter_player(object ob,string family)
{
	if(
		 !userp(ob)
		 ||!interactive(ob)
		 ||!living(ob)
		 //||ob->query("family/family_name")!=family
		 )
	 {
		 //printf("门派选择了%s\tplayer\t%s的门派是%s\n",menpai_name,ob->query("name"),ob->query("family/family_name"));
		 return 0;
	 }
	return 1;

}


void do_assess_1(mapping family)
{
	//check place and master
	object master,place;
	mapping exits;
	//mapping *family_assess;
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	

	if(!place=find_object(family["place"]))
		place=load_object(family["place"]);
	if(!objectp(place))
		return;

	if(!objectp(master=present(family["master_id"], place)))
	{
		//printf("%s\n",family["master"]);
		master=master_living(family["master"],family["master_id"]);
		//write(master->query("name"));
		if(!objectp(master))
		{
			//write("master没有找到\n");
			master=new(family["master"]);
			//write("new master\n");
		}
		if(!objectp(master)) 
		{
			write("new master error\n");
			return;
		}
		tell_room(environment(master),master->query("name")+"急急忙忙离开了。\n");
		master->move(place);
		tell_room(place,master->query("name")+"走了过来。\n");
	}
	//write("maseter must be here\n");

	place->set("no_fight",1);
	place->set("no_sleep",1);
	place->set("no_steal",1);
	place->set("long1",place->query("long"));
	place->set("long",place->query("long")+HIY"\t\t现在正在进行"
				+family["family"]+"重要会议\n"NOR);
	if(!place->query("exit_temp"))
	{
	place->set("exit_temp",place->query("exits"));
	place->delete("exits");
	}
	job_data->set_start_assess(family["family"],2);
	return;
}
//

void do_assess_2(mapping family)
{
	object *player_list,player,kickout_place,place,master;
	mapping out;
	string msg_1,exit;
	int i,kick_o;

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	if(!place=find_object(family["place"]))
		place=load_object(family["place"]);
	if(!objectp(place))
		return;
	if(!objectp(master=present(family["master_id"], place)))
	{
		//printf("%s\n",family["master"]);
		master=master_living(family["master"],family["master_id"]);
		//write(master->query("name"));
		if(!objectp(master))
		{
			//write("master没有找到\n");
			master=new(family["master"]);
			//write("new master\n");
		}
		if(!objectp(master)) 
		{
			//write("new master error\n");
			return;
		}
		tell_room(environment(master),master->query("name")+"急急忙忙离开了。\n");
		master->move(place);
		tell_room(place,master->query("name")+"走了过来。\n");
	}
	assess_msg(master,master,"assess_start","assess",family["family"],place);
	assess_msg(master,master,"family","assess",family["family"],place);

	player_list=all_inventory(place);
	player_list=filter_array(player_list,"filter_player",this_object(),family["family"]);
	//kick out player who are not in this family.
	for(i=0;i<sizeof(player_list);i++)
	{
		if(player_list[i]->query("family/family_name")!=family["family"])
		{
			msg_1=get_family_master_massage("assess",family["family"],"kick_out");
			if(!kick_o)
			{
			assess_msg(master,player_list[i],"kick_out","assess",family["family"],place);
			kick_o=1;
			}
			out=place->query("exit_temp");
			if(!sizeof(out))
			{
				if(!kickout_place=find_object("/d/city/kedian"))
					kickout_place=new("/d/city/kedian");
				if(!objectp(kickout_place))
					player_list[i]->move(VOID_OB);
				else
					player_list[i]->move(kickout_place);
				//tell_room(place,player_list[i]->query("name")+"离开了这里。\n");
				assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
				continue;
			}
			else
			{
				exit=out[keys(out)[random(sizeof(out))]];
				if(!kickout_place=find_object(exit))
						kickout_place=new(exit);
					if(!objectp(kickout_place))
						player_list[i]->move(VOID_OB);
					else
						player_list[i]->move(kickout_place);
					assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
					continue;
			}
		}
	}
	

	job_data->set_start_assess(family["family"],3);
	return;
}
//award player
void do_assess_3(mapping family)
{
	object *player_list,player,kickout_place,place,master;
	mapping out,*family_assess;
	string msg_1,exit,*player_name;
	
	int i,kick_o;

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_assess=job_data->query_family_assess_data();
	if(!place=find_object(family["place"]))
		place=load_object(family["place"]);
	if(!objectp(place))
		return;
	if(!objectp(master=present(family["master_id"], place)))
	{
		//printf("%s\n",family["master"]);
		master=master_living(family["master"],family["master_id"]);
		//write(master->query("name"));
		if(!objectp(master))
		{
			//write("master没有找到\n");
			master=new(family["master"]);
			//write("new master\n");
		}
		if(!objectp(master)) 
		{
			//write("new master error\n");
			return;
		}
		tell_room(environment(master),master->query("name")+"急急忙忙离开了。\n");
		master->move(place);
		tell_room(place,master->query("name")+"走了过来。\n");
	}
	player_list=all_inventory(place);
	player_list=filter_array(player_list,"filter_player",this_object(),family["family"]);
	//kick out player who are not in this family.
	for(i=0;i<sizeof(player_list);i++)
	{
		if(player_list[i]->query("family/family_name")!=family["family"])
		{
			msg_1=get_family_master_massage("assess",family["family"],"kick_out");
			if(!kick_o)
			{
			assess_msg(master,player_list[i],"kick_out","assess",family["family"],place);
			kick_o=1;
			}
			out=place->query("exit_temp");
			if(!sizeof(out))
			{
				if(!kickout_place=find_object("/d/city/kedian"))
					kickout_place=new("/d/city/kedian");
				if(!objectp(kickout_place))
					player_list[i]->move(VOID_OB);
				else
					player_list[i]->move(kickout_place);
				//tell_room(place,player_list[i]->query("name")+"离开了这里。\n");
				assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
				continue;
			}
			else
			{
				exit=out[keys(out)[random(sizeof(out))]];
				if(!kickout_place=find_object(exit))
						kickout_place=new(exit);
					if(!objectp(kickout_place))
						player_list[i]->move(VOID_OB);
					else
						player_list[i]->move(kickout_place);
					assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
					continue;
			}
		}
	}
	//award best player.

	player_name=job_data->choose_of_player(family["family"],"good");
	job_data->set_family_best_job_player(player_name,family["family"]);
	//printf("%d\n",sizeof(player_name));

	player_list=all_inventory(place);
	player_list=filter_array(player_list,"filter_player",this_object(),family["family"]);
	player_list=filter_array(player_list, "do_check_job_player", this_object(),player_name);
	if(!sizeof(player_list))
	{
		job_data->set_start_assess(family["family"],4);
		return;
	}
	for(i=0;i<sizeof(player_list);i++)
	{
		//assess_msg(master,player_list[i],"assess_award_best","assess",family["family"],place);
		family_assess_award(player_list[i],master,family["family"]);
		player_list[i]->set_temp("assess/no_award",1);
		//printf("name=%s\tfamily=%s\n",player_list[i]->query("id"),family["family"]);
		job_data->remove_assess_player(player_list[i]->query("id"),family["family"]);
	}

	job_data->set_start_assess(family["family"],4);
	return;
}
//punish player
void do_assess_4(mapping family)
{
	object *player_list,player,kickout_place,place,master;
	mapping out,*family_assess;
	string msg_1,exit,*player_name;
	
	int i,kick_o;

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_assess=job_data->query_family_assess_data();
	if(!place=find_object(family["place"]))
		place=load_object(family["place"]);
	if(!objectp(place))
		return;
	if(!objectp(master=present(family["master_id"], place)))
	{
		//printf("%s\n",family["master"]);
		master=master_living(family["master"],family["master_id"]);
		//write(master->query("name"));
		if(!objectp(master))
		{
			//write("master没有找到\n");
			master=new(family["master"]);
			//write("new master\n");
		}
		if(!objectp(master)) 
		{
			//write("new master error\n");
			return;
		}
		tell_room(environment(master),master->query("name")+"急急忙忙离开了。\n");
		master->move(place);
		tell_room(place,master->query("name")+"走了过来。\n");
	}

	player_list=all_inventory(place);
	player_list=filter_array(player_list,"filter_player",this_object(),family["family"]);
	//kick out player who are not in this family.
	for(i=0;i<sizeof(player_list);i++)
	{
		if(player_list[i]->query("family/family_name")!=family["family"])
		{
			msg_1=get_family_master_massage("assess",family["family"],"kick_out");
			if(!kick_o)
			{
			assess_msg(master,player_list[i],"kick_out","assess",family["family"],place);
			kick_o=1;
			}
			out=place->query("exit_temp");
			if(!sizeof(out))
			{
				if(!kickout_place=find_object("/d/city/kedian"))
					kickout_place=new("/d/city/kedian");
				if(!objectp(kickout_place))
					player_list[i]->move(VOID_OB);
				else
					player_list[i]->move(kickout_place);
				//tell_room(place,player_list[i]->query("name")+"离开了这里。\n");
				assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
				continue;
			}
			else
			{
				exit=out[keys(out)[random(sizeof(out))]];
				if(!kickout_place=find_object(exit))
						kickout_place=new(exit);
					if(!objectp(kickout_place))
						player_list[i]->move(VOID_OB);
					else
						player_list[i]->move(kickout_place);
					assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
					continue;
			}
		}
	}
	//award punish player.

	player_name=job_data->choose_of_player(family["family"],"bad");
	//for(i=0;i<sizeof(player_name);i++)
		//printf("bad player=%s\n",player_name[i]);
	job_data->set_family_bad_job_player(player_name,family["family"]);
	//printf("%d\n",sizeof(player_name));

	player_list=all_inventory(place);
	player_list=filter_array(player_list,"filter_player",this_object(),family["family"]);
	player_list=filter_array(player_list, "do_check_job_player", this_object(),player_name);
	if(!sizeof(player_list))
	{
		job_data->set_start_assess(family["family"],5);
		return;
	}
	
	for(i=0;i<sizeof(player_list);i++)
	{
		//assess_msg(master,player_list[i],"assess_punish","assess",family["family"],place);
		family_assess_punish(player_list[i],master,family["family"]);
		player_list[i]->set_temp("assess/no_award",1);
		job_data->remove_assess_player(player_list[i]->query("id"),family["family"]);
	}
	job_data->set_start_assess(family["family"],5);

	return;
}
//award common .
void do_assess_5(mapping family)
{
	object *player_list,player,kickout_place,place,master,frist_place;
	mapping out,*family_assess;
	string msg_1,exit;
	
	int i,kick_o;

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_assess=job_data->query_family_assess_data();
	if(!place=find_object(family["place"]))
		place=load_object(family["place"]);
	if(!objectp(place))
		return;
	if(!objectp(master=present(family["master_id"], place)))
	{
		//printf("%s\n",family["master"]);
		master=master_living(family["master"],family["master_id"]);
		//write(master->query("name"));
		if(!objectp(master))
		{
			//write("master没有找到\n");
			master=new(family["master"]);
			//write("new master\n");
		}
		if(!objectp(master)) 
		{
			//write("new master error\n");
			return;
		}
		tell_room(environment(master),master->query("name")+"急急忙忙离开了。\n");
		master->move(place);
		tell_room(place,master->query("name")+"走了过来。\n");
	}
	player_list=all_inventory(place);
	player_list=filter_array(player_list,"filter_player",this_object(),family["family"]);
	//kick out player who are not in this family.
	for(i=0;i<sizeof(player_list);i++)
	{
		if(player_list[i]->query("family/family_name")!=family["family"])
		{
			msg_1=get_family_master_massage("assess",family["family"],"kick_out");
			if(!kick_o)
			{
			assess_msg(master,player_list[i],"kick_out","assess",family["family"],place);
			kick_o=1;
			}
			out=place->query("exit_temp");
			if(!sizeof(out))
			{
				if(!kickout_place=find_object("/d/city/kedian"))
					kickout_place=new("/d/city/kedian");
				if(!objectp(kickout_place))
					player_list[i]->move(VOID_OB);
				else
					player_list[i]->move(kickout_place);
				//tell_room(place,player_list[i]->query("name")+"离开了这里。\n");
				assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
				continue;
			}
			else
			{
				exit=out[keys(out)[random(sizeof(out))]];
				if(!kickout_place=find_object(exit))
						kickout_place=new(exit);
					if(!objectp(kickout_place))
						player_list[i]->move(VOID_OB);
					else
						player_list[i]->move(kickout_place);
					assess_msg(master,player_list[i],"kick_out_player","assess",family["family"],place);
					continue;
			}
		}
	}
	//award best player.
	//write("do 5");
	player_list=all_inventory(place);
	//printf("%d\n",sizeof(player_list));
	assess_msg(master,master,"assess_award_common","assess",family["family"],place);
	if(sizeof(player_list))
		for(i=0;i<sizeof(player_list);i++)
			{
			if(!player_list[i]->query_temp("assess/no_award"))
			family_assess_common(player_list[i],master,family["family"]);
			player_list[i]->delete_temp("assess/no_award");

		}		
	
	assess_msg(master,master,"assess_end","assess",family["family"],place);
	job_data->remove_family_assess(family["family"]);
	job_data->reset_family_data(family["family"]);
	if(!frist_place=find_object(family_master_place[family["family"]]))
	{	//write(family_master_place[family["family"]]+"没有被编译。\n");
		frist_place=load_object(family_master_place[family["family"]]);
	}
	if(!objectp(frist_place))
	{
		//write("房间恢复错误,master删除\n");
		destruct(master);
	}
	else
	{
		
		if(present(master->query("id"), frist_place))
		{
			//write("以前的地方"+frist_place->query("short")+"已经有master,master del\n");
//			if(!destruct(master))
//				write("删除失败\n");
			if(base_name(place)!=base_name(frist_place))
			{
			tell_room(place,master->query("name")+"走了出去。\n");
			//write(
			if(!destruct(master))
				write("删除失败\n");
			}

		}
		else
		{
			tell_room(place,master->query("name")+"走了出去。\n");

		if(master->move(frist_place))
			tell_room(frist_place,master->query("name")+"走了过来。\n");
		else
			write("move error\n");
		}
	}

	if(place->query("long1"))
	place->set("long",place->query("long1"));
	if(place->query("exit_temp"))
	place->set("exits",place->query("exit_temp"));
	place->delete("long1");
	place->delete("exit_temp");
	place->delete("no_fight");
	place->delete("no_sleep");
	place->delete("no_steal");

	return;
}

