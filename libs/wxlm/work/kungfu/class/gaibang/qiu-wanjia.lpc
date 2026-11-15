// qiu-wanjia.c
// Modified by Venus Nov.1997

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()								   
{
	set_name("裘万家", ({"qiu wanjia", "qiu", "wanjia"}));
	set("title", "丐帮二袋弟子");
	set("gender", "男性");
	set("age", 16);
	set("long",
		"这是位地痞似的丐帮二袋弟子，看来是个吃得看的小地痞。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 19);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 150);
	set("max_jing", 140);
	set("neili", 370);
	set("max_neili", 370);
	set("jiali", 10);
	set("combat_exp", 12000);
	set_skill("force", 35);
	set_skill("jiaohua-neigong", 35);
	set_skill("unarmed", 35);
	set_skill("changquan", 35);
	set_skill("dodge", 35);
	set_skill("feiyan-zoubi", 35);
	set_skill("parry", 35);
	set_skill("begging", 35);
	set_skill("checking", 35);
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	create_family("丐帮", 20, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( !permit_recruit(ob) ) return;
	if( ob->query("gender") != "男性") return;

	command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
	command("recruit " + ob->query("id"));
}
