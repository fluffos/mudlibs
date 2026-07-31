// ruanshizhong.c 阮士中

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("阮士中", ({ "ruan shizhong", "shizhong", "ruan" }) );
	set("gender", "男性");
	set("title", "辽东天龙门北宗第五代弟子");
	set("nickname", "七星手");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
set("neili", 33000);
	set("max_neili", 33000);
	set("jiali", 60);
	set("max_qi",22500);
	set("max_jing",21800);
	set("combat_exp", 9000000);
	set("shen_type", 1);

	set_skill("hand", 200);
	set_skill("unarmed",200);
	set_skill("sword", 300);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("hengshan-sword", 380);
	set_skill("luoyan-jian", 380); 
	set_skill("huiyan-xinfa",380);
	set_skill("luoyan-hand",380);
	set_skill("biluo-zhang",380);
	set_skill("qiuyan-nanhui",380);
	set_skill("literate",180);
	//set_skill("luteplaying",180);
set_skill("goplaying", 380);
set_skill("luteplaying", 380);
set_skill("jiutian-sword", 380);
	map_skill("sword", "jiutian-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "qiuyan-nanhui");
	map_skill("force", "huiyan-xinfa");
	map_skill("hand", "luoyan-hand");
	map_skill("strike", "biluo-zhang");
	prepare_skill("hand", "luoyan-hand");
	prepare_skill("strike", "biluo-zhang");
 
	set("env/wimpy", 60);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.xiangsi" :),
		(: perform_action, "sword.wuyun" :),
		(: perform_action, "sword.xiaofeng" :),
			(: perform_action, "parry.luoyan" :),
				(: perform_action, "parry.yunwu" :),
					(: perform_action, "dodge.nanhui" :),
		(: perform_action, "hand.jinghan" :),
		(: perform_action, "strike.huan" :),
		(: exert_function, "shield" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
