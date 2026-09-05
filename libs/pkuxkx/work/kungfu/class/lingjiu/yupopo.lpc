// NPC yupopo.c

#include <ansi.h>
#include <title.h>
inherit NPC;

inherit F_BQUESTMASTER;

string ask_me();
void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "她是「灵鹫宫」九天九部中昊天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", "昊天部首领");
	set("gender", "女性");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 500000);
	set("score", 10000);
	set_skill("force", 150);
        set_skill("literate", 120);
//	set_skill("unarmed", 100);
	set_skill("dodge", 160);
	set_skill("parry", 150);
	set_skill("hand",140);
	set_skill("strike", 140);
        set_skill("sword",150);

        set_skill("changhen-jian",150);
	set_skill("zhemei-shou",140);
	set_skill("liuyang-zhang",160);
	set_skill("yueying-wubu",160);
	set_skill("bahuang-gong", 160);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "changhen-jian");
	create_family("灵鹫宫",3,"首领");


	setup();
//       carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);

}

void init()
{
	set("inquiry", ([
                "上山" : (: ask_me :),
        ]));

        add_action("give_wsquest", "quest");
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
	   command("say 您开什么玩笑？我这点玩意哪能教您呀？");
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


string ask_me()
{	 
        object me=this_player();
	if ((string)me->query("gender")=="女性")
{ me->move("/d/lingjiu/xianchou");
message_vision("余婆婆说道“好吧，我就带你过这个山涧吧。”\n",me);
return "我还得回去，真烦！";
}
message_vision("余婆婆说道“灵鹫宫里都是女性，"+RANK_D->query_respect(me)+",你还是请回吧”\n",me);
return "真烦呀";
}
