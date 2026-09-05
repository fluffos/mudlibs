// yinzhe.c
//Made By:pingpang
#include <ansi.h>

inherit NPC;

void create()
{
    set_name("隐者", ({ "yin zhe", "zhe" }) );
    set("title", HIR "与世" NOR + CYN "隔绝" NOR);
    set("gender", "男性");
    set("age", 90);
    set("long",
            "这是一个面颊深陷，瘦骨零丁的老头，他脸色枯黄，如同一段枯木。\n");

    set("attitude", "peaceful");
    set("combat_exp", 100000);
    set("score", 20000);

    set("str", 20);
    set("int", 25);
    set("cor", 20);
    set("cps", 20);
    set("con", 20);

    set("qi", 1000);
    set("max_qi", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 30);

    set_skill("force", 80);
    set_skill("parry", 80);
    set_skill("dodge", 80);
    set("chat_chance_combat",100);

    set("inquiry", ([
                "陆乘风"     : "他就是当年[桃花岛]帮助我的黄岛主的徒弟。\n",
                ]));

    set("shen_type",1);set("score",500);setup();
    set("chat_chance",5);
    set("chat_msg",({"当年我在桃花岛时，多蒙陆大侠相助，才免于一难.可是至今没有他的音信。\n",
                "前面树林里老虎很多，谁能帮我杀了它们.\n",
                }));

    carry_object("/d/city/obj/cloth")->wear();
}

int accept_object(object who,object ob)
{
    object kaijia;
    if((string)ob->query("id")=="paper")
    {
        if(present("hu pi",this_player()))
        {
            if(this_player()->query_temp("get_kaijia"))
            {
                command("say 我已经给你金轮铠甲了啊，你怎么还来要？\n");
                return 0;
            }
            else
            {
                message_vision("\n隐者长笑一声，点点头，从屋后的藏宝处拿出金轮铠甲交给$N。\n\n", this_player());
                call_out("destroy",1,ob);
                kaijia=new(__DIR__"obj/kaijia");
                kaijia->move(this_player());
                this_player()->set_temp("get_kaijia",1); 
                command("say 你既然能闯进这猛虎出没的树林，必然是桃花岛中的非凡人物，这件铠甲是适逢其主了。\n");
                return 1;
            }
        }
        else command("say 树林里猛虎为害百姓，你能否为民除害?\n");
        return 0;
    }
    else
    { 
        command("say 好久没有陆庄主的消息了，不知老朋友最近可好?\n");
        command("look "+this_player()->query("id"));
        command("shake "+this_player()->query("id"));
        return 0;
    }
}

void destroy(object ob)
{
    destruct(ob);
    return;
}

