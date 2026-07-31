//Cracked by Kafei
//wzfeng@xkx 2000 6
//job_data
//记录所有任务系统数据

#include <ansi.h>

inherit F_SAVE;
inherit ITEM;

#include "default_data.h"
#include "lpc_math.h"
#define JOB_DIR "/clone/obj/job/"

mapping job_data;    //当前任务系统数据。
mapping *job_datas;    //全部任务系统的数据。
mapping *family_job_data;
mapping *family_assess;
//mapping *best_player_data;
//mapping *bad_player_data;
mapping *assess_player_data;
mapping family_assess_number;
int START_JOB_SYSTEM;
mapping *query_familys_job_data()
{
	restore();
	return family_job_data;

}
int query_job_start()
{
	restore();
	return START_JOB_SYSTEM;
}
void set_job_start()
{
	restore();
	START_JOB_SYSTEM=1;
	save();
}
void set_close_start()
{
	restore();
	START_JOB_SYSTEM=0;
	save();
}
void reset_family_data(string family)
{
	
	mapping new_map;
	restore();
	new_map=([]);
	new_map["family_name"]=family;
	family_job_data=change_map(new_map,family_job_data,"family_name",family);
	save();

}

mapping *query_assess_player_data()
{
	restore();
	return assess_player_data;
}
void remove_assess_player(string player,string family)
{
	int i;
//	printf("id=%s\tfamily_name=%s\n",player,family);

	if(!pointerp(assess_player_data))
		return;
	for(i=i;i<sizeof(assess_player_data);i++)
		if(!undefinedp(assess_player_data[i][player]))
		{

			map_delete(assess_player_data[i],player);
		}


	save();
}

void set_family_best_job_player(string *player_list,string family)
{
	mapping best,family_map;
	int i;
	best=([]);
	restore();

	family_map=get_mapping(family,"family",assess_player_data);
	if(!sizeof(family_map))
	{
		family_map=([]);
		family_map["family"]=family;
	}
	for(i=0;i<sizeof(player_list);i++)
	{
			if(judge_map_element(player_list[i],family_map))
				continue;
		family_map[player_list[i]]="good";
	}
	assess_player_data=change_map(family_map,assess_player_data,"family",family);
	save();

}
void set_family_bad_job_player(string *player_list,string family)
{
	mapping bad,family_map;
	int i;
	string *name;
	bad=([]);
	restore();

	family_map=get_mapping(family,"family",assess_player_data);

	if(!sizeof(family_map))
	{
		family_map=([]);
		family_map["family"]=family;
	}


	for(i=0;i<sizeof(player_list);i++)
	{
			if(judge_map_element(player_list[i],family_map))
				continue;
		family_map[player_list[i]]="bad";
	}
	assess_player_data=change_map(family_map,assess_player_data,"family",family);
	save();

}


int judge_family_assess_data(mapping map,string family)
{
	if(map["family"]==family)
		return 0;
	return 1;
}
void remove_family_assess(string family)
{

	if(!is_attr_mapping(family,"family",family_assess))
		return ;
	
	family_assess=filter_array(family_assess,(:judge_family_assess_data:),family);
	save();
	return;
}
mapping *query_family_assess_data()
{
	restore();

	return family_assess;
}
void set_start_assess(string family,int step)
{
	mapping temp_map;
	temp_map=get_mapping(family,"family",family_assess);
	temp_map["assess_start"]=step;
	family_assess=modify_map(family,"family",temp_map,family_assess);
	save();
	return;
}
void set_family_assess(mapping *family_assess_temp)
{
	family_assess=family_assess_temp;
	save();
}
mapping query_assess_playermap()
{
	int i,j;
	mapping player_map,family_map;
	string *keys;
	player_map=([]);
	restore();
	if(!pointerp(assess_player_data))
		return player_map;
	//family_map=get_mapping("武当派","family",assess_player_data);
	//write(p_map(family_map));
	for(i=0;i<(sizeof(assess_player_data));i++)
	{
		keys=keys(assess_player_data[i]);
		
		for(j=0;j<sizeof(assess_player_data[i]);j++)
		{
			
			if(!(assess_player_data[i][keys[j]]=="good"
				||assess_player_data[i][keys[j]]=="bad"))
			{
				continue;
			}
//			printf("添加keys=%s\t内容为%s\n",keys[j],assess_player_data[i][keys[j]]);
			player_map[keys[j]]=assess_player_data[i][keys[j]];
		}
	}
	return player_map;


}
void create()
{
//	 set_name("任务产生器",  ({"job_produce"}));
	seteuid(getuid());
}

