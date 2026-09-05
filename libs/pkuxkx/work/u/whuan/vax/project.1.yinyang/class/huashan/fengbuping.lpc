// fengbuping.c -封不平
#include <ansi.h>
inherit NPC;
int ask_xueyi();

void create()
{
        set_name("封不平",({"feng buping","buping","feng"}));
        set("long",
                "华山派剑宗传人。\n"
                "他是华山剑宗的第一高手。剑气之争剑宗一败涂地，封不平隐居苦练，。\n");
	set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "传人" NOR);
        set("gender", "男性");
        set("age", 40);
	set("feilong", 1);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 28);
        set("con", 26);
        set("dex", 26);

        set("max_qi",  2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 10000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feilong" :),
        }) );

        set_skill("force", 130);
        set_skill("huashan-neigong", 150);
        set_skill("huashan-xinfa", 150);
        set_skill("dodge", 150);
        set_skill("huashan-shenfa", 150);
        set_skill("parry", 150);
        set_skill("sword", 160);
        set_skill("huashan-jianfa", 160);
        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派" , 18, "弟子");
        set("inquiry", ([
                "学艺" : (: ask_xueyi :),
        ]) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
int ask_xueyi()
{ 
	mapping myfam;
        if (!(myfam = this_player()->query("family"))
            	|| myfam["family_name"] != "华山派")
   	{
   		say("封不平说：你非本派弟子，此话谈何说起？\n");
             	return 1;
   	}
  	else
  	{
  		say("封不平说：我现在已不收徒，但你若能给我紫霞秘籍，我可以教你一招。\n");
  	    	this_player()->set_temp("marks/学封", 1);
  	  	return 1;
  	}
}
int accept_object(object ob, object obj)
{
        object me = this_player();
	mapping myfam;

        if(obj->query("id") == "zixia miji") 
        {
        	if (!(myfam = this_player()->query("family")) || myfam["family_name"] == "华山派" )
		{      	command("say 好，既然你给了我紫霞秘籍，我就教你一招「天外飞龙」。");
			if (me->query_skill("huashan-jianfa", 1) >=100)
			{
				say("你听了封不平的讲解，学会了这一招。\n");
				me->set("feilong",1);
                		return 1;
			}
			else
			{
				say("由于你的华山剑法等级不够，对封不平的讲解没有听懂。\n");
				return 1;
			}
		}
		else 
		{	command("say 我可没法报答你呀");
                	return 1;
        	}
	}
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

