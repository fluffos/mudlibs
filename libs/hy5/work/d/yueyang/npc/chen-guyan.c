// chen-guyan.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("陈孤雁", ({"chen guyan", "chen", "guyan"}));
	set("nickname", "丐帮六老长臂叟");
	set("gender", "男性");
	set("age", 50);
	set("long","他是一个两条手臂甚长的老者。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 9000);
	set("max_qi", 9000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 13000);
	set("max_neili", 12000);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 190); // 基本内功
	set_skill("huntian-qigong", 190); // 混天气功
	set_skill("blade", 220); // 基本刀法
	set_skill("liuhe-dao", 220); // 四象六合刀
	set_skill("hand", 185); // 基本手法

	set_skill("dodge", 195); // 基本躲闪
	set_skill("xiaoyaoyou", 185); // 逍遥游
	set_skill("parry", 190); // 基本招架

	set_skill("strike",185);  // 基本掌法

	set_skill("xianglong-zhang",185);
        set_skill("liuhe-dao",300);
	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-dao");
	map_skill("parry", "liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");
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
	create_family("丐帮", 10, "弟子");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}
#include "/kungfu/class/gaibang/gaibang.h"