string query_save_file()
{
        return DATA_DIR + "job_system/job_data"; 
}
void reset()
{
	job_data=([]);
	job_datas=({});
	return ;
}
void change_family_data(string family,object player,string job_kind)
{
	mapping family_data;
	int achievement;
	restore();
	write("开始修改门派data\n");
	family_data=([
		"family_name":family,
		]);
	write(job_kind+"是惩罚形态\n");
	switch(job_kind)
	{
	case "oppose_pker":

		achievement=10;
		break;
	case "OPPOSE_DROP_CON":

		achievement=- OPPOSE_DROP_CON;
		break;
	case "MASTER_CALL_IN_CON":
		write("call iun");

		achievement= -MASTER_CALL_IN_CON;
		break;
	case "FINISH_JOB_CON":

		achievement=- FINISH_JOB_CON;
		break;

	}
	//if no this manpai mapiing.
	if(!is_attr_mapping(family,"family_name",family_job_data))
	{
		family_job_data=add_string(family_data,family_job_data);
	}

	family_data=get_mapping(family,"family_name",family_job_data);
	
	
	//if have this player data.
	if(judge_map_element(player->query("id"),family_data))
	{
		family_data[player->query("id")]+=achievement;
	}
	else
	{
		family_data[player->query("id")]=achievement;
	}
	//Add job_contribute only achievement is plus.
	if(achievement>0)
	{
	if(judge_map_element("job_contribute",family_data))
		family_data["job_contribute"]+=achievement;
	else
		family_data["job_contribute"]=achievement;
	}
	family_job_data=modify_map(family,"family_name",family_data,family_job_data);
	save();
	write("修改成功\n");
}

//choose player good or bad
string *choose_of_player(string family,string kind)
{
	mapping family_data;
	string *name_keys,kind_player,*member;
	int i,temp;
	restore();
	kind_player=0;
	if(!is_attr_mapping(family,"family_name",family_job_data))
		return 0;
	family_data=get_mapping(family,"family_name",family_job_data);
	if(!sizeof(family_data))
		return 0;
	//filter map
	map_delete(family_data,"family_name"); 
	map_delete(family_data,"job_contribute"); 
	switch(kind)
	{
	case "good":
		member=get_maxnum_inmap(family_data);
		break;
	case "bad":
		member=get_minnum_inmap(family_data);
		break;

	}
	
	return member;
}
string query_family_jobdata(string family)
{
	mapping family_data;
	string data;
	if(!is_attr_mapping(family,"family_name",family_job_data))
		return "没有这个门派的数据。\n";
	family_data=get_mapping(family,"family_name",family_job_data);
	data=p_map(family_data);
	return data;
}
mapping query_family_job_data(string family)
{
	mapping family_data;
	string data;
	restore();
	if(!is_attr_mapping(family,"family_name",family_job_data))
		return 0;
	family_data=get_mapping(family,"family_name",family_job_data);
	
	return family_data;

}

//获取达到评定条件的门派
string is_familyassess_full()
{
	mapping family_data,assess_list,*familys_data;
	object menpai_ob;
	int i,assess_num;
	
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	
	if(!objectp(menpai_ob)) return 0;

	menpai_ob->restore();

//	assess_list=get_array_map("family_assess_num",menpai_ob->query_familys);
//	write(p_map(assess_list)
	familys_data=menpai_ob->query_familys();
	if(menpai_ob)
	destruct(menpai_ob);

	
	
	if( !pointerp(family_job_data))
		return 0;
	
	for(i=0;i<sizeof(family_job_data);i++)
	{
		assess_num=get_msg_map("family_name",family_job_data[i]["family_name"],"family_assess_num",familys_data);
/*		printf("%s的assess_unm==%d\t现在%s的assess_num==%d\n",
			family_job_data[i]["family_name"],assess_num,
			family_job_data[i]["family_name"],family_job_data[i]["job_contribute"]);
*/
		if(family_job_data[i]["job_contribute"]>assess_num)
			return family_job_data[i]["family_name"];
	}
	
	return 0;
}

string *query_player_list()
{
	int i,j;
	string *job_player_list;
	
	
	restore();
	if(!pointerp(job_datas))
		return job_player_list;
	for(i=0;i<sizeof(job_datas);i++)
	{
		job_player_list=get_array_map("job_player",job_datas);
	}

	return job_player_list;
}

string *query_list(string kind)
{
	int i;
	string *job_player_list,*job_kind_list,job_kind;

	restore();
	job_player_list=query_player_list();

	if(!pointerp(job_datas))
		return job_kind_list;
	switch(kind)
	{
	case "finish_job":
		job_kind="job_finish";
		break;
	case "ask_job":
		job_kind="job_askjob";
		break;
	case "oppose_pker":
		job_kind="job_oppose_pker_place";
		break;
	case "protect":
		job_kind="job_protect_place";
		break;

	}
			for(i=0;i<sizeof(job_player_list);i++)
			{
			if(undefinedp(get_mapping(job_player_list[i],"job_player",job_datas)[job_kind]))
				continue;
			else
				job_kind_list=add_string(job_player_list[i],job_kind_list);
			}
	return job_kind_list;
}

mapping *query_job_data()
{
	
	return job_datas;
}

int add_job_data(mapping job_data)
{
	
	if( !pointerp(job_datas) )
        {
         job_datas = ({ job_data });
        }
        else job_datas += ({ job_data });
		return 1;
}
int judge_mapping(mapping job,string player_name)
{
	if(job["job_player"]==player_name)
		return 0;
	return 1;
}

int detract_job_data(string player_name)
{
	job_datas=filter_array(job_datas,(:judge_mapping:),player_name);

	return 1;

}
int modify_job_data(string player_name,mapping map)
{
	int i;
	restore();

	if( !pointerp(job_datas) )
        {
         job_datas = ({});
		 return 0;
        }
	for(i=0;i<sizeof(job_datas);i++)
	{
		if(job_datas[i]["job_player"]==player_name)
		{
		job_datas[i] = map; 
		return 1;
		}
	}
	return 0;
}

