// zhudanchen.c 朱丹臣


inherit NPC;

void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu" }));
	set("title",  "大理护卫" );
	set("long", "他是大理国四大护卫之一。一副书生酸溜溜的打扮行头。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1600);
	set("max_jing", 800);
	set("neili", 1900);
	set("max_neili", 1900);
	set("jiali", 35);
	set("combat_exp", 290000);
	set("score", 11000);

	set_skill("force", 75);
	set_skill("dodge", 70);
	set_skill("parry", 75);
	set_skill("cuff", 70);
	set_skill("sword", 75);
	set_skill("staff", 75);
	set_skill("wudang-xinfa", 75);
	set_skill("tiannan-step", 70);
	set_skill("jinyu-quan", 70);
	set_skill("duanjia-sword", 75);
	set_skill("literate", 95);

	map_skill("force", "wudang-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);

	create_family("大理段家", 0, "护卫");
}
