// NPC yupopo.c

#include <ansi.h>
#include <title.h>
inherit NPC;

inherit F_MASTER;
void create()
{
	set_name("符敏仪", ({ "fu minyi", "fu", "minyi" }));
	set("long",
	    "她是「灵鹫宫」九天九部中阳天部的首领.\n");
	set("nickname", RED "针神" NOR );
	set("title", "阳天部首领");
	set("gender", "女性");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1400);
	set("max_jing", 1400);
	set("neili", 950);
	set("max_neili", 950);
	set("jiali", 50);

	set("combat_exp", 300000);
	set("score", 1000);
	set_skill("force", 130);
//	set_skill("unarmed", 100);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("hand",130);
	set_skill("strike", 130);
        set_skill("sword",150);

        set_skill("changhen-jian",140);
	set_skill("zhemei-shou",130);
	set_skill("liuyang-zhang",130);
	set_skill("yueying-wubu",160);
	set_skill("bahuang-gong", 150);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
//	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "changhen-jian");
	create_family("灵鹫宫",3,"首领");
	setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}

void attempt_apprentice(object ob)
{
   	if ((string)ob->query("gender")!="女性")
           {
 		command("say 你找死啊!");
		return;
	   }
	if (ob->query("betrayer")>1)
	{
	   command("say 本宫最忌欺师灭祖之事，你多次判师，我怎么还能收你？");
	   return;	}

	if (ob->query("family/family_name") != "灵鹫宫")
	{
	   
		command("say 我们灵鹫宫拜师要从副首领拜起，" + RANK_D->query_respect(ob) + "先去拜副首领吧！\n");
	   return;
	}

        if  ((int)ob->query("family/generation") <4 && ob->query("family/family_name") == "灵鹫宫")
	{
	   command("say 您开什么玩笑？我这点玩意哪能叫您呀？");
	   return;	}

         if ((int)ob->query("score") < 500) 
           {
                command("say " + RANK_D->query_respect(ob) + "对本门贡献不够，我还不能收你。\n");
		return;
	   }
	if ((int)ob->query_skill("bahuang-gong", 1) < 60) 
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	   }
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
	command("recruit " + ob->query("id"));
	return;
}



void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
	        ob->set("title",MAG "灵鹫宫" NOR + HIG +"副首领" NOR); 
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
        return;
}
