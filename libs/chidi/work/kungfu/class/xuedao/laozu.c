// /kungfu/class/xueshan/laozu.c  血刀老祖

#include <ansi.h>
inherit BHNPC;
inherit F_MASTER;
string ask_me();
void create()
{
        set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
        );
        set("title",HIR"血刀门第四代掌门"NOR);
        set("gender", "男性");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen", -2000000);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 8000);
        set("max_jing", 6000);
        set("neili", 25000);
        set("max_neili", 22000);
        set("jiali", 250);
        set("combat_exp", 8000000);
        set("score", 180000);

        set_skill("lamaism", 1450);
        set_skill("literate", 1400);
        set_skill("force", 1450);
        set_skill("parry", 1450);
        set_skill("blade", 1450);
        set_skill("dodge", 1450);
        set_skill("longxiang", 1450);
        set_skill("shenkong-xing", 1450);
        set_skill("hand", 1450);
        set_skill("dashou-yin", 1450);
        set_skill("xue-dao", 1450);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand",  "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");

        set("inquiry", ([
                "血刀" : (: ask_me:),
                "神刀" : (: ask_me:),   
        ]));

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "blade.shendao" :),
                (: perform_action, "hand.yin" :),
                (: exert_function, "fanchang" :),
                (: exert_function, "recover" :),
        }) );

        create_family("血刀门", 1, "弟子");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object(__DIR__"xuedao")->wield();

        add_money("gold",2);
}




void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen") >= 0
                 && ob->query("family/master_id")=="xuedao laozu")
        {
                      command("chat "+ob->query("name")
                      +"! 装什么正道人士，从此以后你就不要再回血刀门来了! \n");
                      command("expell "+ ob->query("id"));
                      this_player()->set("title","血刀门" + RED + "弃徒" NOR);  
        }
}


void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "血刀门")
        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本门弟子，还是请回吧！\n");
                return;
        }
        if ((int)ob->query("shen") > -100000)
        {
                command("say 你是不是向着侠义道，连杀人都不会！\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 100)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

        ob->set("title","血刀门第二代弟子");
}

string ask_me()
{
    object me=this_player(),dao;

    if(me->query("family/family_name")!="血刀门")
    {
     this_object()->kill_ob(me);
     return "那里来的狗贼，胆敢觊觎本门的宝物，受死吧！！\n";
    } else
    if(!me->query("family/master_id")
      || me->query("family/master_id")!="xuedao laozu")  
    return "你武功如此低微，给你我可不放心哪。\n";
    if(!objectp(dao=present("xue dao",this_object())))
    return "你来晚了，血刀已经不在我身上了。\n";  
    dao->move(me);
    return "好吧，本门的血刀就暂时交给你掌管了！\n";
}

