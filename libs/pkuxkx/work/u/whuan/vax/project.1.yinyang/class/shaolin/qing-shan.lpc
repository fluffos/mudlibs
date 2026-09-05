// Npc: /kungfu/class/shaolin/qing-shan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("清善比丘", ({
		"qingshan biqiu",
		"qingshan",
		"biqiu",
	}));
	set("long",
		"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 21);
	set("int", 18);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 30000);
	set("score", 500);

	set_skill("force", 50);
        set_skill("tongzi-gong", 50);
	set_skill("dodge", 45);
	set_skill("shaolin-shenfa", 45);
	set_skill("finger", 45);
	set_skill("nianhua-zhi", 45);
	set_skill("parry", 45);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "tongzi-gong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");

	create_family("少林派", 40, "弟子");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


#include "/kungfu/class/shaolin/qing.h"

