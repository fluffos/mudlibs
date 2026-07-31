// ding.c 丁敏君

#include "emei.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("丁敏君", ({ "ding minjun","ding","minjun"}));
	set("long", "她是峨嵋派的第四代俗家弟子。是天下"
		    "最恶心，无赖的人。\n");
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");

	set("str", 20);
	set("int", 22);
	set("con", 21);
	set("dex", 24);

	set("max_qi", 1600);
	set("max_jing", 800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 90000);
	set_skill("force", 60);
	set_skill("throwing", 30);
	set_skill("dodge", 80);
	set_skill("finger", 70);
	set_skill("parry", 70);
	set_skill("strike", 70);
	set_skill("sword", 80);
	set_skill("jinding-zhang", 70);
	set_skill("tiangang-zhi", 70);
	set_skill("huifeng-jian", 80);
	set_skill("zhutian-bu", 80);
	set_skill("emei-xinfa", 70);

	map_skill("force","emei-xinfa");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");
	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}
