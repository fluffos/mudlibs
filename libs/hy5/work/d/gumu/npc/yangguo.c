// yangguo.c 杨过
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("杨过", ({ "yang guo", "yang" }));
	set("nickname", HIG "神雕大侠" NOR);
	set("gender", "男性");
	set("age", 30);
	set("per",30);
	set("con",30);
	set("str", 30);
	set("class","gumu");
	set("dex", 30);
	set("long", "他是一位高大的男子，相貌俊秀。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住他迷人的风采。你可以跟他切磋(qiecuo)\n");
	set("combat_exp", 10000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("anranxiaohun-zhang",350);
	set_skill("xuantie-sword", 350);
	set_skill("xiantian-qigong", 100);
	set_skill("yunv-shenfa",300);
	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.feihongrudian" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
	set("neili", 25000); 
	set("max_neili", 25000);
	set("max_jing", 25000);
	set("max_qi", 25000);
	set("qi",25000);
        set("inquiry", ([
                "小龙女" : "她就在小屋里。\n",
"拜师": "先让我试试你的武功，然后再决定收不收你。你想试试(accept test)？\n",
"切磋":"你可以跟我进行切磋(qiecuo)\n",
"运气之道" : (: ask_me :),
       ]) );
       
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
       
       create_family("古墓派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiesword")->wield();
	add_money("gold", 1);
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
	add_action("do_qiecuo","qiecuo");
	add_action("do_killing", "kill");
	add_action("do_killing", "touxi");
	add_action("do_killing", "hit");
	add_action("do_killing", "ansuan");
}

void attempt_apprentice(object ob)
{ 
  if(!ob->query("marks/beguo"))
	  return;
else {
 command("recruit " + ob->query("id") );
ob->set("title",HIW"杨过嫡传弟子"NOR);
}
 return;
}
int recognize_apprentice(object ob)
{
  if(!ob->query("marks/win_guo_time"))
	  return 0;
  if((time() - ob->query("marks/win_guo_time") ) > 900)
  {
    say("杨过说道：你从我这学了不少了，我们来再砌磋(qiecuo)一下吧！\n");
    return 0;
  }
 return 1;
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=target->query("qi");
	
	if((time()-me->query("marks/win_guo_time"))<900)
	{
     command("say 你的功夫真不错，不用再切磋啦！\n");
	 return 1;
	}
	//if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
	if(time() - me->query("marks/qiecuo_last_time")>72000)
	{
     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
	 say("\n杨过道：一招．．．．\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n杨过道：二招．．．．\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n杨过道：三招．．．．\n");
	 dkee=target->query("qi");
     if(!(dkee<skee)) 
	 {
      say("杨过说道：看来你武功不行，等你练好些再来吧！\n");
	  me->set("marks/qiecuo_last_time",time());
     }
	 else
	 {
            
      say("\n杨过说道：你的功夫真不错，从今以后我们就相互学习吧！\n");
	  me->set("marks/win_guo_time",time());
	 }
	 return 1;
	}
    say("杨过说道：你不久前才输给我！过两天再比吧！\n");
    return 1;
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
	if((string)this_player()->query("family/family_name") != "古墓派") 
		{
			command("say 你先去拜我姑姑吧。\n");
			return 1;
		}
	else if(this_player()->query("shen")>50000)
		{
			command("say 我杨过向来不跟你们这些所谓的正派人物打交道。\n");		return 1;}
	else if(this_player()->query("shen")<-50000)
		{
			command("say 我杨过向来最痛恨你们这些邪派人物，快给我滚！\n");		return 1;}
	else if(this_player()->query("str")<28)
		{
			command("say 你臂力太差，学不会我的武功。\n");
		return 1;}
	else if(this_player()->query("combat_exp")<1000000)
		{
			command("say 你当我是谁，连你也想学我武功？。\n");
		return 1;}

	else if(this_player()->query("family/master_id") == this_object()->query("id"))
	{
	say("\n杨过拍拍你的头道：你将来必定是一个可造之才了！\n");
	return 1;
	}
	
                say("\n杨过点了点头，说道：很好，我试你三招，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("杨过叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                 this_player()->die();
	       return 1;
		}
                say("\n杨过说道：不错，这是第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("杨过「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
                this_player()->die();     
	   return 1;
                }
                say("\n杨过说道：第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("杨过叹道：可惜，至今竟无有缘人....\n");
                       this_player()->die();
 return 1;
                }
                
say("\n杨过哈哈大笑，说道：今日终於觅得一个可造之才！\n\n");
                this_player()->set("marks/beguo",1);
	return 1;
        }
        return 0;
}
int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "小龙女")
		{
		message_vision("$N冷笑一声道：敢杀我姑姑，我看你活得太长了。\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}


string ask_me()
{ 
       mapping fam; 
       object ob;
       ob = this_player();
//       if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
//               return RANK_D->query_respect(this_player()) + 
//               "非我古墓传人,不知道此话怎讲?";
            if (!ob->query_temp("xth_hm"))
            return RANK_D->query_respect(this_player()) + 
               "想知道什麽运气之道呢?";
                      ob->delete_temp("xth_hm");
               ob->set_temp("make/xtj_look1",1);
            ob->set_temp("yg_pbask",1);
       return "屏气具息,凝气守中,双肩放松,意守丹田,这是在洪水中运气的诀窍,你好好去领悟一下.";
}