#include <ansi.h>
inherit BHNPC;

void create()
{
        set_name("江洋大盗", ({ "jiangyang dadao","dadao" }));
        set("nickname",HIW "逃犯"NOR);
        set("long", 
                "他是前段时间从扬州监狱里越狱出来的一个逃犯。\n"
                "他看起来满脸的惊慌失措。\n");
        set("gender", "男性");
        set("age", 31);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 2800);
        set("max_jing", 1800);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 50);

        set("chat_chance", 5);
        set("chat_msg", ({
             (: random_move :)
        }) );

        set("combat_exp", 1800000+random(600000));
        set("score", 10);

        set_skill("force", 135);
        set_skill("taiji-shengong", 135);
        set_skill("dodge", 150+random(60));
        set_skill("tiyunzong", 135);
        set_skill("unarmed", 150+random(60));
        set_skill("taiji-quan", 135);
        set_skill("parry", 135);
        set_skill("sword", 150+random(60));
        set_skill("taiji-jian",150+random(60));

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        

        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sui" :),
                (: exert_function, "recover" :),
                (: random_move :)
        }) );

        setup();
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

