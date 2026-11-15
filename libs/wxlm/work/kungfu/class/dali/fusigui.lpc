// fusigui.c 傅思归


inherit NPC;

void create()
{
	set_name("傅思归", ({ "fu sigui", "fu" }));
	set("title",  "大理护卫" );
	set("long", "他是大理国四大护卫之一。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 9500);

	set_skill("force", 65);
	set_skill("dodge", 65);
	set_skill("parry", 60);
	set_skill("cuff", 65);
	set_skill("sword", 60);
	set_skill("staff", 60);
	set_skill("shaolin-xinfa", 60);
	set_skill("tiannan-step", 65);
	set_skill("jinyu-quan", 65);
	set_skill("duanjia-sword", 60);
	set_skill("literate", 45);

	map_skill("force", "shaolin-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);

	create_family("大理段家", 0, "护卫");
}
