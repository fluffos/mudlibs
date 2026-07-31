// caoyunqi.c 曹云奇

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("曹云奇", ({ "cao yunqi", "yunqi", "cao" }) );
	set("gender", "男性");
	set("title", "辽东天龙门北宗第六代掌门人");
	set("nickname", "腾龙剑");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
set("neili", 22400);
	set("max_neili", 22400);
	set("jiali", 230);
	set("max_qi",22000);
	set("max_jing",21200);
	set("combat_exp", 8000000);
	set("shen", -200000);
	set("book_count", 1);
	set("book_count1", 1);

	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set_skill("construction", 380);
	set_skill("painting", 380);


	        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        //set_skill("songyang-zhang", 380);
        //set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 380);
	set_skill("songyang-strike", 380);
	set_skill("poyun-hand", 380);
	set_skill("hanbing-zhenqi", 388);
	set_skill("fuguanglueying", 380);

set_skill("taoism", 388);
set_skill("club", 388);
set_skill("wuyue-spear", 388);
	set_skill("luoyan-jian", 200);
	set_skill("shiba-pan", 200);
	set_skill("songshan-jian", 200);
	set_skill("liuhe-dao", 200);
	set_skill("hengshan-jian", 200);


	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");

	map_skill("sword", "songshan-sword");
map_skill("parry", "songshan-sword");

	
	
	map_skill("dodge", "zhongyuefeng");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
    (: perform_action, "dodge.feng" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),	
			(: exert_function, "fenglei" :),	
	}) );

		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
