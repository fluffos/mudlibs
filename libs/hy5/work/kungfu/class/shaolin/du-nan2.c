// dunan.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡难", ({ "du nan", "nan" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁铸成。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 8500000);
	set("score", 200000);

	set("str", 35);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 35);
	set("jing", 34000);
	set("max_jing", 34000);

	set("qi", 34000);
	set("max_qi", 32000);
	set("neili", 34000);
	set("max_neili", 35000);
	set("jiali", 80);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 150);
	set_skill("whip", 250);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 301);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
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
	set_skill("jingang-quan", 350);
	set_skill("longzhua-gong", 350);
	set_skill("luohan-quan", 350);
	set_skill("nianhua-zhi", 350);
	set_skill("pudu-zhang", 350);
	set_skill("qianye-shou", 350);
	set_skill("sanhua-zhang", 350);
	set_skill("weituo-gun", 350);
	set_skill("wuchang-zhang", 350);
	set_skill("xiuluo-dao", 350);
	set_skill("yingzhua-gong", 350);
	set_skill("yizhi-chan", 350);
	set_skill("zui-gun", 350);
	set_skill("buddhism", 300);
	//map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	//map_skill("club", "wuchang-zhang");
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
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chanrao" :),
                (: perform_action, "whip.fumoquan" :),
                            }) );


	set("count", random(10)-8);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2100);
        set_temp("apply/damage", 2100);

	setup();

	carry_object("/d/shaolin/obj/heibian")->wield();
}

