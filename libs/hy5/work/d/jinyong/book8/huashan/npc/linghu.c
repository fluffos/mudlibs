// linghu.c 令狐冲

inherit NPC;

void create()
{
	set_name("令狐冲", ({ "linghu chong", "linghu", "chong" }));
	set("nickname", "大师兄");
	set("long", 
"令弧冲身材较瘦，长的浓眉阔眼，气宇暄昂，他在\n"
"同门中排行老大，是华山派年轻一代中的顶尖好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 128000);
	set("max_qi", 128000);
	set("jing", 116000);
	set("max_jing", 116000);
	set("neili", 12400);
	set("max_neili", 12400);
	set("jiali", 60);
	
	set("combat_exp", 3000000);
	set("score", 100000);
	set_skill("chongling-jian", 380);
	set_skill("blade", 280);
	set_skill("cuff", 280);
	set_skill("feiyan-huixiang", 280);
	set_skill("hand", 280);
	set_skill("finger", 280);
	set_skill("strike",280);
	set_skill("claw", 280);
	set_skill("unarmed",280);
	set_skill("force", 280);
	set_skill("zixia-shengong", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("huashan-sword", 280);
	set_skill("literate", 120);
	
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "chongling-jian");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ai" :),
		(: perform_action, "sword.jianzhang" :),	
		(: perform_action, "sword.jie" :),	
		(: perform_action, "sword.jm" :),	
		(: perform_action, "sword.wudui" :),				
	      }) );
	create_family("华山派", 14, "弟子");
       
	setup();	 	
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}