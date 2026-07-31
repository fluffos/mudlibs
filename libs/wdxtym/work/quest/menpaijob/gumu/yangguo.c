// yangguo.c 杨过
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
void create()
{
	set_name("杨过", ({ "yang guo", "yang" }));
	set("nickname", HIG "神雕大侠" NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",80);
	set("con",80);
	set("str", 80);
	set("class","gumu");
	set("dex", 80);
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
	set_skill("yunv-xinfa", 320);
	set_skill("anranxiaohun-zhang",380);
	set_skill("xuantie-sword", 390);
	set_skill("xiantian-qigong", 200);
	set_skill("yunv-shenfa",300);
        set_skill("yunv-jian", 320);  
        set_skill("tianluo-diwang", 320); 
                set_skill("meinv-quan", 320); 
                        set_skill("wuzhan-mei", 320); 
                                set_skill("yinsuo-jinling", 320);         




	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	map_skill("force", "yunv-xinfa");

	set("chat_chance_combat", 99);
       set("chat_msg_combat", ({
                (: perform_action, "parry.anran" :),
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "parry.jingtao" :),
                (: perform_action, "parry.sad" :),
                          (: perform_action, "tuo" :),


                (: exert_function, "recover" :),
                (: perform_action, "sword.feihongrudian" :),
                 (: perform_action, "sword.botao" :),
                (: perform_action, "sword.lei" :),
                (: perform_action, "sword.juan" :),
                (: perform_action, "sword.dong" :),
                (: perform_action, "sword.dang" :),
                (: perform_action, "sword.hai" :),					
                (: perform_action, "sword.qianjun" :),		            
        }) );

if (random(2)==0) 
	{
	map_skill("sword", "yunv-jian");

	set("chat_chance_combat", 99);
       set("chat_msg_combat", ({
                (: perform_action, "sword.hebi long" :),
            		(: command("perform sword.hebi long") :),
                (: perform_action, "parry.anran" :),
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "parry.jingtao" :),
                (: perform_action, "parry.sad" :),
                          (: perform_action, "tuo" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
        }) );
   }     
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
	set("neili", 55000); 
	set("max_neili", 55000);
	set("max_qi", 25000);
	set("qi",25000);
	set("max_jing", 25000);
	set("jing",25000);
        set("inquiry", ([
                "小龙女" : "她就在小屋里。\n",
"拜师": "先让我试试你的武功，然后再决定收不收你。你想试试(accept test)？\n",
"切磋":"你可以跟我进行切磋(qiecuo)\n",
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
       ]) );
       create_family("古墓派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("d/gumu/npc/obj/tiesword")->wield();
	add_money("gold", 2);
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
	add_action("do_killing", "qiangjian");
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
	if(!me)
	{
     command("say 人呢！\n");
	 return 1;
	}
	if(!me->query_temp("weapon"))
	{
     command("say 你的武器呢！\n");
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
	else if((string)this_player()->query("family/family_name") != "古墓派" && this_player()->query("str")<28)
		{
			command("say 你臂力太差，学不会我的武功。\n");
		return 1;}
	else if(this_player()->query("combat_exp")<1000000)
		{
			command("say 你当我是谁，连你也想学我武功？你的修为太低了!。\n");
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
		victim->kill_ob(player);
		return 1;
		}
	}
	return 0;		
}

int ask_job()
{

        object me = this_player();
        object guo = this_object();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }

        if (me->query_condition("gumu_job"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }
      if( (int)me->query_skill("yunv-xinfa",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }

        if( me->query("family/family_name") != "古墓派")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), me);
                     return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "保家卫国很难的，你还是练高修为再来吧");
                return 1;
}
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你连本钱都没有，我怎么放心要你去保家卫国？");
                return 1;
        }

        if (me->query("kill_gumu") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "能为国家出力，真是太好了。");
                command("say " + me->query("id") + " 一队蒙古兵在『" + quest["short"]             + "』出现，快去吧！\n" NOR);
                me->set("kill_gumu", 1);
	        me->apply_condition("gumu_job",15);
                me->set("quest/quest_type", "杀");
                me->set("quest/quest", "蒙古兵");
                me->set("task_time", time() + 300);
                ob = new(__DIR__"qiangdao",1);
                }
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
//}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_gumu") == 1) {
                command("sigh");
                command("say 你这身手也来保家卫国!!");
                                me->delete("kill_gumu");
                me->apply_condition("gumu_job",16);
               me->delete("kill_gumu");
                return 1;
                }
}

