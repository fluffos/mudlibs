// ning.c 宁中则
#include <ansi.h>


inherit NPC;

inherit F_MASTER;

#include "/new_quest/qhuashan.h"
#include "/new_quest/quest.h"
void create()
{
        set_name("宁中则",({"ning zhongze","ning"}));
	set("nickname", MAG "紫衫女侠" NOR);
	set("title", YEL "华山派" NOR + GRN "第十八代" NOR + YEL "掌门夫人" NOR);
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
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);
        set("combat_exp", 2700000);
        set("score", 40000);
        set_skill("force", 240);
        set_skill("zixia-shengong", 320);
        set_skill("huashan-xinfa", 240);
	set_skill("cuff", 250);
	set_skill("poyu-quan", 250);
	set_skill("strike", 250);
	set_skill("hunyuan-zhang", 250);
        set_skill("dodge", 260);
        set_skill("huashan-shenfa", 260);
//      set_skill("tianpo-quan", 130);
        set_skill("parry", 240);
        set_skill("sword", 240);
        set_skill("huashan-jianfa", 240);
//      set_skill("taoism", 140);
        set_skill("literate", 250);

        map_skill("force", "huashan-xinfa");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff","poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
      ]));


        create_family("华山派",18,"弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/zishan")->wear();
}

void attempt_apprentice(object ob)
{
 if ((string)ob->query("family/family_name")!="华山派")
{
                command("say 你非我派弟子，我不能收你。");
                return ;
}

        if((string)ob->query("gender")=="女性")
          {
               if ((int)ob->query("max_neili") <200) {
                       command("say 我华山派原有剑宗、气宗之争。最终气宗为首。")
;
                       command("say " + RANK_D->query_respect(ob) +"是否还应该多
练练内力？");
                       return;
               }
               if ((int)ob->query("score") < 500)
                {
                 command("sigh "+ob->query("id"));
                 command("say 你对本门的贡献太低了，我怎么能信任你呢?");
                 return;
                }
               if ((int)ob->query("shen") < 1000) {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未
练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) +"
是否还做得不够？");
                       return;
               }
          command("say 好吧，" + RANK_D->query_respect(ob) +"，我就收下你了！");
          command("recruit "+ob->query("id"));

           }
        else {
          command("say 我不收男弟子，" + RANK_D->query_respect(ob) +"怎么能拿我开玩笑呢？ 你还是去拜我师兄吧！\n");
            };
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

