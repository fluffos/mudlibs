 // tao_2.c
inherit NPC; 
void create()
{
        set_name("孙天灭", ({ "fighter", "taoist fighter" }) );
        set("nickname", "六指小真人");
        set("gender", "男性");
        set("age", 20);
        set("long",
"孙天灭外号六指小真人，据说是丁乘风最喜爱的徒弟，尽得师傅真传！\n可不知道为什么被派到这里来看大门。\n"
);
        set("combat_exp", 100000);
        set("score", 500); 
        set("class", "taoist"); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30); 
        set("force", 1000);
        set("max_neili", 500);
        set("force_factor", 20); 
        set("atman", 1000);
        set("max_atman", 1000); 
        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 5); 
        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );

        create_family("三清宫", 6, "弟子"); 
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
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20); 
        setup(); 
        add_money("coin", 3);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object("/clone/misc/cloth")->wear(); 
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="三清宫" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 三清宫不和别派的人过招。");
        return 0;
}
       
