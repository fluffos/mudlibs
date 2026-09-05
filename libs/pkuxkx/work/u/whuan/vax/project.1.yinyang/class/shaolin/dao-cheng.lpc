// Npc: /kungfu/class/shaolin/dao-cheng.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("道成禅师", ({
		"daocheng chanshi",
		"daocheng",
		"chanshi",
	}));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 21);
	set("int", 20);
	set("con", 19);
	set("dex", 24);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("force", 60);
	set_skill("hunyuan-yiqi", 65);
    set_skill("tongzi-gong",70);
	set_skill("dodge", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("strike", 65);
	set_skill("banruo-zhang", 65);
	set_skill("claw", 70);
	set_skill("longzhua-gong", 70);
	set_skill("parry", 65);
	set_skill("buddhism", 60);
	set_skill("literate", 60);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "longzhua-gong");

	prepare_skill("claw", "longzhua-gong");

	create_family("少林派", 39, "弟子");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}


#include "/kungfu/class/shaolin/dao.h"

