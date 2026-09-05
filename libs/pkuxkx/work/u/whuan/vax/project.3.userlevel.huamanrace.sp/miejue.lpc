//miejue.c 灭绝师太
//create bye cuer  
//modified by advent
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void consider();
void heal();
int ask_ling();
int ask_xiashan();
int ask_me();

string s_skill;
string ask_special_skill();
void init()
{
  object me = this_player();
  object ob = this_object();
  if( me->query("family/master_id") == ob->query("id") )
    if(me->query("score") < -100)
       {            
         command("shake");
         command("say 你扪心自问，你都对师门干了些什么？我岂能仍是你的师傅。\n");
         command("expell "+ me->query("id"));
       }
}

 
void create()
{
        set_name("灭绝师太", ({
                "miejue shitai",
                "miejue",
                "shitai",
        }));
        set("long",
                "她是一位中年师太。\n"
        );
        set("gender", "女性");
        set("nickname","峨嵋派第三代掌门");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 30);
        set("int", 27);
        set("con", 20);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 120);
        set("combat_exp", 11000000);
        set("score", 100);
        set("sword",1);
        set_skill("force", 400);
        set_skill("linji-zhuang", 450);
        set_skill("dodge", 400);
        set_skill("zhutian", 400);
        set_skill("tiangang-zhi", 480);
        set_skill("finger", 480);
        set_skill("jinding-mianzhang",460);
        set_skill("strike",480);
        set_skill("fuliu-jian",450);
        set_skill("sword",400);
        set_skill("yanxing-dao",450);
        set_skill("blade",400);
        set_skill("throwing",400);
        set_skill("pili-dan",450);
        set_skill("parry", 400);
        set_skill("mahayana", 450);
        set_skill("literate", 400);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "fuliu-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("sword", "fuliu-jian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("throwing", "pili-dan"); 
        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-mianzhang");

        set("chat_chance",100);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        set("chat_chance",100);
        set("chat_msg",({
        (:heal:),
        }));
        create_family("峨嵋派", 3, "掌门");
        setup();
        carry_object(__DIR__"obj/changjian");
        carry_object(__DIR__"obj/gangdao");
        carry_object(__DIR__"obj/cloth")->wear();

		// 特别技能指导能力
		s_skill = "master-taiyang";
        set("inquiry",([
                 "峨嵋令" : (: ask_ling :),
                 "名字" : "我就是峨眉派的掌门人灭绝师太呀！你怎么连我都不认识？",
                 "峨嵋" : "峨嵋是天下第一派，我派创始人郭女侠名震南北！",
                 "灭绝师太" : "我就是灭绝师太啊。",
                 "周芷若" : "她是我最得意的徒儿，只可惜跟明教那个魔头有来往",
                 "张无忌" : "就是他带坏了我的好徒儿！",
                 "杨逍" : "魔教的臭贼！",
                 "下山" : ( : ask_xiashan : ),
                 "倚天剑" : ( : ask_me : ),
                s_skill       : (: ask_special_skill :),
                 ]));
}


string ask_special_skill()
{
	object user;
	int cur_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，老尼已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		if (YINYANG_D->query_yinyang(user) != "太阳")
			return "你的内功并没有显现出太阳气息，恕在下无法指导。\n";
			
		if (!SPECIAL_D->query_level(user, "master-con"))
			return "你先要修习"+to_chinese("master-con")+"(master-con)才能修练"+to_chinese(s_skill)+"。";
		
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句控制太阳气息的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你感觉内功的太阳气息也随之增强了。\n");
			return "拼死我也要杀了张无忌！";
		}
	}
	return "什么？";
}
int ask_me()
{
        mapping fam;
        if (!(fam=this_player()->query("family")) || (fam["family_name"] != "峨嵋派"))  
        {
        say("灭绝师太说道：“这是江湖谣传，倚天剑不在本派！”\n");
        return 1;
        }
        else
        {
        say("灭绝师太说道：“本派的倚天剑在方碧琳处保管。”\n");
        this_player()->set_temp("marks/方",1);
        return 1;
        }
}

