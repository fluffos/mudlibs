// dayou.c

#include <ansi.h>

inherit NPC;
inherit F_AQUESTMASTER;

void create()
{
        set_name("梁发", ({ "liang fa", "liang", "fa"}));
	set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
        set("long",
"梁发有身材高大，手中一把长剑，让人一看便知他是个剑客。他在\n"
"同门中排行第三，是华山派年轻一代中的好手。\n");
        set("gender", "男性");
        set("age", 26);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 27);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 20);
        set("combat_exp", 20000);
        
        set_skill("force", 80);
        set_skill("huashan-xinfa", 80);
	set_skill("cuff", 80);
	set_skill("poyu-quan", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("huashan-jianfa", 80);
        set_skill("huashan-shenfa", 80);

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
}
void init()
{
add_action("give_wsquest","quest");
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
           if ((int)ob->query("score") < 200)
              {
               command("say 你还是多为本门作点事吧");
               return;
              }
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
