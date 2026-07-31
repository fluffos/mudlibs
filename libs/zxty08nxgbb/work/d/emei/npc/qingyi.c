// qingyixiaoni.c 青衣小尼

inherit NPC;

void create()
{
	set_name("青衣小尼", ({ "qingyi xiaoni", "qingyi", "xiaoni" }));
	set("long", 
		"她是峨嵋派的出家女弟子。\n");
	set("gender", "女性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);

	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("峨嵋派", 6, "弟子");

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
