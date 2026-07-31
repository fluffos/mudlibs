//NPC /d/henshan/npc/tian.c
#include <ansi.h>
inherit NPC;
string ask_me();
string ask_live();
string ask_tast();
string ask_job();
string ask_kill();
string ask_jiebai();
object me = this_player();

void greeting(object ob);
int accept_fight(object ob);
#include "/quest/givegift.c"
void create()
{
	seteuid(getuid());
	set_name("田伯光", ({ "tian boguang", "tian" }));
        set("title","采花淫贼");
        set("nickname",HIY"千里采花我独行"NOR);
        set("long", 
                "他就是江湖第一淫贼。\n"
                "一个身材中等的壮年男子，眉梢眼角处处留出淫亵之意，不时朝你瞟过几眼。\n");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);

        set("per", 23);
	set("str", 85);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

set("pubmaster",1);
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 3800);
	set("max_jing", 3800);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 10);

	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("blade", 100);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("lingxu-bu", 150);
	set_skill("touch", 300);
	set_skill("kuangfeng-blade", 200);
         set("inquiry", 
               ([      "不戒" : (: ask_kill :),
                       "解谗" : (: ask_tast :),
                       "job" :  (:ask_tast:),
                       "任务" : (: ask_job :),
                       "help" : (: ask_job :),
                       "帮助" : (:ask_job :),
                       "采花" : (:ask_tast:),
                       "秘技" : (:ask_me :),
                       "丽春院" : "那可是扬州城里的好去处，就他妈的没少花老子的钱" ,
                       "fuck" : "这等出娘胎便会的事，亏你还来问我？" ,
                       "令狐冲" : "冲弟和盈盈正仙居一处，甚是快活。"  ,
                       "仪琳" : "你可千万别再提她，她老子可真的要了我的命，真是个丧门星啊。" ,
                       "结拜" : (:ask_jiebai :),
                       "girl" : (:ask_live :),
                       "woman" : (:ask_live :),
                       "jiebai" : (:ask_jiebai :),
               ]));

	map_skill("cuff", "touch");
	map_skill("unarmed", "touch");
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

        set("chat_msg_combat", ({
                (: perform_action, "blade.kuang" :),
        }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"田伯光笑道：尼姑也没关系嘛，蓄起头发，两个月就是小美人了。\n",
                "田伯光叹道：“自从惹了不戒那秃驴，日子真是难过，东躲西藏，不知何日可以再。\n",
                "田伯光仰首望望天，：“谁能帮我找个妞就好了。\n",
                 "田伯光垂头丧气地说：“也不知道丽春院近来又有了什么新货色。\n",
                 "田伯光忽然精神一振：“前几天路过山下小村，那个叫翠翠的长的可真他妈的不赖。\n",
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();
     add_action("do_want", "要");
     add_action("do_want", "yao");
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="女性")
	{
if (ob->query("age")<26) say("田伯光笑道：妙极，妙极，又来了一个小姑娘。\n");     
else say("田伯光笑道：妙极，妙极，可惜太老了点，我可没胃口。\n");     
	}
	else say("田伯光笑着招招手：这位"+RANK_D->query_respect(ob) + "来喝两杯，这个小尼姑嘛，反正也没什么事，就让她坐着就是。\n");
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性")
	{
		write("田伯光笑道：花姑娘？杀了太可惜了的。\n");
		return 0;
        }
	return 1;
}
 
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeg"))      
		who->set_temp("learn_timeg", 0);

    if (environment(who)->query("short")!="回雁楼")
         {
           command ("say 这是什么地方啊,好像不是回雁楼啊!");
           return 0;
          }

        if (userp(ob))
         {
           command ("say 玩家我可不敢要!");
           return 0;
          }

       if (ob->query("gender") == "女性"
       && ob->query("per") <= 22)
         {
           command ("say 这么难看的货色你自己玩吧!");
           return 0;
          }
       
       if (ob->query("gender") == "女性" && ob->query("age") <= 25)
      {
          if  (this_player()->query_temp("findgirl"))
         {
           this_player()->set_temp("findgirlok",1);
           command ("thumb" + this_player()->query("id"));
           message_vision("田伯光色迷迷地看着$N，不停的咽口水。\n",ob);
           message_vision("田伯光对着$N哈哈大笑,好好，我要好好谢你，说吧，你要什么。\n" , this_player());
           tell_object(this_player(), "请输入 要(yao)  money, exp, ... \n");
       call_out("destroying", 0,ob);
           return 1;
          }
      }

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("touch",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("touch",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("touch",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeg",i);

      message_vision("田伯光对$N说道：既然你和我是同道中人，我就教你二手吧。\n",who);


	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeg") <= 0) return 0;
else         
ob->add_temp("learn_timeg",-1);
return 1;
}
int do_want(string arg)
{
	int exp;
	       me = this_player();

        if (me->query_condition("menpai_busy"))
        {
                  tell_object(me,"我需要休息一会，你等会再来吧!\n");
                   return 0;
        }


        if ( !me->query_temp("findgirl"))
       { 
       command("kick " + me->query("id"));
       message_vision("田伯光朝$N勃然大怒：“你什么也没干，也敢来要奖励，给老子滚一边去。\n", me);
      return 1;
        }
        if ( !me->query_temp("findgirlok"))
       { 
       command("kick " + me->query("id"));
       message_vision("田伯光朝$N勃然大怒：“你什么也没干，也敢来要奖励，给老子滚一边去。\n", me);
      return 1;
        }

//       if (!me->query("tianjob") || stringp(me->query("tianjob")))       { 
//       command("kick " + me->query("id"));
//       message_vision("田伯光朝$N勃然大怒：“你什么也没干，也敢来要奖励，给老子滚一边去。\n", me);
//      return 1;
//        }

      if( !arg || arg==""  ) return 0;
      if( arg == "money" ) 
      {    message_vision("田伯光朝$N嘿嘿一乐：“想不到阁下是位财迷。\n", me);
           new("/clone/money/gold.c")->move(me);
           tell_object(me, "田伯光给你一些黄金。\n");
me->start_busy(3);
      }
      if ( arg == "exp" )
       {
           message_vision("田伯光朝$N点了点头:“江湖中人，武艺确实是我等看家之宝。\n", me);
       exp=50+random(100);
       exp=exp/2+18;
addnl(me,"exp",exp);
me->start_busy(3);
me->apply_condition("menpai_busy",4);
       }
       if ( arg ==  "all")
        {   command("faint " + me->query("id"));
            message_vision("田伯光惊讶地对$N看着:“想不到你是个如此贪得无厌的家伙。\n", me);
            command("slap " + me->query("id"));
        }    
           this_player()->delete_temp("findgirl");
           this_player()->delete_temp("findgirlok");
           this_player()->add("tianjob", 1);
if (me->query("tianjob") || !stringp(me->query("tianjob")))
  { 
           if (me->query("tianjob") >1 && me->query("tianjob") <= 5)
           me->set("title", "采花小贼");
           if (me->query("tianjob") >5 && me->query("tianjob") <= 20)
           me->set("title", "采花贼");
           if (me->query("tianjob") >20 && me->query("tianjob") <= 40)
           me->set("title", "采花淫贼");
           if (me->query("tianjob") > 40)
           me->set("title", "采花大盗");
}
           me->add("shen", -2000);
           message_vision("田伯光迫不及待地说：“好了，你我各得所需，现在我要先去享用了。\n" , me);
return 1;
          
        }   
string ask_me()
{
         return RANK_D->query_respect(this_player()) + 
                "想学点手段原也不难，可不知能否帮我解解谗先？";
}
string ask_live()
{            return "原来" + RANK_D->query_respect(this_player()) +
        "和我乃是同道中人呢。";
}
string ask_tast()
{       
             this_player()->set_temp("findgirl", 1);
            return  "这样吧，最近风声太紧，你帮我搞几个妞吧，我会好好谢你的。";
}
string ask_job()
{
//             command("chat* touch " + this_player()->query("id"));
              return "如果你能帮我杀了不戒那贼秃，我，我，你要什么我给什么。";
              this_player()->set_temp("killmonk", 1);
}
string ask_kill()
{               if (this_player()->query("jiebai1"))
                return "都是自家兄弟了，还开这等玩笑。";
                command ( "say 原来你是那老秃驴的同党，罢了，拿命来。");
                kill_ob(this_player());
                return "你死在我的闪电刀下，也算你的造化。";
 }
 string ask_jiebai()
{            
               if (!this_player()->query("tianjob") || stringp(this_player()->query("tianjob")))
              {
                  message_vision("田伯光朝$N白了一眼。\n", this_player());
                  return "你是谁啊?";
               }

                  if (this_player()->query("jiebai1"))
              {
                  message_vision("田伯光朝$N白了一眼。\n", this_player());
                  return "都是自家兄弟了，还开这等玩笑。";
               }
  
               if (this_player()->query("tianjob") <= 20)
       {         message_vision("田伯光朝$N轻蔑地一撇嘴。\n", this_player());
                 command("say 我田某人虽不才，可结交的也都是顶天立地的豪侠。"); 
                 return "你再努力干吧。";
        }
                if (this_player()->query("tianjob") <= 60)
            {    message_vision("田伯光朝$N惊讶地看了一眼。\n", this_player());
                message_vision("田伯光朝$N挤了挤眼睛。\n", this_player());
                return "既要做我兄弟，该再多为兄弟弄几个妞才行，看你够不够意思了。";
            }
                 if (this_player()->query_temp("bujie") < 1)
                {
                   command("say你为我做了确实不少事，只是这不戒不除，我委实不敢安心那。");
                   return "这样吧，你去帮我做掉不戒这老秃驴，我们怎么都是好兄弟，今后有福同享，如何？";
                 }
                 {
                     me->delete_temp("bujie");
                     command("say 好，好，我田某今天结识到你，真是天大的高兴。");
                     command("chat 从即日起，"+this_player()->name(1)+"就是我田某人的好兄弟，大家同福同难，共享天福。");
                     this_player()->set("jiebai1", 1);
                     return "从今后有什么难事，兄弟尽管吩咐，田某万死不辞。";
                   }
          }

void destroying(object ob)
{   
   if(!ob) return;
if (!userp(ob))
{
if(ob) destruct(ob);
}
}
