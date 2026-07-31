//Npc: /u/lots/npc/shiwei.c
// Date: LOTS 98/10/14
// modified by wind

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("带刀侍卫", ({
		"shi wei",
		"wei",
		"shi",
	}));
	set("long",
		"这是一个高大威猛的汉子,因为久在官场做事,脸上已磨练的毫无表情.\n"+
		"他正在开封府前等你来告状\n"
	);


	set("nickname", "御赐五品带刀侍卫");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "officer");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 800000);
	set("score", 1000000);

// before the modification, all the skills are 120
	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 180);
	set_skill("shaolin-shenfa", 180);
	set_skill("parry", 120);
	set_skill("staff", 120);
	set_skill("blade", 120);
	set_skill("hanbing-mianzhang", 300);
	set_skill("xiuluo-dao", 250);
	set_skill("luohan-quan", 300);
	set_skill("strike", 300);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("blade", "xiuluo-dao");
	map_skill("strike", "hanbing-mianzhang");
	prepare_skill("strike", "hanbing-mianzhang");



	set("inquiry", ([
	]));

	set("chat_chance_combat", 45);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();

	carry_object(__DIR__"obj/ironblade")->wield();
	carry_object(__DIR__"obj/yayifu")->wear();
}

