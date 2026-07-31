// gaibang npc code

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("马俱为", ({"ma juwei", "ma", "juwei"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位武艺精强，却沉默寡言的丐帮七袋弟子。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 22);
	set("con", 25);
	set("dex", 30);

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 350);
	set("max_jing", 350);
	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 32);
	
	set("combat_exp", 180000);
	
	set_skill("force", 120);
	set_skill("jiaohua-neigong", 120);
	set_skill("unarmed", 120);
	set_skill("changquan", 120);
	set_skill("dodge", 120);
	set_skill("feiyan-zoubi", 120);
	set_skill("parry", 120);
	set_skill("staff", 120);
	set_skill("begging", 60);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( !permit_recruit(ob) ) return;
	if( ob->query_con() < 22 )
	{
		command("say 你的根骨不佳，吃不了苦，还是算了吧！");
		return;
	}

	command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
