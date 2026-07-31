//Cracked by Kafei
// /kungfu/class/quanzhen/zjou.c
// hao.c 老顽童 周伯通
// Qianj 10/2001

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_me();

int auto_perform();

void create()
{
        set_name("周伯通", ({ "zhou botong", "zhou" }));
        set("title", HIW"老顽童"NOR);
        set("long",
                "一个嘻皮笑脸的老人，整天游手好闲。\n"
                "他眉毛胡子一把抓，笑容可拘。\n"
                );
        set("gender", "男性");
        set("age", 95);
        set("attitude", "heroic");
        set("shen_type", 1);
        set("str", 30);
        set("int", 10);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 25000);
        set("eff_jing", 15000);
        set("max_jing", 15000);
        set("jing", 15000);
        set("max_jingli", 15000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 300);
        set("combat_exp", 6400000);
        set("score", 500000);

        set_skill("force", 400);
        set_skill("xiantian-gong", 400);
        set_skill("dodge", 400);
        set_skill("jinyangong", 400);
        set_skill("cuff", 400);
        set_skill("chunyang-quan", 400);
        set_skill("kongming-quan", 400);
        set_skill("zuoyou-hubo", 400);
        set_skill("strike", 400);
        set_skill("sanhua-juding", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("quanzhen-jian", 400);
        set_skill("literate", 100);
        set_skill("taoism", 300);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyangong");
        map_skill("cuff", "kongming-quan");
        map_skill("strike", "sanhua-juding");
        map_skill("parry", "kongming-quan");
        map_skill("sword", "quanzhen-jian");

        prepare_skill("strike", "sanhua-juding");
        prepare_skill("cuff", "kongming-quan");

        create_family("全真教", 1, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );


        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        string name,new_name;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "全真教" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "并非我门中人，习武还是先从各位道长起吧！");
                return;
        }

        if ((int)ob->query_skill("xiantian-gong", 1) < 200) {
                command("say 老哥我不收徒。");
                return;
        } 
        if (ob->query_int() > 30) {
                command("say 小娃娃这么聪明，老哥我以后不是要吃亏吗？这个。。。。。。。");
                return;
        }

        command("say 好吧，你这小娃好玩的很，哥我就收下你了。");
        name = ob->query("name");
        new_name = name[0..01]+"处" + name[4..5];
        command("say 从今以后你就叫做" + new_name + "。");
        ob->set("name",new_name);
        command("recruit " + ob->query("id"));
}


#include "auto_perform.h"

