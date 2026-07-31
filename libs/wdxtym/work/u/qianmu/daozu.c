inherit NPC;

void init_daozu();
int sort_exp(string user1, string user2);
int get_average_skill(object * top3);
void set_npc_skill(int skill_level);
void set_attribute(object * top3);

void chunyang();
void yinyang();
void jingwu();

void create()
{
	set_name("无争道祖", ({ "wuzheng daozu", "daozu" }));
	set("long", "道祖。\n");
	set("gender", "男性");
	set("age", 100);
	set("shen_type", 1);
	set("shen", 500000);
	set("str", 31);
	set("int", 39);
	set("con", 40);
	set("dex", 32);
	
	set("max_qi", 7500);
	set("max_jing", 5000);
	set("max_jingli", 4000);
	set("jingli", 4000);
	set("max_neili", 9999);
	set("neili", 9999);
	set("jiali", 600);
	set("combat_exp", 3200000);
	set("score", 1200000);

	set_skill("force", 300);
	set_skill("taiji-shengong", 300);
	set_skill("wudang-xinfa", 300);
	set_skill("dodge", 260);
	set_skill("tiyunzong", 260);
	set_skill("unarmed", 290);
	set_skill("taiji-quan", 290);
	set_skill("strike", 290);
	set_skill("wudang-zhang", 290);
	set_skill("hand", 290);
	set_skill("paiyun-shou", 290);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("wudang-jian", 300);
	set_skill("taiji-jian", 300);
	set_skill("blade", 260);
	set_skill("taiji-dao", 260);
	set_skill("taoism", 300);
	set_skill("literate", 180);
	set_skill("medical", 270);
	set_skill("liandan-shu", 270);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("hand", "paiyun-shou");
	map_skill("strike", "wudang-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("blade", "taiji-dao");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.tu" :),
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);
    
    init_daozu();
    
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init_daozu()
{
    object * players;
    object * top3;
    object temp;
    int max_qi = 0;
    int max_neili = 0;
    int max_jing = 0;
    int max_jingli = 0;
    mapping daozu = query_entire_dbase();
    
    players = users();
    
    foreach (temp in players)
    {
        max_qi += temp->query("max_qi");
        max_neili += temp->query("max_neili");
        max_jing += temp->query("max_jing");
        max_jingli += temp->query("max_jingli");
    }
    
    daozu["qi"] = daozu["eff_qi"] = daozu["max_qi"] = max_qi;
    daozu["neili"] = daozu["max_neili"] = max_neili;
    daozu["jing"] = daozu["eff_jing"] = daozu["max_jing"] = max_jing;
    daozu["jingli"] = daozu["max_jingli"] = max_jingli;
    
    players = sort_array(players, (: sort_exp :) );
    top3 = ({players[0], players[1], players[2]});
    
    set_npc_skill(get_average_skill(top3));
    
    set_attribute(top3);
}

int sort_exp(string user1, string user2)
{
	return (int)user2->query("combat_exp")-(int)user1->query("combat_exp");
}

int get_average_skill(object * top3)
{
	string temp1;
	mapping skill_map;
	string skills, temp2;
	int count_level, max_level = 0;
	string skill_name;
	
	foreach(temp1 in top3)
	{
		if(!(skill_map = temp1->query_skills()))
			continue;
		
		skills = (string)keys(skill_map);
		max_level = 0;
		foreach(temp2 in skills)
		{
		    if (SKILL_D(temp2)->type() == "knowledge")    continue;
			if(max_level < skill_map[temp2]) 
			{
			    max_level = skill_map[temp2];
			    skill_name = temp2;
			}
		}
		
		count_level += max_level;
	}
	
	return (count_level / sizeof(top3));
}

void set_npc_skill(int skill_level)
{
	string *skills;
	string temp;
	
	
	skills = keys(query_skills());
	
	foreach(temp in skills)
	{
	    set_skill(temp, skill_level);
	}
}

void set_attribute(object * top3)
{
    string * attribute = ({"con", "int", "dex", "str"});
    string temp1;
    object temp2;
    int attribute_count;
    
    foreach (temp1 in attribute)
    {
        attribute_count = 0;
        foreach(temp2 in top3)
        {
            attribute_count += temp2->query(temp1);
        }
        set(temp1, attribute_count / 3);
    }
}

void heart_beat()
{
    ::heart_beat();
    if (this_object()->is_fighting() && living(this_object()))
    {
        if (((query("qi") * 100 / query("max_qi")) < 30) && (random(10) == 1))
        {
            chunyang();
        }
        else if (random(100) < 5)
        {
            yinyang();
        }
        else if (random(100) < (10 + random(10)))
        {
            jingwu();
        }
    }
}

void chunyang()
{
    tell_room(environment(this_object()), "道祖运转纯阳真气，皮肤泛红，瞬间恢复了精神！\n");
    set("eff_qi", query("max_qi") / 2);
    set("qi", query("eff_qi"));
}

void yinyang()
{
    object * players;
    object target;
    
    players = filter_array(all_inventory(environment(this_object())), (: userp($1) :));
    target = players[random(sizeof(players))];
    message_combatd("$N大喝一声，左手化拳，一拳击中$n胸膛，阴阳二气涌入$n体内，$n喷出一口鲜血。\n", this_object(), target);
    target->die();
}

void jingwu()
{
    object * players;
    object temp;
    
    players = filter_array(all_inventory(environment(this_object())), (: userp($1) :));
    
    tell_object(players, "无争道祖口颂咒语，你只觉得一阵倦意袭来，顿时使不上力。\n");
    foreach (temp in players)
    {
        temp->start_busy(10);
    }
}

void die()
{
    object who = this_object()->query_last_damage_from();
    string banghui;
    
    banghui = who->query("banghui/name");
    tell_object(who, "bp_boss" + banghui + "\n");
    log_file("xxxxx", "909" + banghui + "\n");
    ::die();
}