// song.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("宋长老", ({"song zhanglao", "song", "zhanglao"}));
	set("nickname", "丐帮六老");
	set("gender", "男性");
	set("age", 50);
	set("long", "他是一个白须老者，是本帮外家奇门兵器高手。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 12000);
	set("max_qi", 12000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 13000);
	set("max_neili", 12000);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 290); // 基本内功
	set_skill("huntian-qigong", 290); // 混天气功
	set_skill("hand", 185); // 基本手法

	set_skill("dodge", 195); // 基本躲闪
	set_skill("xiaoyaoyou", 255); // 逍遥游
	set_skill("parry", 190); // 基本招架

	set_skill("strike",185);  // 基本掌法

	set_skill("xianglong-zhang",255);

	map_skill("unarmed","xianglong-zhang");
	map_skill("strike","xianglong-zhang");
	prepare_skill("strike","xianglong-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 10, "弟子");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
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
who->set_temp("killtlbb11",1);
	::die();
}