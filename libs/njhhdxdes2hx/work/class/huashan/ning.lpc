// ning.c 宁中则
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("宁中则",({"ning zhongze","ning"}));
        set("nickname", MAG "紫衫女侠" NOR);
        set("title",GRN "华山派" NOR + YEL "第十八代" NOR+ GRN "掌门夫人" NOR);
        set("long",
                "华山派掌门岳不群的夫人。 \n"
               "她今年将近四十, 人称紫衫女侠.\n");
        set("gender", "女性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 28);
        set("con", 26);
        set("dex", 30);
	set("per", 25);
        set("max_kee", 1000);
        set("max_gin", 800);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
        set("combat_exp", 900000);
        set("score", 40000);
        set_skill("force", 140);
        set_skill("huashan-neigong", 140);
        set_skill("dodge", 120);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("purple", 80);
        set_skill("literate", 100);
        set_skill("strike", 60);
        set_skill("hunyuan-zhang", 60);
	set_skill("cuff", 80);
		set_skill("poyu-quan", 100);

        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "poyu-quan");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

        create_family("华山派",18,"弟子");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/zishan")->wear();
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
        if((string)ob->query("gender")=="女性")
          {
               if ((int)ob->query("max_force") <200) {
                       command("say 我华山派原有剑宗、气宗之争。最终气宗为首。");
                       command("say " + RANK_D->query_respect(ob) +"是否还应该多练练内力？");
                       return;
               }
               if ((int)ob->query("shen") < 1000) {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
                       return;
               }
          command("say 好吧，" + RANK_D->query_respect(ob) +"，我就收下你了！");
          command("recruit "+ob->query("id"));
        

           }
        else {
          command("say 我不收男弟子，" + RANK_D->query_respect(ob) +"怎么能拿我开玩笑呢？你还是去拜我师兄吧！\n");
            };
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<500 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "ning zhongze"))
        {
                command("say 你多次杀害好人，还屡教不改，我岂能仍是你的师傅。\n");
		ob->set("bad", 0);
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("shen")<10000)
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"女剑客" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("shen")<10000)
                {
                        student->set("title",GRN "华山派" NOR + YEL +"女剑客" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
                        return;
                }
}
