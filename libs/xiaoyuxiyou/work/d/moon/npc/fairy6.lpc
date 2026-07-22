//change.c
inherit SUPER_NPC;
#include "guanli.h"

void create()
{
	set_name("蝶衣",({"butterfly","die yi", "fairy"}));
	set("long",
"其仙袂乍飘兮，闻麝兰之馥郁；荷花欲动兮，听环佩之铿锵。靥笑春
桃兮，云髻堆翠；唇绽樱颗兮，榴齿含香。纤腰之楚兮，若风回雪舞
\n");
	set("title", "月宫舞仙");
	set("gender", "女性");
	set("age", 18);
	set("class", "xian");
	set("attitude", "friendly");
	set("rank_info/respect", "仙姑");
	set("force_factor", 40);
	set("mana_factor", 140);
	set_level(100);
	set_skill("literate", 1000);
	set_skill("unarmed", 1000);
	set_skill("dodge", 1000);
	set_skill("force", 1000);
	set_skill("parry", 1000);
	set_skill("sword", 1000);
	set_skill("spells", 1000);
 	set_skill("moonshentong", 1000);
 	set_skill("baihua-zhang", 1000);
 	set_skill("moonforce", 1000);
 	set_skill("snowsword", 1000);
 	set_skill("moondance", 1000);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
	create_family("月宫", 2, "弟子");
	set("env/test","HIB");
	set("inquiry", ([
   		"青鸾" : (: ask_guanli :),
	]));
	setup();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"sword",1)->wield();
	powerup(0,1);
}

void die()
{
	if( environment() )
	{
		message_vision("\n$N脸色一变，勉力逼住伤势，念动月华真言，化作一道霞光直冲太阴而去！\n\n");
		if( query_temp("last_damage_from") )
			lose_inventory();
	}
	destruct(this_object());
}