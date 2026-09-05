// wujiang.c 武将

inherit __DIR__"ask_ning";
//inherit F_SKILL;

void create()
{
	set_name("武将", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("spear", 60);
	set_skill("yuejia-qiangfa", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	map_skill("spear", "yuejia-qiangfa");
	map_skill("parry", "yuejia-qiangfa");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/changqiang")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
    ::init();
}
