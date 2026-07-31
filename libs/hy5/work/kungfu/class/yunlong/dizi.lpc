// xuanzhen.c 玄贞道长

#include <ansi.h>
inherit NPC;


void create()
{
	set_name("弟子", ({ "yl dizi", "dizi" }));
	set("gender", "男性");
	if (random(2)==0) set("gender", "女性");
	set("title", HIR "天地会"HIG"总舵"NOR"护法");
	set("long", "\n这位沉默寡言的人，便是天地会青木堂护法。\n"+
		"天地会训练的好手，一柄长剑使得出神入化。\n");
	set("age", random(30)+20);
	set("class", "taoist");
	set("int", 30);
	set("per",random(40));
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("shen_type", 1);

	set("combat_exp", 2200000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 100);
	set_skill("whip", 80);
	set_skill("hand", 70);
	set_skill("claw", 70);
	set_skill("yunlong-shengong", 170);
	set_skill("yunlong-shenfa", 170);
	set_skill("yunlong-xinfa", 170);
	set_skill("yunlong-bian", 170);
	set_skill("yunlong-jian", 280);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-zhua", 250);
	set_temp("apply/attack", 170);
	set_temp("apply/defense", 170);
	set_temp("apply/damage", 160);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-jian");
	map_skill("sword", "yunlong-jian");
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");
	create_family("云龙门",3, "弟子");
	set("book_count", 1);
        set("inquiry", ([
		"陈近南" :  "\n江湖威望值达到70就可以拜总舵主为师。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武功。\n",
                "反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({

                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
                      }) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
        
}

