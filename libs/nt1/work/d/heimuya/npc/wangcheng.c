// wangcheng.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("王诚", ({ "wang cheng","wang"}) );
	set("gender", "男性" );
	set("title", "日月神教风雷堂旗主");
	set("age", 65);
	set("long", "此人身材矮胖，满脸堆笑，其实为人十分狠毒。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 150);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("sword",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("日月神教",2,"弟子 风雷堂旗主");

	setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
     command("say 我是患难之身, 怎么能收徒呢。壮士还是请回吧!\n");
}

