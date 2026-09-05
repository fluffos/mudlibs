// gaoyanchao.c 高彦超

#include <ansi.h>

inherit NPC;

void create()

{


	set_name("高彦超", ({ "gao yanchao", "gao", "yanchao" }));

    	set("title", HIR "天地会"HIG"青木堂"NOR"会众");

	set("gender", "男性");


	set("age", 32);


	set("str", 25);


	set("dex", 20);


	set("long", "他不过三十出头，却显得异常老练。一言不发地往那儿一站，\n"


            "真是威风凛凛。\n");


	set("combat_exp", 40000);


	set("shen_type", 1);


	set("attitude", "peaceful");


	set_skill("hand", 50);
	set_skill("force", 60);
	set_skill("blade", 80);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("yunlong-shou", 60);
	set_skill("wuhu-duanmendao", 80);
	set_skill("yunlong-shenfa", 60);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("dodge", "yunlong-shenfa");

	prepare_skill("hand", "yunlong-shou");


	set_temp("apply/attack", 25);


	set_temp("apply/defense", 25);


	set_temp("apply/armor", 5);


	set_temp("apply/damage", 25);


	set("qi", 400);


	set("max_qi", 400);


	set("jing", 300);


	set("max_jing", 300);


	set("neili", 250);


	set("max_neili", 250);


	set("jiali", 35);


        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
                "反清复明" : "去棺材店内室仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
       ]) );
	setup();

        carry_object("/d/city/obj/gangdao")->wield();

	carry_object("/clone/misc/cloth")->wear();

	add_money("silver", 80);


}

