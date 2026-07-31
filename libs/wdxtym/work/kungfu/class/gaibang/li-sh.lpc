// gaibang npc code

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("黎生", ({"li sheng", "li", "sheng"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 38);
	set("long", 
		"这是位生性刚直，嫉恶如仇的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
	set("str", 32);
	set("int", 18);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 390);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);

	set("combat_exp", 480000);

	set_skill("force", 140);
	set_skill("jiaohua-neigong", 140);
	set_skill("unarmed", 120);
	set_skill("changquan", 120);
	set_skill("dodge", 100);
	set_skill("feiyan-zoubi", 100);
	set_skill("parry", 140);
	set_skill("staff", 135);
	set_skill("strike", 130);
	set_skill("jiaohua-bangfa", 135);
	set_skill("shenlong-baiwei", 130);
	set_skill("begging", 60);
	set_skill("checking", 110);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("strike", "shenlong-baiwei");

	set("no_teach/shenlong-baiwei", "这、这是洪帮主传我的，我不敢乱传。");

	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( !permit_recruit(ob) ) return;
	if( ob->query("shen") < 0 )
	{
		command("say 岂有此理！身为丐帮弟子，竟然不做好事？");
		return;
	}

	command("say 好，有你这样一等一的人才做我徒弟，我欢喜还来不及呢！");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
