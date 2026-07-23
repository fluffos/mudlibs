
// huogong.c 刀师
// By Lgg,1998.10

inherit NPC;

void create()
{
	set_name("刀师", ({"daoshi"}));
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是血刀门特别请回来打照兵器的刀师。\n");
	set("attitude", "friendly");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 500000);

	set_skill("force", 300);
	set_skill("xiantian-qigong", 300);	//先天气功
	set_skill("dodge", 300);
	set_skill("jinyan-gong", 300);   //金雁功
	set_skill("parry", 300);
	set_skill("strike",300);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "jinyan-gong");


	setup();

	carry_object("/d/xuedao/obj/changjian")->wield();


}

