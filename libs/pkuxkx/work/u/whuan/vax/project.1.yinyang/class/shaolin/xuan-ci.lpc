// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();
int ask_damo();


void create()
{
    set_name("玄慈大师", ({
                "xuanci dashi",
                "xuanci",
                "dashi",
                }));
    set("long",
            "他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
            "他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
       );


    set("nickname", "少林寺方丈");
    set("gender", "男性");
    set("attitude", "friendly");
    set("class", "bonze");

    set("age", 70);
    set("shen_type", 1);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("max_qi", 2000);
    set("max_jing", 1000);
    set("neili", 2500);
    set("max_neili", 2500);
    set("jiali", 150);
    set("combat_exp", 1000000);
    set("score", 100000);

    set_skill("force", 150);
    set_skill("hunyuan-yiqi", 150);
        set_skill("tongzi-gong", 150);
    set_skill("dodge", 150);
    set_skill("shaolin-shenfa", 150);
    set_skill("finger", 150);
    set_skill("strike", 150);
    set_skill("hand", 150);
    set_skill("claw", 150);
    set_skill("parry", 150);
    set_skill("nianhua-zhi", 150);
    set_skill("sanhua-zhang", 150);
    set_skill("fengyun-shou", 150);
    set_skill("longzhua-gong", 150);
    set_skill("buddhism", 150);
    set_skill("literate", 150);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("finger", "nianhua-zhi");
    map_skill("strike", "sanhua-zhang");
    map_skill("hand", "fengyun-shou");
    map_skill("claw", "longzhua-gong");
    map_skill("parry", "nianhua-zhi");

    prepare_skill("finger", "nianhua-zhi");
    prepare_skill("strike", "sanhua-zhang");
    set("inquiry", ([
                "达摩老祖" : (: ask_damo :),
                "达摩心经" : (: ask_me :),
                ]));

    create_family("少林派", 36, "弟子");

    set("book_count" , 1);
    setup();

    carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
int ask_damo()
{ mapping myfam;
    if (!(myfam = this_player()->query("family"))
            || myfam["family_name"] != "少林派")
    {
        say("达摩老祖是我少林祖师,施主非我佛门弟子，还是请会吧. \n");
        return 1;
    }
    else {
        say("老祖在达摩洞后修行，有事你可到那去找他. \n");
        this_player()->set_temp("marks/达",1);
        return 1;
    }
}
string ask_me()
{
    mapping fam;
    object ob;
    if (!(fam = this_player()->query("family")) || fam["family_name"]!="少林派")
        return RANK_D->query_respect(this_player())+"与本派素无来往，不知此话从何说起?";
    if ( this_player()->query("score") < 200 )
        return "你对本派贡献太小，宝经交给你我可不放心啊。";
    if (this_player()->query("generation") > 37)
        return RANK_D->query_respect(this_player())+"你的地位不够，宝经不能交付你保管";
    if(query("book_count")<1)
        return "你来晚了，宝经已经被人要走了";
    add("book_count",-1);
    ob=new("d/shaolin/obj/damoxinjing");
    ob->move(this_player());
    return"好吧，宝经就交给你保管了";
}

void attempt_apprentice(object ob)
{
    object me; 
    mapping ob_fam, my_fam;
    string name, new_name;

    me = this_object();
    my_fam  = me->query("family");

    name = ob->query("name");

    if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
    {
        command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
        return;
    }

    if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
    {
        command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
        return;
    }

    if ( ob_fam["generation"] <= my_fam["generation"] )
    {
        command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
        return;
    }

    if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..0] == "澄")
    {
        command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
        command("recruit " + ob->query("id"));
    }
    else
    {
        command("say " + RANK_D->query_respect(ob) + "，你辈份不合，不能越级拜师。");
        return;
    }

    return;
}




#include "/kungfu/class/shaolin/xuan1.h"

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("title",HIR "少林" NOR + CYN "达摩院" NOR + RED "弟子" NOR);
    return;
}

void re_rank(object student)
{
    student->set("title",HIR "少林" NOR + CYN "达摩院" NOR + RED "弟子" NOR);
    return;
}

