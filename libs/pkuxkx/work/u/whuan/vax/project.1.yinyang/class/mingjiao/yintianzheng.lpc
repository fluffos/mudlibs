// yin tianzheng.co.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("殷天正", ({ "yin tianzheng", "yin" }));
        set("nickname", HIW"白眉鹰王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－白眉鹰王。身着一件白衫，他白须白眉，
\n"
                   "威风凛凛。四大法王中数他年纪最大。他在鹰爪功上浸淫了几十年
\n"
                   "工夫，在明教中算得上一等好手。\n");
         set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 500000);
        set_skill("force", 110);
        set_skill("shenghuo-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set_skill("myingzhua-gong",120);
        set_skill("datengnuo-bufa", 100);
        set_skill("claw", 110);
        set_skill("literate", 100);
        set_skill("shenghuo-shengong", 50);
        map_skill("claw","myingzhua-gong");
        map_skill("force", "shenghuo-xinfa");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        prepare_skill("claw","myingzhua-gong");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
}void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 我不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query("score")<500){
             command("sigh");
             command("say 你对本门不忠,这怎么能让本王相信你呢?");
             return;
            }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say 你的九阳神功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=10)
        {
   command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
     command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                      ob->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
}
void re_rank(object student)
{
                        student->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
}
