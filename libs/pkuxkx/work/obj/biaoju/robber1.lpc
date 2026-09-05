#pragma save_binary

#include <ansi.h>

inherit NPC;

mapping* skill_pack=({
([	"force_skill"	: "taiji-shengong",
	"unarmed_type"	: "cuff",
	"unarmed_skill" : "taiji-quan",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "taiji-jian",
	"dodge_skill"	: "tiyunzong",
	"menpai"        : "武当派",
]),
([	"force_skill"	: "yijinjing",
	"unarmed_type"	: "cuff",
	"unarmed_skill" : "jingang-quan",
	"weapon_type" 	: "whip",
	"weapon"	: "gangbian",
	"weapon_skill"	: "riyue-bian",
	"dodge_skill"	: "shaolin-shenfa",
	"menpai"        : "少林派",
]),
([	"force_skill"	: "celestial",
	"unarmed_type"	: "strike",
	"unarmed_skill" : "celestrike",
	"weapon_type" 	: "blade",
	"weapon"	: "gangdao",
	"weapon_skill"	: "spring-blade",
	"dodge_skill"	: "pyrobat-steps",
	"menpai"        : "天邪派",
]),
([	"force_skill"	: "niling-force",
	"unarmed_type"	: "strike",
	"unarmed_skill" : "celestrike",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "six-tian-sword",
	"dodge_skill"	: "pyrobat-steps",
	"menpai"        : "逆灵宫",
]),
([	"force_skill"	: "bahuang-gong",
	"unarmed_type"	: "hand",
	"unarmed_skill" : "deathhand",
	"weapon_type" 	: "blade",
	"weapon"	: "gangdao",
	"weapon_skill"	: "luocha-blade",
	"dodge_skill"	: "lingbo-weibu",
	"menpai"        : "灵鹫宫",
]),
([	"force_skill"	: "jiuyang-shengong",
	"unarmed_type"	: "strike",
	"unarmed_skill" : "moni-strike",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "shenghuo-lingfa",
	"dodge_skill"	: "yunlong-shenfa",
	"menpai"        : "明教",
]),
([	"force_skill"	: "beiming-shengong",
	"unarmed_type"	: "strike",
	"unarmed_skill" : "liuyang-zhang",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "xiaoyao-jian",
	"dodge_skill"	: "lingbo-weibu",
	"menpai"        : "逍遥派",
]),
([	"force_skill"	: "mystforce",
	"unarmed_type"	: "strike",
	"unarmed_skill" : "moni-strike",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "mystsword",
	"dodge_skill"	: "mysterrier",
	"menpai"        : "步玄派",
]),
([	"force_skill"	: "nine-moon-force",
	"unarmed_type"	: "strike",
	"unarmed_skill" : "liuyang-zhang",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "dugu-jiujian",
	"dodge_skill"	: "lingbo-weibu",
	"menpai"        : "魔剑山庄",
])
});

void time_to_go();
void set_level(int level_number);
int do_rob(object victim);
int real_rob(object victim);

void create()
{
	set_name("劫匪", ({ "jie fei", "jie", "fei","robber"}));
	if (random(10)>3) set("gender", "男性" );
		else set("gender", "女性" );
	set("age", 16+random(33));
        set("long", "这是一个拦路抢劫行人货物的劫匪\n");
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);
        set("max_force", 3000);
        set("eff_force", 3000);
        set("force", 3000);
        set("kar", 30);
        set("str", 30);
        set("con", 30);
        set("cor", 50);
        set("cps", 50);
        set("per", 50);
	setup();
	
}

