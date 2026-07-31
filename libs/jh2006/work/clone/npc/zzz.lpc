// zzz.c
#include <ansi.h>
inherit NPC;
void create()

{
       set_name("张昭重", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "铁捕");
	set("long", 
		"他就是张昭重。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :)
	}));

	set_skill("force", 200);
        set_skill("yinyun-ziqi", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 180);
	set_skill("cuff", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("taoism", 150);
	set_skill("literate", 100);

        map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	prepare_skill("cuff", "taiji-quan");

        setup();
	carry_object("/clone/weapon/changjian1")->wield();
       carry_object("/clone/armor/cloth")->wear();
//       carry_object("/u/yuj/mask")->wear();
            setup();

}

 
