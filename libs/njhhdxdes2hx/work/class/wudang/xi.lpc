#include <ansi.h>
// xi.c 张松溪

inherit NPC;

void heal();
void create()
{
        set_name("张松溪", ({ "zhang songxi", "zhang" }));
       set("nickname", RED "武当四侠" NOR);

        set("long",
                "他就是张三丰的四弟子张松溪。\n"
                "他今年四十岁，精明能干，以足智多谋著称。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("max_kee", 1200);
        set("max_gin", 800);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 50);
        set("combat_exp", 100000);
        set("score", 50000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 80);
        set_skill("taiji-shengong", 60);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 60);
           set_skill("cuff", 80);
        set_skill("taiji-quan", 60);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("taiji-jian", 60);
//      set_skill("taoism", 80);
        set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
           map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/obj/weapon/gangjian")->wield();
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
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
