// fanye.c 范骅


inherit NPC;

void create()
{
	set_name("范骅", ({ "fan ye", "fan" }));
	set("title",  "大理司马" );
	set("long", "他是大理国三公之一。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	
	set("max_qi", 1900);
	set("max_jing", 950);
	set("neili", 2900);
	set("max_neili", 2900);
	set("jiali", 50);
	set("combat_exp", 460000);
	set("score", 13000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("cuff", 80);
	set_skill("sword", 80);
	set_skill("staff", 80);
	set_skill("shaolin-xinfa", 80);
	set_skill("tiannan-step", 80);
	set_skill("jinyu-quan", 80);
	set_skill("duanjia-sword", 80);
	set_skill("literate", 80);

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
	add_money("silver", 20);

	create_family("大理段家", 0, "武将");
}
