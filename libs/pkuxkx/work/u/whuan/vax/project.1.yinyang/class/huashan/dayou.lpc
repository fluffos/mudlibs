// dayou.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陆大有", ({ "lu dayou", "lu", "dayou" }));
        set("nickname", "六猴儿");
	set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
	    set("start_room","/d/huashan/buwei1");
        set("long",
"陆大有身材很瘦，又长的尖嘴猴腮的，但别看他其貌不扬，他在\n"
"同门中排行第六，是华山派年轻一代中的好手。\n");
        set("gender", "男性");
        set("age", 26);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 20);
        set("combat_exp", 10000);
        set("score", 5000);

        set_skill("force", 40);
        set_skill("huashan-xinfa", 40);
	set_skill("cuff", 50);
	set_skill("poyu-quan", 50);
        set_skill("dodge", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 60);
        set_skill("huashan-shenfa", 50);

        map_skill("force", "huashan-xinfa");
	map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("dodge", "huashan-shenfa");

	prepare_skill("cuff", "poyu-quan");

        create_family("华山派", 19, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
	carry_object("/d/huashan/obj/book-zixia");
}
void attempt_apprentice(object ob)
{
        if((string)ob->query("gender")!="男性")
          {
           command("say 我不收女弟子。"+RANK_D->query_respect(ob)+"，你还是拜我?氖γ冒桑?);
           return;
          }
        if((string)ob->query("gender")=="男性")
          {
           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
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
                	student->set("title",GRN "华山派" NOR + YEL +"剑童" NOR);
			return;
                }
        	else 
		{
        	        student->set("title",GRN "华山派" NOR + YEL +"剑士" NOR);
			return;
        	}
}
