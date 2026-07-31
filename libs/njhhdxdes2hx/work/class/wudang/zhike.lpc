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
	set("title",RED "武当派" NOR + GRN "道士" NOR);
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_kee", 300);
	set("max_gin", 200);
	set("force", 300);
	set("max_force", 300);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("taiji-shengong", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 20);
	set_skill("taoism", 20);
	set_skill("tiyunzong", 30);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");

	create_family("武当派", 4, "弟子");

	setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
	carry_object("/obj/weapon/changjian")->wield();
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
