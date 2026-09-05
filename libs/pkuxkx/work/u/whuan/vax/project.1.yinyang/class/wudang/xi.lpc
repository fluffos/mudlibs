#include <ansi.h>
// xi.c 张松溪
inherit NPC;
void heal();

#include "/new_quest/qwudang.h"
#include "/new_quest/quest.h"
void create()
{
        set_name("张松溪", ({ "zhang songxi", "zhang" }));
       set("nickname", RED "武当四侠" NOR);

        set("long",
                "他就是张三丰的四弟子张松溪。\n"
                "他今年四十岁，精明能干，以足智多谋著称。\n");
	set("title", RED "武当派" NOR + GRN + "真人" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
		(: perform_action , "sword.chan" :),
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));

        set("max_qi", 1200);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 100000);

        set_skill("force", 150);
        set_skill("yinyun-ziqi", 150);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 120);
           set_skill("cuff", 130);
        set_skill("taiji-quan", 130);
        set_skill("parry", 150);
        set_skill("sword", 120);
        set_skill("taiji-jian", 120);
        set_skill("taoism", 100);
        set_skill("literate", 80);

	map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
           map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
      ]));


        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 50");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}
