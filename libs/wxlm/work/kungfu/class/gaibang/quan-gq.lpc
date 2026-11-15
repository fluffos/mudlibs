// gaibang npc code

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("全冠卿", ({"quan guanqing", "quan", "guanqing"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位沉默寡言却颇有心计的阴毒的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 25);
	set("int", 32);
	set("con", 28);
	set("dex", 27);

	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 40);
	
	set("combat_exp", 500000);
	
	set_skill("force", 150); 
	set_skill("jiaohua-neigong", 150); 
	set_skill("unarmed", 160); 
	set_skill("changquan", 160); 
	set_skill("dodge", 170); 
	set_skill("feiyan-zoubi", 170); 
	set_skill("parry", 160); 
	set_skill("staff", 150); 
	set_skill("begging", 80); 
	set_skill("training", 120);
	
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( !permit_recruit(ob) ) return;
	if( ob->query_con() < 24 )
	{
		command("say 你个根古不佳，不适合学我的武功。");
		return;
	}

	command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
	command("recruit " + ob->query("id"));
}
