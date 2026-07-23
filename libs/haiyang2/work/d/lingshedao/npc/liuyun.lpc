//NPC: /d/lingshedao/npc/liuyun.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("流云使", ({"liu yun", "liu",}));
        set("long",
        "这人身材高大,虬髯碧眼,眼中透出一股邪气.\n"
        );
        set("nickname",MAG"波斯明教总教护教使者" NOR);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 30);
        set("shen_type",-1);
        set("per", 18);
        set("str", 40);
        set("int", 20);
set_temp("no_kill",1);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 7000);
        set("max_jing", 7200);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 60);
        set("combat_exp", 1550000);
        set("score",50000);
       
        set_skill("force", 385);
        set_skill("dodge", 385);
        set_skill("lingfa", 385);
        set_skill("parry", 385);
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
        if(interactive(ob) && ob->query("party/party_name")== HIG "明教" NOR)
    {
        message("vision",HIC"流云使朗声说道:明教圣火令到，护教狮王还不下跪迎接，更待何时?\n\n"NOR,"/d/lingshedao/xiaowu");
        message_vision(HIC"流云使接着对$N厉声说道:你是我明教门众,见了护教使者,为何不下跪?\n\n"NOR,ob);
        tell_object(ob,HIC"你决定下跪(kneel)还是拒绝(refuse)?\n\n"NOR);
    }
        add_action("do_kneel","kneel");
        add_action("do_refuse","refuse");
}

int do_kneel()
{       
        object tld;
        object ob=this_player();
if (ob && present("tulong dao",ob))
{
        message_vision("$N恭恭敬敬的跪在地上,说道:在下"+ob->query("name")+"恭迎护教使者.\n\n",ob);
        message("vision",HIC"流云使哈哈大笑,说道:不错,不错.不过你手中的这把刀,本使者倒是看上了,拿来罢!\n\n"NOR,"/d/lingshedao/xiaowu");
        message_vision(HIC"说完流云使将$N手中的屠龙刀拿了过去.\n\n"NOR,ob);
        tld=present("tulong dao",ob);
if (tld)
{
        tld->move(this_object());
}
}
        call_out("dest",0,ob);
        return 1;
}

int do_refuse()
{
        object ob=this_player();
if (ob)
{
        message_vision(HIC"$N凛然说道:我虽是明教门众,可我加入的是中土明教,却不是你那个波斯明教,为何下跪?\n\n"NOR,ob);
        message_vision(HIC"流云使脸色一沉,怒道:胡说九道,胡说九道,
今日非让你见识一下我们的厉害不可.\n\n"NOR,ob);
        message_vision(HIC"流云使大手一挥,但见妙风使,辉月使围了上来,流云使对$N大喝一声:接招罢.\n\n"NOR,ob);
        call_out("fight3",5,ob);
}
        return 1;
}

#include "shi.h"
/*int fight3(object ob)
{       
   say("haha,test\n");
   return 1;
}*/
