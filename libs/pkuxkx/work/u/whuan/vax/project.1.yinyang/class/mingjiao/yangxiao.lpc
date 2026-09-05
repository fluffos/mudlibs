// yangxiao.co.c
inherit NPC;
inherit F_MASTER;
void heal();
#include <ansi.h>
void create()
{
        set_name("杨逍", ({ "yang xiao", "yang" }));
        set("title",GRN "明教" NOR + YEL +"光明左使" NOR);
        set("long","明教光明左使。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
       set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 30);
        set("combat_exp", 800000);
        set("score", 5000);
        set_skill("force", 120);
        set_skill("jiuyang-shengong", 100);
        set_skill("dodge", 150);
        set_skill("parry", 120);
        set_skill("blade", 140);
        set_skill("datengnuo-bufa", 120);
        set_skill("hanbing-zhang", 150);
        set_skill("jinwu-dao", 150);
        set_skill("strike", 120);
        set_skill("literate", 110);
        set_skill("shenghuo-shengong", 50);
        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "shenghua-shengong");
        map_skill("blade", "jinwu-dao");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        prepare_skill("strike","hanbing-zhang");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/gangdao")->wield();
        carry_object("/d/mingjiao/obj/qingshan")->wear();
}
void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="明教" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }if ((int)ob->query("shen") < 5000) {
                command("say 我杨逍乃顶天立地的好汉，我的弟子应该扶危济困.");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本使一定收你。");
                return;
        }
        if ((int)ob->query("score")<500){
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本使一定收你");
            return;      
            }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
          command("say 你的九阳神功太低了，无法修习我的功夫。");
          command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=1)
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
                      ob->set("title",GRN "明教" NOR + YEL +"护法" NOR);
                        return;
}
void re_rank(object student)
{
                        student->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
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

