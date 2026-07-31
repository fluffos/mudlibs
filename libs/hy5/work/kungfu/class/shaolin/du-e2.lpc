// due.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡厄", ({ "du e", "e" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色枯黄，如同一段枯木。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 8500000);
	set("score", 200000);

	set("str", 36);
	set("int", 36);
	set("cor", 30);
	set("cps", 30);
	set("con", 36);


	set("qi", 34000);
	set("max_qi", 34000);
	set("neili", 35000);
	set("max_neili", 35000);
	set("max_jing", 35000);
	set("jiali", 90);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 350);
	set_skill("cibei-dao", 350);
	set_skill("damo-jian", 350);
	set_skill("fengyun-shou", 350);
	set_skill("fumo-jian", 350);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 350);
	set_skill("luohan-quan", 350);
	set_skill("nianhua-zhi", 350);
	set_skill("pudu-zhang", 350);
	set_skill("qianye-shou", 350);
	set_skill("sanhua-zhang", 350);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 350);
	set_skill("xiuluo-dao", 350);
	set_skill("yingzhua-gong", 350);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	//map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	//map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	//map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );


	set("count", random(10)-8);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2100);
        set_temp("apply/damage", 2100);

	setup();
	carry_object("/d/shaolin/obj/jingangchu")->wield();
}