int ask_xiashan()
{
  object me = this_player();
  if( (string)me->query("family/family_name") != "峨嵋派" )
     {
      command("say 施主与本派素无渊源，问这干吗？");
      command("? "+(string)me->query("id"));
      return 1; 
     }
  if( !(me->query("xiashan")))
     {
      say("灭绝师太有些发怒了。\n");
      command("say 我已经同意你可以下山了。你还来问干什么？");
      return 1;
     }      
/*  else if( me->query("age") < 15)
     { 
      command("pat "+(string)me->query("id"));
      command("say 江湖上人心险恶啊！还是等你年纪大点在去吧。");
      return 1;
     }      
*/   
  else if(!(me->query_temp("xia1")))
     {
      command("say 好吧，那你就进一趟蛇窟，看能否闯出来。");
      me->set_temp("xia1",1);
      return 1; 
     }
  else if(me->query_temp("xia1") == 1 && !(me->query_temp("xia2")))
     {
      say("灭绝师太有些发怒了。\n");
      command("say 你还没有闯过蛇窟，又来问干什么？");
      return 1;
     }  
  else if( me->query_temp("xia2") == 1)
     {
      command("smile");
      command("say 不愧是峨嵋派的好徒儿，你可以自由下山了。");
      me->delete_temp("xia1");
      me->delete_temp("xia2");
      me->delete("xiashan");
      return 1; 
     }   
  
  else 
      return 0;
}              


int ask_ling()
{
   object me = this_player();
   object ob = this_object();
   object obj;    
   mapping my_fam;
   if(!(my_fam = me->query("family")) || my_fam["family_name"] != "峨嵋派")
        {
            command("say 施主与本派速无渊源，要本派信物何用？\n");
            return 1;
        }
   if( ( my_fam["generation"] == 6 && me->query("score") < 200 )
       || ( my_fam["generation"] == 5 && me->query("score") < 500 ) )
        {
            command("shake");
            command("say 你对师门的贡献还不够，加紧努力吧。");
            return 1;
        }     
   if ( my_fam["master_id"] == ob->query("id") )
        {
            command("? "+me->query("id"));
            command("say 你已是我的徒儿了，还要令干吗？");
            return 1;
        }
   obj=new(__DIR__"obj/emling");
   obj->move(me);
   command("say 好吧，凭此令可以和师傅们比划了。\n");
   return 1; 
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield jian");
            command("perform sword.miejian " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("wield blade");
            command("wield jian");
            command("perform blade.heji " +target->query("id"));
            command("unwield jian");
            command("unwield blade");
             break;
             }
}
void heal()
{
        object ob = this_object();
        if(random(10)==1)
         { 
          switch(random(3)){
             case 0 : say("灭绝师太咬牙切齿的说：“一定要杀了赵敏这贱人！”\n");break;
             case 1 : say("灭绝师太说：“周芷若这小丫头也太不知好歹了。”\n");break;
             case 2 : command("sigh");break;         
              }
          }
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                if(random(5)==1)
                {say(GRN"灭绝师太怒声说道：“你好大胆子，居然敢打伤我！”\n"NOR);
                 say(RED"看来灭绝师太要使出全力了！\n"NOR);
                 ob->set("jiali",150);
                } 
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                  command("exert regenerate");
                 return;
}

int accept_object(object ob, object obj)
{
		object user;
        object me = this_object();
		
		user = me;
		if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
				&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
		{
			message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
			user->delete_temp("mark/gold_"+s_skill);
			user->set_temp("mark/ok_"+s_skill, 1);
			return 1;
		}
		
        if (obj->query("id") == "jieshao-xin2"
        && ob->query_temp("have_letter") )
        {
                ob->set_temp("apprentice_ok",1);
                command("say 好，" + ob->query("name") + "，你愿意拜我为师吗？");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
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
void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");
	string name, new_name;
	name = ob->query("name");
	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}
	if ( ob_fam["generation"] == 0 )
	{
		command("say 阿弥陀佛！贫尼就收下你做我的弟子了。");
		command("recruit " + ob->query("id"));
		return;
	}
	
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say 是" + ob_fam["master_name"] + "叫你来找我的吧，哈哈哈 !");
			command("say 贫尼又得一可塑之才，真是可喜可贺 !");                     
                        if(ob->query("class") == "bonze" )
			{new_name = "静" + name[1..1];
			ob->set("name", new_name);
	                command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为峨嵋派静字辈弟子 !");
                        }
                        else 
                        command("say 恭喜你荣升为峨嵋派四代弟子 !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你没有介绍信，不能越级拜师。");
			return;
		}
	}
	return;
}
