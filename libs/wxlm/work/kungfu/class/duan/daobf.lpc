// daobaifeng.c 刀素凰


#include "duan.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("刀素凰", ({ "dao baifeng", "dao" }));
	set("title",  "大理国王妃" );
	set("nickname",  CYN"玉虚散人"NOR );
	set("gender", "女性");
	set("long", @LONG
这是个容貌秀丽的中年道姑，是个摆夷族女子，颇有雍容气质。她本是
大理国皇帝段正纯的正房原配夫人。因恼丈夫风流不羁，沾花惹草，一
怒之下跑到这里出了家。
LONG );
	set("age", 35);
	set("class", "royal");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1800);
	set("max_jing", 900);
	set("neili", 2200);
	set("max_neili", 2200);
	set("jiali", 50);
	set("combat_exp", 420000);
	set("score", 8000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("cuff", 100);
	set_skill("strike", 100);
	set_skill("whip", 100);
	set_skill("kurong-changong", 100);
	set_skill("duanjia-sword", 100);
	set_skill("tiannan-step", 100);
	set_skill("jinyu-quan", 100);
	set_skill("wuluo-zhang", 100);
	set_skill("feifeng-whip", 100);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("whip", "feifeng-whip");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "feifeng-whip");
	map_skill("sword", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	setup();
	carry_object("/d/dali/npc/obj/cynrobe")->wear();
	carry_object("/d/dali/obj/fuchen")->wield();
	add_money("silver", 10);

	create_family("段氏皇族", 15, "传人");
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((string)ob->query("gender") != "女性")
	{
		command("say 我只收女弟子。");
		return;
	}

	command("say 好，我收下你了。");
	command("recruit " + ob->query("id"));
	return;
}
