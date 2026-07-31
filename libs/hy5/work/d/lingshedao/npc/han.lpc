//NPC: /d/lingshedao/npc/han.c
//Creat by Yjss on Sep.1999 
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_yy();
int ask_mj();
void create()
{
        set_name("金花婆婆", ({"jin hua", "han", "popo", }));
        set("long",
        "她弓腰曲背、白发如银,似是个贫家老妇.\n"
        "她不停地咳嗽着,看上去似乎连站也显得极是辛苦!\n"
        );

        set("nickname",HIW"夺命金花" NOR);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("shen_type",1);

        set("age", 50);
        set("per", 16);
        set("str", 30);
        set("int", 30);
        set("con", 30); 
        set("dex", 30);
        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 80);
        set("combat_exp", 2500000);
        set("score", 55000);
    
        set_skill("force", 340);
        set_skill("staff", 360);
        set_skill("dodge", 360);
        set_skill("parry", 340);
        set_skill("shenghuo-shengong", 350);
        set_skill("throwing", 360);
        set_skill("duoming-jinhua", 360);
        set_skill("xiaoyao-bu", 360);
        
        map_skill("parry", "duoming-jinhua");
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "xiaoyao-bu");
        map_skill("throwing", "duoming-jinhua");
        
        set("chat_chance", 500);
        set("chat_msg", ({
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
        }) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.lianhuan" :),
        }) );
	create_family("明教",34, "法王");

        set("inquiry", ([
             "明教" : (: ask_mj :),
             "银叶先生" : (: ask_yy :),
             "屠龙刀" : "等我拿到屠龙刀再去找灭绝老尼算帐!\n",
        ]) );

        setup();
        carry_object("/d/lingshedao/obj/jinhua")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}


void init()
{
        object ob=this_player();
        :: init();
        if(interactive(ob)&& ob->query_temp("nk") )
        {
        message_vision("金花婆婆对$N大叫一声:你这不是找死吗?\n",ob);
        kill_ob(ob);
        }
}


int ask_mj()
{
        message_vision("金花婆婆似在梦呓一般道:都是过去的事了,还提他做甚!
突然回过头来厉声问$N道:你究竟是谁,到底来干什么的?\n",this_player());
        return 1;
}

int ask_yy()
{
       message_vision("金花婆婆凄然道:他,他死得好冤哪!都是胡青牛这狗贼害的,我不会放过他的,
忽又凄然道:明教，明教，原来还不过是为了明教!\n",this_player());
       return 1;
}
#include "fawang.h"