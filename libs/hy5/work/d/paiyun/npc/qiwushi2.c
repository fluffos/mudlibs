// xi.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("韩长老", ({"han zhanglao", "han", "zhanglao"}));
	set("nickname", "丐帮六老");
	set("gender", "男性");
	set("age", 50);
	set("long", "他是一个身材矮胖的老者，手持一条钢杖，性子直率，是本帮外家高手。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 15000);
	set("max_qi", 15000);
	set("jing", 15000);
	set("max_jing", 15000);
	set("neili", 35000);
	set("max_neili", 35000);
	set("jiali", 100);
	
	set("combat_exp", 1000000);
	set("score", 20000);
	
	set_skill("force", 90); // 基本内功
	set_skill("huntian-qigong", 90); // 混天气功
	set_skill("staff", 200); // 基本杖法
	set_skill("fengmo-zhang", 200); // 疯魔杖
	set_skill("hand", 85); // 基本手法

	set_skill("dodge", 95); // 基本躲闪
	set_skill("xiaoyaoyou", 85); // 逍遥游
	set_skill("parry", 90); // 基本招架

	set_skill("strike",85);  // 基本掌法
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");

	map_skill("staff", "fengmo-zhang");
	map_skill("parry", "fengmo-zhang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");
set_skill("force", 195);            // 基本内功
	set_skill("huntian-qigong", 190);   // 混天气功
	set_skill("hand", 190);             // 基本手法

	set_skill("staff", 190);            // 基本杖法

	set_skill("dodge",190);            // 基本躲闪
	set_skill("xiaoyaoyou", 195);       // 逍遥游
	set_skill("parry", 185);            // 基本招架
	set_skill("staff", 190);            // 基本棍杖
	set_skill("strike",185);  // 基本掌法

	set_skill("xianglong-zhang",185);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

		set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
	set_skill("strike",190);
	set_skill("force", 200);             // 基本内功
	set_skill("huntian-qigong", 180);   // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	
	set_skill("dodge", 160);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 180);       // 逍遥游
	set_skill("parry", 160);             // 基本招架
	set_skill("staff", 180);            // 基本棍杖
	set_skill("dagou-bang", 220);        // 打狗棒法
	set_skill("begging", 180);          // 叫化绝活
	set_skill("checking", 180);         // 道听途说
	set_skill("training", 180);        // 驭兽术
	
	map_skill("force", "huntian-qigong");

	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                        
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"六袋长老"NOR);
	set("party/level", 6);
	create_family("丐帮", 11, "弟子");
          set_temp("apply/attack", 100);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}

