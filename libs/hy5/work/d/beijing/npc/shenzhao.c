// shenzhao.c
inherit NPC;

void create()
{
	set_name("神照上人", ({
		"shen zhao",
		"shen",
		"zhao",
	}));
	set("long",
		"他是一位秃顶老僧，身穿一袭红色镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("jing", 14000);
	set("max_jing", 14000);
	set("qi", 14000);
	set("max_qi", 12000);
	set("neili", 14000);
	set("max_neili", 15000);
	set("jiali", 90);



	set_skill("force", 251);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	//map_skill("whip",  "riyue-bian");
	map_skill("parry", "ranmu-daofa");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 200);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
	set_skill("yijinjing", 301);
	set_skill("ranmu-daofa", 300);
	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 190);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 190);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 190);
	set_skill("zui-gun", 190);
	set_skill("buddhism", 200);
	map_skill("blade", "ranmu-daofa");
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
                (: perform_action, "blade.huo" :),
                (: perform_action, "blade.fenxin" :),
                (: perform_action, "blade.fentian" :),
                            }) );

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
	setup();
	
	carry_object("/d/shaolin/obj/jgdao")->wield();
	carry_object("/clone/cloth/seng-cloth")->wear();
	//carry_object("/clone/cloth/seng-shoe")->wear();
}


