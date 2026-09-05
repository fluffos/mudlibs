// Npc: /kungfu/class/shaolin/xu-ming.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;


void create()
{

	set_name("虚明", ({
		"xu ming",
		"xu",
		"ming",
	}));
	set("long",
		"他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n"
	);

	set("title",HIR "少林" NOR + CYN "知客僧" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("combat_exp", 20000);
	
	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo-zhang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 41, "弟子");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/xu-cloth")->wear();

}



