// qi.c
inherit NPC;

void create()
{
	set_name("武当高手", ({ "wudang gaoshou", "wudang" }));
	set("long", "参加掌门人比武大会的高手。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 27000);
	set("max_jing", 27000);
	set("neili", 29000);
	set("max_neili", 29000);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("score", 60000);
        set_skill("taoism", 180);
	set_skill("force", 100);
	set_skill("taiji-shengong", 250);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 250);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("taiji-jian", 250);
	set_skill("wudang-jian", 250);
	set_skill("literate", 50);
	set_skill("raozhi-roujian", 180);
	set_skill("wudang-mianzhang", 280);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 250);
	set_skill("shenmen-jian", 250);
	set_skill("yitian-zhang", 250);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "paiyun-shou");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
prepare_skill("hand", "paiyun-shou");
prepare_skill("strike", "yitian-zhang");
	
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set("env/wimpy", 60);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male1-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
	//add_money("gold",1);
}

