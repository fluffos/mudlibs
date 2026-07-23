//NPC: /d/lingshedao/npc/huiyue.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("辉月使", ({"hui yue", "hui",}));
        set("long",
        "这女子一头黑发，和华人无异，但眸子极淡，几乎无色.\n"
        );
        set("nickname",MAG"波斯明教总教护教使者" NOR);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("age", 30);
        set("shen_type",-1);
        set("per", 25);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 30);
set_temp("no_kill",1);
        set("max_qi", 7000);
        set("max_jing", 7200);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 50);
        set("combat_exp", 7400000);
        set("score",20000);

        set_skill("force", 380);
        set_skill("dodge", 380);
        set_skill("lingfa", 380);
        set_skill("parry", 380);
        set_skill("qiankun-danuoyi", 390);
        set_skill("shenghuo-shengong", 380);
        set_skill("shenghuo-ling",385);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qiankun-danuoyi");
        map_skill("parry", "shenghuo-ling");
        map_skill("sword", "shenghuo-ling");
       
        setup();
        carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object(__DIR__"obj/shenghuo-ling")->wield();
//        carry_object("/clone/book/shenghuo-ling")->wield();
        
}

void init()
{
        object ob=this_player();
        ::init();
        if(interactive(ob) && ob->query("party/party_name")== HIG "明教" NOR)
        message_vision(HIR"辉月使直盯盯的看着$N.\n"NOR,ob);
}


