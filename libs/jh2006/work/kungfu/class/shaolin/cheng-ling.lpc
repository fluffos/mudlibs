// Npc: /kungfu/class/shaolin/cheng-ling.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
    set_name("澄灵", ({
		"chengling luohan",
		"chengling",
		"riyue",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);


	set("nickname", "日月罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen", 5000);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 600000);
    set("unique", 1);

	set_skill("force", 120);
	set_skill("yijin-jing", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("leg", 120);
	set_skill("shaolin-tantui", 120);
	set_skill("parry", 120);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("leg", "shaolin-tantui");
	map_skill("parry", "shaolin-tantui");
 
        prepare_skill("leg", "shaolin-tantui");

	create_family("少林派", 37, "弟子");

	setup();

        
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();

}


#include "/kungfu/class/shaolin/cheng.h"

