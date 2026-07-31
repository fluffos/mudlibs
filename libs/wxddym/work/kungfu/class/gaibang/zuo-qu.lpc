// gaibang npc code

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("左全", ({"zuo quan", "zuo", "quan"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("qi", 720);
	set("max_qi", 720);
	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1210);
	set("max_neili", 1210);
	set("jiali", 32);
	
	set("combat_exp", 350000);
	
	set_skill("force", 130); 
	set_skill("jiaohua-neigong", 130); 
	set_skill("unarmed", 130); 
	set_skill("changquan", 130); 
	set_skill("dodge", 130); 
	set_skill("feiyan-zoubi", 130); 
	set_skill("parry", 120); 
	set_skill("begging", 80); 
	set_skill("checking", 60); 
	
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( !permit_recruit(ob) ) return;

	command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
