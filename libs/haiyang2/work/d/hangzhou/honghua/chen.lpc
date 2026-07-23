// chen.c 陈家洛

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("陈家洛", ({ "chen jialuo", "chen","jialuo" }));
	set("title", HIR "红花会"HIG"总舵主" NOR);
	set("long", 
"他一副模样直是个富贵人家的纨裤子弟，丰姿如玉，目朗似星，轻
袍缓带，手中摇着一柄折扇，神采飞扬，气度闲雅，吐属斯文。服
饰俨然是个贵介公子。\n");
	set("nickname", HIY"玉面神龙"NOR);
	set("gender", "男性");
	set("class", "scholar");
	set("age", 22);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 9000);
	set("max_jing", 6000);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);

	set_skill("literate", 300);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("whip", 300);
	set_skill("blade", 300);
	set_skill("sword", 300);
	set_skill("hand", 300);
	set_skill("claw", 300);
	set_skill("yunlong-xinfa", 300);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 350);
	set_skill("yunlong-jian", 300);
	set_skill("yunlong-shenfa", 350);
	set_skill("yunlong-bian", 350);
	set_skill("yunlong-shou", 350);
	set_skill("yunlong-zhua", 350);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
        set("chat_chance_combat", 90);  
        set("chat_msg_combat", ({
                (: command("unwield changjian") :),
                (: command("wield changjian") :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
        }) );

	set("env/wimpy", 60);

 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

