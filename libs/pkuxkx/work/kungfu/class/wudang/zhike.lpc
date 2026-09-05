// zhike.c 知客

#include <ansi.h>

inherit NPC;

void heal();

void create()
{
	set_name("知客道长", ({ "zhike daozhang", "zhike" }));
	set("long", 
		"他是武当山的知客道长。\n");
	set("gender", "男性");
	set("title", RED "武当派" NOR + GRN "道长" NOR);
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
		(: perform_action , "cuff.zhen" :)
        }) );

	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 20);
	set_skill("taoism", 20);
	set_skill("taiji-shengong", 40);
	set_skill("cuff", 20);
	set_skill("taiji-quan", 30);

	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "taiji-quan");

	create_family("武当派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
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
