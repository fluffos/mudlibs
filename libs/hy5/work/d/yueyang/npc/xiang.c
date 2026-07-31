// xiang.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("项长老", ({"xiang zhanglao", "xiang", "zhanglao"}));
	set("nickname", "丐帮六老");
	set("gender", "男性");
	set("age", 59);
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

        set("qi", 12000);
	set("max_qi", 12000);
	set("jing", 11800);
	set("max_jing", 11800);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 200);
	
	set("combat_exp", 2500000);
	set("score", 200000);
	set("shen", 100000);
	 	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("force", 150);             // 基本内功
	set_skill("huntian-qigong", 150);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 150);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("blade", 150);             // 基本刀法
	set_skill("liuhe-dao", 300);       // 四象六合刀
	set_skill("begging", 100);           // 叫化绝活
	set_skill("checking", 100);          // 道听途说
	set_skill("training", 100);          // 驭兽术
	set_skill("strike",85);  // 基本掌法
	set_skill("xianglong-zhang",185);
	//set_skill("yuejia-qiang", 180);        // 打狗棒法
	set_skill("suohou-gong", 180);        // 打狗棒法
set_skill("chansi-shou", 180); 
	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");

	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-dao");
	map_skill("parry", "liuhe-dao");
map_skill("parry", "chansi-shou");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");
	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
(: perform_action, "blade.lianhuan" :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 10, "传功长老");

	setup();
	
	carry_object("/clone/weapon/gangdao")->wield();
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

#include "/kungfu/class/gaibang/gaibang.h"


void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
message_vision("$N说道：乔峰你这契丹狗贼！......\n" NOR,this_object());
who->set_temp("killtlbb10",1);
	::die();
}