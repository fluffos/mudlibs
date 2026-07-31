// Last Modified by Winder on May. 29 2001
// Npc: /d/shaolin/npc/seng-bing1.c

inherit NPC;

void create()
{
	set_name("护林僧兵", ({ "seng bing", "seng", "bing"}));
	set("long", "他是一位身材高大的青年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭白布镶边袈裟，似乎有一身武艺。\n");

	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 3500);
	set("max_jing", 3300);
	set("neili", 3500);
	set("max_neili", 3500);
	set("pursuer", 1);
	set("combat_exp", 32000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("yijinjing", 330);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 330);
	set_skill("strike", 30);
	set_skill("banruo-zhang", 330);
	set_skill("claw", 30);
	set_skill("longzhua-gong", 330);
	set_skill("blade", 30);
	set_skill("cibei-dao", 330);
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

void init()
{
	object ob = this_player();
	
	::init();

	if (interactive(ob))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       
}

