// ma-dayuan.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("马大元", ({"ma dayuan", "ma", "dayuan"}));
	set("gender", "男性");
	set("age", 29);
	set("long", 
"他就是丐帮第十任副帮主，办事谨慎仔细，是帮中一把好手。
一手锁喉擒拿手威震武林。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

        set("qi", 32000);
	set("max_qi", 32000);
	set("jing", 3800);
	set("max_jing", 3800);
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

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"副帮主"NOR);
	set("party/level", 10);
	create_family("丐帮", 10, "弟子");
       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	setup();
	
	carry_object(__DIR__"yuejia-spear")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20)
	{
		command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐帮")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老叫化呢？");
		return;
	}
	if ((int)ob->query_skill("huntian-qigong",1) < 80)
	{
		command("say 你的混天气功修为不够。\n");
		return;
	}

	if ((int)ob->query_skill("xianglong-zhang",1) < 80)
	{
		command("say 你的降龙十八掌修为不够。\n");
		return;
	}

	if ((int)ob->query_skill("dagou-bang",1) < 80)
	{
		command("say 你的打狗棒修为不够。\n");
		return;
	}
	command("recruit "+ob->query("id"));
}

