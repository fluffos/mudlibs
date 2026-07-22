#include <ansi.h>
inherit NPC;

void create()
{
       	set_name("虾兵",({"xia bing","xia","bing",}));
	set_level(40);
	set("long","一个穿着盔甲的大虾米。\n");
	set("gender", "男性");
	set("age", 36);
	set("title", "东海护卫");
	set("class","dragon");
	set("attitude", "peaceful");
	set("shen_type", 1);
        create_family("东海龙宫", 4, "水族");
	setup();
}

void set_skills(int level)
{
	int j;
	if( level<40 )
		level = 40;
	level = level-5+random(5);
	set_level(level);
	j = level*10;
        set_skill("unarmed", j);
        set_skill("dodge", j);
        set_skill("parry", j);
        set_skill("force", j);
        set_skill("spells", j);
 	set_skill("fork", j);
        set_skill("fengbo-cha", j);
        set_skill("dragonstep", j);
        set_skill("dragonfight", j);
        set_skill("dragonforce", j);
        set_skill("seashentong", j);
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("unarmed", "dragonfight");
        set("chat_chance_combat",50);
	set("chat_msg_combat", ({
        	(: perform_action,"fork", "fengbo" :),
        	(: perform_action,"fork", "bibo" :),
        	(: perform_action,"fork", "dhwl" :),
        	(: exert_function, "shield" :),
        	(: exert_function, "recover" :),
	}));
        setup();
	carry_object(0,"armor",1)->wear();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"pifeng",1)->wear();
	carry_object(0,"kui",1)->wear();
	carry_object(0,"shoes",1)->wear();
	carry_object(0,"fork",1)->wield();
	powerup(0,1);
	set("num",level/5+random(level/5));
}

string short()
{
	if( query("num")>0 )
		return chinese_number(query("num"))+"位"+::short();
	else	return ::short();
}

void die()
{
	int i;
	object who;
	if( query("num")<=1 )
	{
		if( environment() )
		{
			message("vision","\n\n众虾兵给打的落花流水，慌不择路的逃了。\n\n",environment());
			if( environment()->is_sea() )
				environment()->fight5();
		}
		destruct(this_object());
		return;	
	}
	who = query_temp("last_damage_from");
	if( !who )
		i = 1;
	else
	{
		i = who->query_kar();
		i/= 8;
		i = i/2+random(i/2)+1;
	}
	if( environment() )
		message("vision","\n\n虾兵们给打得东倒西歪，其中"+chinese_number(i)+"只已化作大龙虾，跌跌撞撞的跑了。\n\n",environment());
	add("num",-i);
	if( query("num")<1 )
		set("num",1);
	powerup();
	this_object()->clear_condition();
	if( who )
		kill_ob(who);
}

void unconcious()
{
	die();
}
