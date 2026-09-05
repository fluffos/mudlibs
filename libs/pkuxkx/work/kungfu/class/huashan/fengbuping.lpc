// fengbuping.c -封不平
#include <ansi.h>
inherit NPC;
#include <title.h>
inherit F_MASTER;
int ask_xueyi();
int ask_join();
int ask_join2();
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
        set_skill("huashan-neigong", 140);
        set_skill("dodge", 150);
        set_skill("huashan-shenfa", 150);
        set_skill("parry", 150);
        set_skill("sword", 160);
        set_skill("huashan-jianfa", 160);
        set_skill("kuangfeng-kuaijian", 200);
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
        "加入剑宗" : (: ask_join :),
        "剑宗绝学" : (: ask_join2 :),
        ]) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
  if ((string)ob->query("family/family_name")!="华山派")
  {
    command("say 你非我派弟子，我不能收你。");
    return ;
  }
  if (!ob->query("huashan_newskills/jianzong"))
  {
    command("say 我只会传授剑宗弟子武功。");
    return;
  }
  command("say 好吧，小兄弟！我今天收下你了！\n");
  command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
  {
    ob->set("title",GRN "华山派" NOR + RED +"剑宗弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
    ob->set_title(TITLE_RANK, ob->query("title"));
  }
}
int ask_join2()
{
  object me=this_player();
  if (me->query("chushi/last_family")!="华山派")
  {
    command("? "+me->query("id"));
    return 1;
  }
  if (me->query("huashan_newskills/jianzong"))
  {
    command("say 做人不能忘本啊。");
    return 1;
  }
  me->set("huashan_newskills/jianzong",1);
  command("nod "+me->query("id"));
  return 1;
}
int ask_join()
{
  object me=this_player();
  mapping myfam;
  if (!(myfam = me->query("family"))|| myfam["family_name"] != "华山派")
  {
    command("say 你非本派弟子，此话谈何说起？");
    return 1;
  }

  if ( me->query("betrayer") )
  {
		message_vision("$N想起$n以前的经历，对$n不太信任，拒绝了$n加入剑宗的要求。",this_object(), me);
		return 1;
  }
  
  if ( me->query("chushi/done") )
  {
	  {if (!me->query("safari_skill/hs_jq"))
		  {
			message_vision("$N想起$n以前的经历，对$n不太信任，拒绝了$n加入剑宗的要求。",this_object(), me);
			return 1;
		  }
		else
		  {
			message_vision("$N叹道：$n也算是为本派做了巨大贡献，答应了$n加入剑宗的要求。",this_object(), me);
		  }
	  }
  }
  
  if (me->query("huashan_newskills/jianzong"))
  {
    command("say 你已经是我剑宗传人了。");
    return 1;
  }
  
  if ( me->query_skill_mapped("force") )
  {
    command("say 加入剑宗这么严肃的事情请不要激发内功。");
    return 1;
  }
  
  if (!me->query("huashan_newskills/trial"))//第一次可以直接转，之后需要24小时转换。
  {
    command("ok");
    command("say 既然你有心，我就把你收入华山剑宗吧。");
    me->set("huashan_newskills/trial",1);
    me->delete("huashan_newskills/qizong");
    me->set("huashan_newskills/jianzong",1);
    tell_object(me,HIR+"恭喜你，加入了华山剑宗。\n"+NOR);
    return 1;
  }
  if (!me->query("huashan_newskills/attempt_jianzong"))
  {
    command("consider");
    command("say 过一天后再来吧。");
    me->set("huashan_newskills/attempt_jianzong",time());
    return 1;
  }
  if (time()-me->query("huashan_newskills/attempt_jianzong")<86400)
  {
    command("say 还没满一天呢。");
    return 1;
  }
  else
  {
    command("say 既然你有心，我就把你收入华山剑宗吧。");
    me->delete("huashan_newskills/qizong");
    me->set("huashan_newskills/jianzong",1);
    tell_object(me,HIR+"恭喜你，加入了华山剑宗。\n"+NOR);
    me->delete("huashan_newskills/attempt_jianzong");
    return 1;
  }
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
    {        command("say 好，既然你给了我紫霞秘籍，我就教你一招「天外飞龙」。");
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
    {  command("say 我可没法报答你呀");
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

