//npc: xu-jie
//iszt
inherit NPC;

string ask_yaoli();
string ask_yaoxing();

void create()
{
        set_name("虚呆", ({
                "xu dai",
		"xu",
                "dai",
	}));
	set("long",
                "他是一位身穿黄布袈裟的青年僧人，臭名昭著的佛门内衣\n"
                "收藏爱好者——虚呆。看起来呆呆的，鼻涕都快到地上了。。。。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 15);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("combat_exp", 30000);

	set_skill("force", 60);
	set_skill("yijin-jing", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 60);
	set_skill("banruo-zhang", 60);
	set_skill("parry", 30);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 41, "弟子");

        set("inquiry", ([
                "batchelor" : "嗯，小僧认识。",
        ]));

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/xu-cloth")->wear();
        carry_object("/d/shaolin/obj/xu-cloth2");
        carry_object("/d/shaolin/obj/qing-cloth2");
        carry_object("/d/shaolin/obj/dao-cloth2");
        carry_object("/d/shaolin/obj/hui-cloth2");
        carry_object("/d/shaolin/obj/cheng-cloth2");
        carry_object("/d/shaolin/obj/xuan-cloth2");
}

