// li.c

inherit NPC;
inherit F_GUARDER;
inherit F_UNIQUE;

void create()
{
	set_name("李管家", ({ "li", "li guanjia" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是个和蔼可亲的大管家。\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("class", "fighter");

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 5000);
	set("qi", 5000);
	set("max_jing", 5000);
	set("jing",5000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 0);

	set("combat_exp", 250000);
	set("score", 20000);

	set_skill("force", 100);
	set_skill("dodge", 120);
	set_skill("unarmed", 110);
	set_skill("parry", 100);
	set_skill("chanchu-bufa", 100);
	set_skill("changquan", 100);

	map_skill("dodge", "chanchu-bufa");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	create_family("欧阳世家", 0, "管家");

	set("coagents", ({
	    ([ "startroom" : "/d/baituo/dating",
	       "id"	: "ouyang feng" ]),
	}));

	set("chat_chance", 2);
	set("chat_msg", ({
		"李管家说道: 勤学苦练方可出神功..\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if (ob->query("born_family") != "欧阳世家")
	{
		command("shake");
		command("say 哪里来的家伙居然敢来白驼山添乱？");
		return;
	}

	command("say 呵呵，我不收徒，去找欧阳庄主吧。\n");
	return;
}
