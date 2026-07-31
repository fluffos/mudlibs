inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("无常", ({ "figure", "wuchang" }));
	set("title", "黑衣人");
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "一个全身穿黑衣的家伙。\n");

	set("shen_type", 0);
	set("attitude", "heroism");

        set("qi", 9800);
	set("max_qi", 9800);
	set("jing", 8600);
	set("max_jing", 8600);
	set("neili", 14400);
	set("max_neili", 14400);
	set("jiali", 1300);

	set("combat_exp", 80050000);
	set("score", 200000);

	set_skill("cuff", 1200);
	set_skill("force", 1180);
	set_skill("blade", 1300);
	set_skill("dodge", 180);
	set_skill("parry", 1000);
	set_skill("sword", 320);
	set_skill("strike", 1200);
	set_skill("zixia-shengong", 980);
	set_skill("poyu-quan", 980);
	set_skill("fanliangyi-dao", 980);
	set_skill("huashan-sword", 980);
	set_skill("hunyuan-zhang", 980);
	set_skill("lonely-sword", 980);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 1200);
        set_skill("zhengqijue",300);
        
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");



	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 1550);
	set_temp("apply/damage", 1515);



	setup();
	carry_object("/p/item/ritemtz3/wsword13")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}



