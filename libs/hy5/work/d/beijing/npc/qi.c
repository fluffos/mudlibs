// qi.c
inherit NPC;

void create()
{
	set_name("齐元凯", ({ "qi yuankai", "qi" }));
	set("long", "此人身材瘦长，却是气宇暄昂, 似乎身怀惊人艺业。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 7000);
	set("max_jing", 7000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("score", 60000);
        set_skill("taoism", 180);
	set_skill("force", 100);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 180);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 180);
	set_skill("wudang-jian", 180);
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
	set("inquiry", ([
		"四十二章经": "咦，你也知道康亲王府里有宝书？\n",
		"书": "咦，你也知道康亲王府里有...？\n",
		"钥匙" : "咦，你也知道取书要金钥匙？\n",
	]) );
	set("chat_chance", 1);
	set("chat_msg", ({
		"齐元凯忽然说: 今晚取了书我就走。\n",
		"齐元凯一咬牙，说道: 这仆役太贪了，事成之后一定杀了他灭口。\n",
		"齐元凯自言自语道: 不行，只怕还有机关。\n",
	}) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male1-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
	add_money("gold",1);
}

