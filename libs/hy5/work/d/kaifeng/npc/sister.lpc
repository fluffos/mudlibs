// sister.c 
// LOTS 1998/10/29

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("包新月", ({ "bao xinyue", "bao", "xinyue" }));
	set("long", 
		"她就是包大人的大小姐,据说她能掌上飞.\n"
		"据说她曾经在武当门下学过剑法。\n");
		
	set("title", "京城第一美");
	set("nickname", "赛飞燕");
	set("gender", "女性");
	set("age", 18);
	set("shen_type", 1);

	set("neili", 13000);
	set("max_neili", 13000);
	set("max_qi", 12000);
	set("max_jing", 1200);
	set("jiali", 10);
	set("per", 28);

	set_skill("force", 50);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 60);
	set_skill("sword", 100);
	set_skill("taiji-jian", 300);
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 100000);

	setup();
		carry_object(__DIR__"obj/cloth")->wear();
		carry_object("/clone/weapon/changjian")->wield();
}
