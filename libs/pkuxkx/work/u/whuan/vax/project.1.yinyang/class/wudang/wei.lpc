// weiyixiao.co.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("韦一笑", ({ "wei yixiao", "wei" }));
        set("nickname", HIC"青翼蝠王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－青翼幅王韦一笑。身着一件青衫。他脸色泛青，\n"
                   "可能是修习寒冰绵掌之故。他的轻功独步天下，凭此一技在江湖上闯出了 \n"
                   "青翼幅王的名声。\n");
         set("gender", "男性");
        set("age", 40);
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
        set("jiali", 30);
        set("combat_exp", 600000);
        set_skill("force", 110);
        set_skill("jiuyang-shengong", 100);
        set_skill("dodge", 200);
        set_skill("parry", 120);
        set_skill("hanbing-zhang",100);
        set_skill("datengnuo-bufa", 200);
        set_skill("strike", 110);
        set_skill("literate", 100);
        set_skill("shenghuo-shengong", 50);
        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        prepare_skill("strike","hanbing-zhang");
        create_family("明教", 20, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/qingshan")->wear();
}
init()
{
        object ob;
        mapping myfam;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "明教") &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}
void do_killing(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 我不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say 你的九阳神功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
       if ((int)ob->query("shen") >-10000)  
        {
                command("say 我韦一笑最看不过眼满肚子伪善道德的人。");
                command("say " + RANK_D->query_respect(ob) + "若能杀他" +
                        "几个伪君子，我一定收你。");
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
