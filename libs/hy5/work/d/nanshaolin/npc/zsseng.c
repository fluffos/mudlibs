// Npc: /d/nanshaolin/npc/zsseng.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("执事僧", ({ "zhishi seng", "zhishi","seng" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"他是一位身材高大的青年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭白布镶边袈裟，似乎有一身武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("pursuer", 1);
	set("combat_exp", 2000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("yijinjing", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("strike", 30);
	set_skill("banruo-zhang", 30);
	set_skill("claw", 30);
	set_skill("longzhua-gong", 30);
	set_skill("blade", 30);
	set_skill("cibei-dao", 30);
	set_skill("parry", 30);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");
	prepare_skill("strike", "banruo-zhang");
	prepare_skill("claw", "longzhua-gong");

        create_family("南少林派", 22, "弟子");
	setup();

	carry_object(__DIR__"jiedao")->wield();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

