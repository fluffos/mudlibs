//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("苏万虹",({"su wanhong","su"}));
        set("gender", "男性");
        set("age", 20);
        set("long", 
               "他是凌霄城第六代弟子苏万虹,是白自在挺喜欢的小弟子。\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 1000);
        set("max_neili", 1000);
        set("max_jing", 1000);
        set("jing", 1000);
        set("max_qi", 1500);
        set("qi", 1500);
        set("jiali", 50);

        set("combat_exp", 80000);
        set("shen_type", 0);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 50);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 50);

        set_skill("xueshan-sword", 60);
        set_skill("bingxue-xinfa", 60);
        set_skill("snow-zhang", 60);
        set_skill("snowstep", 60);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/cloth/cloth")->wear();
}

