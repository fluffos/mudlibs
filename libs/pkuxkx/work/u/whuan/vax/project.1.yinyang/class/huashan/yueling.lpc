// yueling.c 岳灵珊
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_linghu();
int ask_siguo();
void do_answer(string);

void create()
{
        set_name("岳灵珊",({"yue lingshan","lingshan","yue"}));
	set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
        set("long",
                "华山派掌门岳不群的爱女。\n"
                "她看起来十多岁，容貌秀丽，虽不是绝代美人，也别有一番可人之处。\
n");
        set("gender", "女性");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 22);
        set("con", 26);
        set("dex", 26);

        set("max_qi",  500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 10000);
        set("score", 5000);

        set_skill("force", 60);
        set_skill("huashan-xinfa", 40);
	set_skill("strike", 50);
	set_skill("hunyuan-zhang", 50);
        set_skill("dodge", 60);
        set_skill("huashan-shenfa", 60);
//      set_skill("tianpo-quan", 70);
        set_skill("parry", 55);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 45);
//      set_skill("taoism", 80);

        map_skill("force", "huashan-neigong");
	map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan_shenfa");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

	prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派" , 19, "弟子");
        set("inquiry", ([
                "岳不群" : "岳灵珊说：他老人家是我的父亲。\n",
                "宁中则" : "岳灵珊说：她老人家是我的母亲。\n",
                "令狐冲" : (: ask_linghu :),
                "思过崖" : (: ask_siguo :),
        ]) );



        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}
void init()
{
	add_action("do_answer","answer");
}

int ask_linghu()
{ mapping myfam;
        if (!(myfam = this_player()->query("family"))
            || myfam["family_name"] != "华山派")
   {
      say("岳灵珊说：他是我的大师兄，你问他干什么？\n");
      return 1;
   }
  else
   {
if ((int)this_player()->query("score") < 100)
        {
          command("say 你刚入本门，问那么多干什么?");
        return 1;
        }
      say("岳灵珊说：他是我的大师兄，现在正在思过崖思过。\n");
      this_player()->set_temp("marks/令1", 1);
    return 1;
   }
}

int ask_siguo()
{
  if ((int)this_player()->query_temp("marks/令1")) {
     say("岳灵珊说：思过崖在华山后山。从练武场往西北的小路可以通向思过崖。\n");
     this_player()->set_temp("marks/思1", 1);
     return 1;
  }
  else {
     say("岳灵珊说：思过崖是华山重地，你怎么知道的？\n");
     return 1;
  }
}
void attempt_apprentice(object ob)
{
        if((string)ob->query("gender")=="女性")
          {
		if ((string)ob->query("family/family_name") == "灵鹫宫" 
			&& ob->query("lingjiu/xiulian"))
		{
        		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
			
		}
		else
		{
        		command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
	        	command("recruit "+ob->query("id"));
		}
           }
        else {
          command("say 我不收男弟子。"+RANK_D->query_respect(ob)+"你还是去拜我师兄吧！\n");
            }
return;
}

void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
	}
return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	        if (this_player()->query("age")<20)
        	{
                	ob->set("title",GRN "华山派" NOR + YEL +"女剑童" NOR);
			return;
                }
        	else 
		{
        	        ob->set("title",GRN "华山派" NOR + YEL +"女剑士" NOR);
			return;
        	}

}

void re_rank(object student)
{
	        if (this_player()->query("age")<20)
        	{
                	student->set("title",GRN "华山派" NOR + YEL +"女剑童" NOR);
			return;
                }
        	else 
		{
        	        student->set("title",GRN "华山派" NOR + YEL +"女剑士" NOR);
			return;
        	}
}
