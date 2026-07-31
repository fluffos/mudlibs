// xu.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("徐长老", ({"xu zhanglao", "xu", "zhanglao"}));
	set("gender", "男性");
	set("age", 85);
	set("long", "白须飘动，穿着一身补丁累累的鹑衣，是个年纪极高的老丐。\n");

	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 22000);
	set("max_qi", 22000);
	set("jing", 21000);
	set("max_jing", 21000);
	set("neili", 31500);
	set("max_neili", 31500);
	set("jiali", 100);

	set("combat_exp", 1200000);
	set("score", 20000);
	
	set_skill("force", 295);            // 基本内功
	set_skill("huntian-qigong", 290);   // 混天气功
	set_skill("hand", 290);             // 基本手法

	set_skill("staff", 290);            // 基本杖法

	set_skill("dodge",290);            // 基本躲闪
	set_skill("xiaoyaoyou", 295);       // 逍遥游
	set_skill("parry", 285);            // 基本招架
	set_skill("staff", 290);            // 基本棍杖
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",185);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

		set_skill("fengmo-zhang",280);
	set_skill("liuhe-zhang",280);
	set_skill("strike",290);
	set_skill("force", 100);             // 基本内功
	set_skill("huntian-qigong", 280);   // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 280);       // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 260);            // 基本棍杖
	set_skill("dagou-bang", 260);        // 打狗棒法
	set_skill("begging", 260);          // 叫化绝活
	set_skill("checking", 260);         // 道听途说
	set_skill("training", 260);        // 驭兽术
	
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
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 8, "弟子");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
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
who->set_temp("killtlbb13",1);
	::die();
}