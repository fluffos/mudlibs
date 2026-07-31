// shenzhao.c
inherit NPC;

void create()
{
	set_name("少林高手", ({
		"shaolin gaoshou",
		"shaolin",
	}));
set("long", "参加掌门人比武大会的高手。\n");

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("jing", 24000);
	set("max_jing", 24000);
	set("qi", 24000);
	set("max_qi", 22000);
	set("neili", 24000);
	set("max_neili", 25000);
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
	set_skill("banruo-zhang", 220);
	set_skill("cibei-dao", 220);
	set_skill("damo-jian", 220);
	set_skill("fengyun-shou", 220);
	set_skill("fumo-jian", 220);
	set_skill("jingang-quan", 220);
	set_skill("longzhua-gong", 220);
	set_skill("luohan-quan", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("pudu-zhang", 220);
	set_skill("qianye-shou", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("weituo-gun", 220);
	set_skill("wuchang-zhang", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("yingzhua-gong", 220);
	set_skill("yizhi-chan", 220);
	set_skill("zui-gun", 220);
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


