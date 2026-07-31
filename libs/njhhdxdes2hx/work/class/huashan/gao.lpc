// gao.c

inherit F_MASTER;
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("高根明", ({ "gao genming", "gao", "genming" }));
        set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
        set("long",
"高根明身材高大，长得很胖，但别看他其貌不扬，他在\n"
"同门中排行第五，是华山派年轻一代中的好手。\n");
        set("gender", "男性");
        set("age", 27);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_kee", 800);
        set("max_gin", 600);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 5000);

        set_skill("force", 40);
        set_skill("huashan-neigong", 40);
        set_skill("dodge", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 60);
        set_skill("huashan-shenfa", 50);
        set_skill("strike", 60);
        set_skill("hunyuan-zhang", 60);

        map_skill("force", "huashan-neigong");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("dodge", "huashan-shenfa");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派", 19, "弟子");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}
void attempt_apprentice(object ob)
{
        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
        else if ((string)ob->query("gender")=="无性" && ob->query_skill("pixie-jian")>=50)
        {
                command("say 我看你向东厂派来的奸细。");
                return;
        }
        if((string)ob->query("gender")!="男性")
          {
           command("say 我不收女弟子。"+RANK_D->query_respect(ob)+"，你还是拜我的师妹吧！");
           return;
          }
        if((string)ob->query("gender")=="男性")
          {
           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));

           }
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<=-100 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "gao genming"))
        {
                command("say 你多次杀害好人，还屡教不改，我岂能仍是你的师傅。\n");
		ob->set("bad", 0);
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("age")<20)
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"剑童" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"剑士" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("age")<20)
                {
                        student->set("title",GRN "华山派" NOR + YEL +"剑童" NOR)
;
                        return;
                }
                else
                {
                        student->set("title",GRN "华山派" NOR + YEL +"剑士" NOR)
;
                        return;
                }
}
