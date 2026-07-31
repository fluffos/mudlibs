// zhao.c 静照师太
// Modified by That Oct.1997

inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
#include "emei.h"
#include "tobebonze.h"

string ask_for_join();

void create()
{
	set_name("静照师太", ({ "jingzhao shitai","jingzhao","shitai"}));
	set("long", "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
	set("gender", "女性");
	set("age", 43);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 20);
	set("int", 21);
	set("con", 20);
	set("dex", 22);

	set("max_qi", 2100);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);

	set("combat_exp", 110000);
	set_skill("persuading", 80);
	set_skill("throwing", 60);
	set_skill("force", 90);
	set_skill("dodge", 70);
	set_skill("finger", 60);
	set_skill("parry", 75);
	set_skill("strike", 70);
	set_skill("sword", 60);
	set_skill("mahayana", 60);
	set_skill("literate", 70);
	set_skill("jinding-zhang", 60);
	set_skill("tiangang-zhi", 70);
	set_skill("huifeng-jian", 60);
	set_skill("zhutian-bu", 60);
	set_skill("emei-xinfa", 90);
	set_skill("linji-zhuang", 90);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	create_family("峨嵋派", 4, "弟子");

	set("no_teach", ([
		"linji-zhuang" : "想学临济十二庄？找灭绝师太去。",
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}
