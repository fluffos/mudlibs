#include <ansi.h>
// yu.c 张翠山

inherit NPC;
inherit F_MASTER;

void heal();

void create()
{
        set_name("张翠山", ({ "zhang cuishan", "zhang" }));
       set("nickname", RED "武当五侠" NOR);
        set("long",
                "他就是张三丰的五弟子张翠山。\n"
                "他于武学的悟性极高，是张真人最喜欢的一个弟子，深得武当真传。\n"
                "他面目俊秀，虽然略觉清癯，但神朗气爽，身形的瘦弱竟掩不住一股剽悍之意。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 52);
        set("con", 28);
        set("dex", 28);
        set("per", 40);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );
        set("inquiry", ([
                "张无忌" : "这小家伙很是淘气，多包涵。\n",
                "谢逊" : "他是我义兄，有什么事到后洞找他吧。\n",
                "殷素素" : "她是我的娘子，如今已一心向善。\n",
        ]) );

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("max_qi", 3500);
        set("max_jing", 5800);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 200);
        set("combat_exp", 5000000);
        set("score", 100000);

        set_skill("force", 320);
        set_skill("taiji-shengong", 320);
        set_skill("dodge", 360);
        set_skill("tiyunzong", 360);
        set_skill("cuff", 320);
        set_skill("taiji-quan", 320);
        set_skill("parry", 350);
        set_skill("sword", 350);
        set_skill("taiji-jian", 250);
        set_skill("taoism", 280);
        set_skill("literate", 280);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
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

