#include "include/create_npc.h"

int create_npc(object who, object fb_mem)
{
	int i, skill_level;
	mapping npc_family_skill, exit;
	object *room_obj, *npc_obj = ({});
	object room, npc, temp;
	
	room_obj = fb_mem->query("room_obj");
	while (!objectp(room))
	{
		temp = room_obj[random(sizeof(room_obj))];
		exit = temp->query("exits");
		if (!temp->query("short") || !mapp(exit) || !sizeof(exit) || !temp->query("outdoors"))
			continue;	
		else
			room = temp;
	}
	npc_family_skill = skill_map[random(sizeof(skill_map))];
	skill_level = get_average_skill(fb_mem);
	
	for (i = 0; i < NPC_AMOUNT; i++)
	{
		npc = new(__DIR__"npc/npc");
		npc_obj +=({npc});
		distribute_skill(npc, skill_level, npc_family_skill);
		npc->set("max_qi", get_average_attri(fb_mem, "max_qi") * 2);
		npc->set("qi", get_average_attri(fb_mem, "max_qi") * 2);
		npc->set("eff_qi", get_average_attri(fb_mem, "eff_qi") * 2);
		npc->set("max_neili", get_average_attri(fb_mem, "max_qi") * 3);
		npc->set("neili", get_average_attri(fb_mem, "max_qi") * 3);
		npc->set("max_jing", get_average_attri(fb_mem, "max_jing"));
		npc->set("jing", get_average_attri(fb_mem, "max_jing"));
		npc->jiali(150);
		npc->move(room);
	}

	fb_mem->set("npc_obj", npc_obj);
		
	return 1;
}

int get_average_skill(object fb_mem)
{
	string temp1;
	string *team;
	mapping skill_map;
	string skills, temp2;
	int count_level, max_level = 0;
	
	team = fb_mem->query("team");
	
	foreach(temp1 in team)
	{
		if(!(skill_map = temp1->query_skills()))
			continue;
		
		skills = (string)keys(skill_map);
		foreach(temp2 in skills)
		{
			if(max_level < skill_map[temp2]) max_level = skill_map[temp2];
		}
		
		count_level += max_level;
	}
	
	return (count_level / sizeof(team));
}

int get_average_attri(object fb_mem, string arg)
{
	int count = 0;
	string *team, temp;
	
	team = fb_mem->query("team");
	foreach(temp in team)
	{
		count += temp->query(arg);
	}
	
	return (count / sizeof(team));
}
int distribute_skill(object ob,int skill_level, mapping npc_family_skill)
{
	string *skills;
	string temp;
	
	skills = keys(npc_family_skill);
	
	foreach(temp in skills)
	{
		if (!npc_family_skill[temp])
		{
			ob->set_skill(temp, skill_level);	
		}
		else
		{
			ob->set_skill(temp, skill_level);
			ob->set_skill(npc_family_skill[temp], skill_level);
			ob->map_skill(npc_family_skill[temp], temp);
		}
	}
	return 1;
}