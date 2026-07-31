// modified by explorer, 3/9/97
inherit NPC;
void create()
{
        set_name("小洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "九指神丐");
        set("gender", "男性");
        set("age", 75);
        set("long", 
                "他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
        set("attitude", "friendly");
        set("str", 40);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 18000);
	set("max_neili", 18000);
	set("jiali", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // 基本内功
	set_skill("huntian-qigong", 300);    // 混天气功
	set_skill("unarmed", 200);           // 基本拳脚
	set_skill("xianglong-zhang", 300);   // 降龙十八掌
	set_skill("dodge", 200);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 250);        // 逍遥游
	set_skill("parry", 200);             // 基本招架
	set_skill("staff", 200);             // 基本棍杖
	set_skill("dagou-bang", 300);        // 打狗棒法
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 250);          // 道听途说
	set_skill("training", 250);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );

        create_family("丐帮", 17, "帮主");
        setup();

        carry_object(__DIR__"obj/yzb")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/badan");
}
