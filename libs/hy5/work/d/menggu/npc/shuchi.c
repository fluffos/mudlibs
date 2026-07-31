inherit NPC;
void create()
{
   set_name("术赤",({"shu chi"}));
   set("gender","男性");
   set("long","铁木真的大儿子,他脸形瘦削,生性险诈!\n");
   set("shen",-20000);
   set("combat_exp",70000);
   
set("age",39);
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);
        set("qi", 32000);
	set("max_qi", 32000);
	set("jing", 38000);
	set("max_jing", 38000);
	set("neili", 32000);
	set("max_neili", 32000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // 基本内功
	set_skill("huntian-qigong", 330);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 320);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法

	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-dao", 280);       // 四象六合刀
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 200);          // 道听途说
	set_skill("training", 200);          // 驭兽术
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

   set("chat_chance",5);
   set("chat_msg",({
"术赤嘿嘿冷笑两声:察合台是个笨蛋,这[汗]的位置迟早是我的.\n",
"术赤举起桌上的金樽,把血色的葡萄酒一饮而尽.\n",
}));

   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/tiejia")->wear();
carry_object(__DIR__"obj/jinqiang")->wield();
}
//void init()

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book594",1);
		


	::die();
}