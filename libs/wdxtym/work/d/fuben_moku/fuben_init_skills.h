void init_npc(object who, object npc);
string get_max_lvskill(string *skills, mapping map_skills);
void set_npc_combat_pfm(mapping skill_map, object npc);
void check_pfm(object npc, mapping u_max_skill, mapping w_max_skill);

int max_skill_lvl = 0;

void init_npc(object who, object npc)
{
	string *s1 = ({
    	"force",//基本内功
    	"dodge",//基本轻功
    	"unarmed",//基本拳脚
    	"cuff",//基本拳法
    	"strike",//基本掌法
    	"finger",//基本指法
    	"hand",//基本手法
    	"claw",//基本爪法
    	"sword",//基本剑法
    	"blade",//基本刀法
    	"staff",//基本丈法
    	"hammer",//基本锤法
    	"club",//基本棍法
    	"whip",//基本鞭法
    	"dagger",//基本短兵
    	"throwing",//基本暗器
    	"parry",//基本招架
    	//"knowledge",//知识类技能
    	//"basic",//其他基本武功综合
	});
	
	int u_maxlv = 0, w_maxlv = 0, add_number;
	mapping map_skills, jifa_skills = ([]), u_max_skill, w_max_skill, my, xuemo;
	string *skills, *basic_skills, *other_skills, *temp_skills;
	string temp, bas_to_spe_skill;
	object weapon;
	
	my = who->query_entire_dbase();
	xuemo = npc->query_entire_dbase();
	
	add_number = (who->query("xuemo") > 0) * 10;
	xuemo["qi"] = xuemo["eff_qi"] = xuemo["max_qi"] = my["max_qi"] + add_number;
	xuemo["neili"] = xuemo["max_neili"] = my["max_neili"] + add_number;
	xuemo["jing"] = xuemo["eff_jing"] = xuemo["max_jing"] = my["max_jing"] + add_number;
	xuemo["jingli"] = xuemo["eff_jingli"] = xuemo["max_jingli"] = my["jingli"] + add_number;
	xuemo["str"] = my["str"];
	xuemo["dex"] = my["dex"];
	xuemo["int"] = my["int"];
	xuemo["con"] = my["con"];
	
	if (mapp(map_skills = who->query_skills()))
	{
		skills = keys(map_skills);
		foreach(temp in skills)
		{
			if (!who->query("xuemo"))
				npc->set_skill(temp, (map_skills[temp] * 2 / 3));
			else
				npc->set_skill(temp, map_skills[temp] + 1);
		}
		
		npc->set("xuemo", who->query("xuemo") + 1);
		
		basic_skills = s1 - (s1 - skills);
		other_skills = skills - basic_skills;
		foreach(temp in basic_skills)
		{
			if(!arrayp(temp_skills = filter_array(other_skills, (:SKILL_D($1)->valid_enable($2):), temp)))	continue;
			bas_to_spe_skill = get_max_lvskill(temp_skills, map_skills);
			jifa_skills += ([temp : bas_to_spe_skill]);
			
			if (temp == "unarmed" || temp == "cuff" || temp == "finger" || temp == "hand" || temp == "claw" || temp == "strike")
			{
				if (u_maxlv < map_skills[bas_to_spe_skill])
				{
					u_maxlv = map_skills[bas_to_spe_skill];
					u_max_skill = ([temp : bas_to_spe_skill]);
				}
			}
			if (temp == "sword" || temp == "blade" || temp == "staff" || temp == "hammer" || temp == "club" || temp == "whip" || temp == "dagger")
			{
				if (w_maxlv < map_skills[bas_to_spe_skill])
				{
					w_maxlv = map_skills[bas_to_spe_skill];
					w_max_skill = ([temp : bas_to_spe_skill]);
				}
			}
		}
		//激发武功
		foreach(temp in keys(jifa_skills))
		{
			npc->map_skill(temp, jifa_skills[temp]);
		}
		//准备空手
		if (mapp(u_max_skill))
			npc->prepare_skill(keys(u_max_skill)[0], values(u_max_skill)[0]);
		//如果武器武功比空手高或相等，装备武器
		if (((mapp(w_max_skill) && mapp(u_max_skill)) && (map_skills[values(w_max_skill)[0]] >= map_skills[values(u_max_skill)[0]])) || (mapp((w_max_skill)) && !mapp(u_max_skill)))
		{
			if ((keys(w_max_skill)[0] == "sword") && who->query("family/family_name") == "桃花岛")
			{
				weapon = new(__DIR__ + "obj/xiao");
				npc->set("family/family_name", "桃花岛");
			}
			else
				weapon = new(__DIR__ + "obj/" + keys(w_max_skill)[0]);
			
			weapon->move(npc);
			weapon->wield();
			if (mapp(u_max_skill))
			    npc->set_npc_combat_pfm((w_max_skill + u_max_skill), npc);
			else
			    npc->set_npc_combat_pfm(w_max_skill, npc);
		}
		else if(mapp(u_max_skill))
		{
			npc->set_npc_combat_pfm(u_max_skill, npc);
		}
	}

	npc->check_pfm(npc, u_max_skill, w_max_skill);
}

string get_max_lvskill(string *skills, mapping map_skills)	//获取武功数组中最高等级武功
{
	string temp, max_lvskill = "none";
	int max_level = 0;
	
	foreach(temp in skills)
	{
		if (max_level < map_skills[temp])
		{
			max_level = map_skills[temp];
			max_lvskill = temp;
		}
	}
	
	max_skill_lvl = max_level;
	return max_lvskill;
}

void set_npc_combat_pfm(mapping skill_map, object npc)
{
	string *pfm_file, *basic;
	string pfm_name, temp1, temp2;
	function *pfm_funcs = ({});
	
	basic = keys(skill_map);
    foreach(temp1 in basic)
    {
    	if (!sizeof(pfm_file = list_dirs(SKILL_D(skill_map[temp1]) + "/*.c")))
    	{
    		if (!sizeof(pfm_file = list_dirs(SKILL_D(skill_map[temp1]) + "/perform/*.c")))
    			continue;
    	}
    	foreach(temp2 in pfm_file)
    	{
    		sscanf(temp2, "%s.c", pfm_name);
    		pfm_funcs += ({(:perform_action, (temp1 + "." + pfm_name):)});
    		
    	}
    }

    if (sizeof(pfm_funcs))
	    npc->set("chat_msg_combat", pfm_funcs);
}

void check_pfm(object npc, mapping u_max_skill, mapping w_max_skill)
{
    int level = 0;
    string temp;
		
    if (mapp(u_max_skill) && sizeof(u_max_skill))
    {
        foreach(temp in values(u_max_skill))
        {
            if (npc->query_skill(temp) > level) level = npc->query_skill(temp);
        }
    }
    
    if (mapp(w_max_skill) && sizeof(w_max_skill))
    {
        foreach(temp in values(w_max_skill))
        {
            if (npc->query_skill(temp) > level) level = npc->query_skill(temp);
        }
    }
    
    if (level < 134)
        npc->set("chat_msg_combat", ({(: xuemo_pfm :)}));
}