void set_level(int level_number)
{
	int idx;
	idx=random(sizeof(skill_pack));
	if((int)skill_pack[idx]["female_only"]) 
		this_object()->set("gender", "女性" );
	set_skill("force",20*random(level_number)+70);
	set_skill(skill_pack[idx]["force_skill"],30*random(level_number)+70);
	set_skill(skill_pack[idx]["unarmed_type"],30*random(level_number)+70);
	if(stringp(skill_pack[idx]["unarmed_skill"]))
	{
		set_skill(skill_pack[idx]["unarmed_skill"],30*random(level_number)+70);
		map_skill(skill_pack[idx]["unarmed_type"],skill_pack[idx]["unarmed_skill"]);
		prepare_skill(skill_pack[idx]["unarmed_type"],skill_pack[idx]["unarmed_skill"]);
	}
	set_skill(skill_pack[idx]["weapon_type"],30*random(level_number)+70);
	set_skill(skill_pack[idx]["weapon_skill"],30*random(level_number)+70);
	set_skill("dodge",30*random(level_number)+100);
	set_skill(skill_pack[idx]["dodge_skill"],35*random(level_number)+70);
	set_skill("move",10);

	map_skill("force",skill_pack[idx]["force_skill"]);
	map_skill(skill_pack[idx]["weapon_type"],
	skill_pack[idx]["weapon_skill"]);
	map_skill("parry",skill_pack[idx]["weapon_skill"]);	
	map_skill("dodge",skill_pack[idx]["dodge_skill"]);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.zhuihun" :),
                (: perform_action, "sword.jianmang" :),
                (: perform_action, "blade.pili" :),
                (: perform_action, "sword.feihong" :),
                (: perform_action, "sword.li" :),
                (: perform_action, "sword.da" :),
        }) );
	create_family(skill_pack[idx]["menpai"],2,"弟子");
	set("combat_exp", 400000*(level_number+4));
	set("force", 10*(80*random(level_number)+1));
	set("max_force", 10*(80*random(level_number)+1));
	set("eff_force", query("max_force"));
	set("force_factor", 8*random(level_number)+80);
	
	set("max_mana", 10*(40*random(level_number)+1));
	set("eff_mana", query("max_force"));
	set("mana", 10*(40*random(level_number)+1));
	
	set("max_atman", 10*(40*random(level_number)+1));
	set("eff_atman", query("max_force"));
        set("atman", 10*(40*random(level_number)+1));
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);
	
/*        set("max_kee",120*random(level_number)+200);
	set("eff_kee",120*random(level_number)+200);
	set("kee",120*random(level_number)+200);

	set("max_gin",100*random(level_number)+100);
	set("eff_gin",100*random(level_number)+100);
	set("gin",100*random(level_number)+100);
	
	set("max_sen",100*random(level_number)+100);
	set("eff_sen",100*random(level_number)+100);
        set("sen",100*random(level_number)+100);*/

	set("bellicosity", 100*level_number);
	
	set_temp("apply/attack", 30*random(level_number));
	set_temp("apply/damage",30*random(level_number));
	set_temp("apply/armor", 30*random(level_number));
        set_temp("apply/dodge", 30*random(level_number));
        set_temp("apply/defense", 30*random(level_number));
	::setup();
	carry_object("obj/biaoju/"+skill_pack[idx]["weapon"])->wield();
}

int do_rob(object victim)
{
	call_out("real_rob",5,victim);
}
int real_rob(object victim)
{
	mapping exits;
	string *dirs;

/*	if (this_object()->is_fighting())
	{  
	     call_out("real_rob", 2, victim);
	     return 1;	 
	}
*/	if( mapp(exits = environment()->query("exits")) ) 
	{
		dirs = keys(exits);
		command("guard " + dirs[random(sizeof(dirs))]);
	}
	if(!objectp(victim)) 
	{
		call_out("time_to_go", 2);
		return 1;
	}
	if (command("rob "+victim->query("id")))
		call_out("real_rob", 2, victim);
	remove_call_out("time_to_go");
	call_out("time_to_go", 20);
	return 1;

}
void time_to_go()
{
	command("say 风紧,扯呼!");
	destruct(this_object());
}
void die()
{
	message_vision(HIW"$N大喊道：名不虚传，果然厉害，风紧，扯呼!\n"NOR,this_object());
	destruct(this_object());
}
