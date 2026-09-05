//miejue.c 灭绝师太
//create bye cuer  
//modified by advent
//modified by Zine EM newbie job
#include <ansi.h>
#include "/d/emei/bonus.h"
inherit NPC;
inherit F_MASTER;
#include <title.h>
#include <no1master.h>
int ask_job();
int ask_zd();
int ask_fail();
int ask_finish();
void consider();
void heal();
int ask_ling();
int ask_xiashan();
int ask_me();
int ask_jsjs();
string ask_for_leave();

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
  add_action("do_decide", "decide");
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
        set_skill("music", 250);
        set_skill("music::music-theory", 350);
        set_skill("music::qin", 350);
        set_skill("music::qin::gaoshan-liushui", 300);
        set_skill("music::qin::guangling-san", 300);
        set_skill("music::qin::puan-zhou", 350);
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
		set("bonus",5);
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
                 "截手九式" : ( : ask_jsjs : ),
                 "还俗" : (: ask_for_leave :),
                    "help" : (: ask_job :),
                    "帮助" : (: ask_job :),
                    "fail" : (: ask_fail :),
                    "失败" : (: ask_fail :),
                    "指点" : (: ask_zd :),
                 "zhidian" : (: ask_zd :),
                    "finish": (: ask_finish :),
                    "完成": (: ask_finish :),
                 ]));
		setup_no1master();
}

int ask_zd()
{
    object me=this_player();
    object ob=this_object();
	object user;
    int n,i;
    string* gifts =({"str","int","dex","con","kar","per","spi",     }); 
    string gift,cgift;
    object key=load_object("/d/emei/houshan/jxan");
    if (ob->is_busy()||ob->is_fighting())
    {
        command("hmm");
        return 1;
    }
    if (!me->query("emeinewbiejobdone"))
    {
        command("hmm");
        return 1;
    }
    user=me->query_temp("link_ob");
        if (!user->query("realuser_verified"))
        {
            tell_object(me,"只有通过实名认证的玩家才可领取额外奖励。\n");
            return 1;
        }
    if (me->query("family/family_name")!="峨嵋派")
    {
        command("hmm");
        return 1;
    }
    if (me->query("emeinewbiejobdonedone1"))
    {
        command("hmm");
        return 1;
    }
    if (me->query("level")>3)
    {
        command("say 我也没有什么可以指点你的了。");
        return 1;
    }
    me->set("emeinewbiejobdonedone1",1);
    n=1+random(5);
    message_vision("$N用醍醐灌顶的功法输送了一些功力到$n的体内。\n",ob,me);
    me->add("level",n);
    write(HIC+ob->name()+"把你的级别提升到了"+chinese_number((int)me->query("level"))+"级！\n"NOR);
    for (i=0;i<n-1;i++)
    {
        if (random(5)==3)
        {
            gift=gifts[random(sizeof(gifts))];
            me->add(gift,1);
            me->add("xiantian/"+gift+"/level",1);
            if (gift=="str") cgift="膂力";
            if (gift=="int") cgift="悟性";
            if (gift=="con") cgift="根骨";
            if (gift=="dex") cgift="身法";
            if (gift=="per") cgift="容貌";
            if (gift=="kar") cgift="福缘";
            if (gift=="spi") cgift="灵性";
            tell_object(me,HIY"你的先天"+cgift+"增加了！\n"NOR);
        }
    }
    return 1;
}

int ask_fail()
{
	object me=this_player();
	object ob=this_object();
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->is_busy()||ob->is_fighting())
	{
		tell_object(me,ob->name()+"正忙着呢。\n");
		return 1;
	}
	if (me->query("family/family_name")!="峨嵋派")
	{
		command("say 阁下不是峨嵋派弟子，请回吧。");
		return 1;
	}
	if (!me->query("emnewbiejob/start"))
	{
		command("say 我没有给你任务啊，你是不是记错了？");
		return 1;
	}
	else
	{
		command("say 放什么弃，我派弟子没有放弃的道理，继续去做！");
		return 1;
	}

}

int ask_finish()
{
	object me=this_player();
	object ob=this_object();
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->is_busy()||ob->is_fighting())
	{
		tell_object(me,ob->name()+"正忙着呢。\n");
		return 1;
	}
	if (me->query("family/family_name")!="峨嵋派")
	{
		command("say 阁下不是峨嵋派弟子，请回吧。");
		return 1;
	}
	if (!me->query("emnewbiejob/start"))
	{
		command("say 我没有给你任务啊，你是不是记错了？");
		return 1;
	}
	if (me->query("emnewbiejob_miejue_task")=="xx")
	{
		command("say 不错不错，你真的让我很满意。");
		bonus(me);
        
		me->delete("emnewbiejob/start");
		me->delete("emnewbiejob_miejue_task");
		me->delete_temp("emnewbiejob");
		return 1;
	}
	else
	{
		command("say 谁交给你的任务，就找谁去复命吧。");
		return 1;
	}
}

int ask_job()
{
    object ob=this_object();
    object me=this_player();
    int n;
    string * taskname=({"星宿派"});
    if (me->query("family/family_name")!="峨嵋派")
    {
        command("say 外派弟子？");
        return 1;
    }
    if (!me->query_temp("emnewbiejob/miejue/start"))
    {
        command("say 我这里暂时不需要人，你去别处看看吧。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢\n");
        return 1;
    }
    if (me->query("emnewbiejob_miejue_task"))
    {
        command("say 叫你去就快去。");
        return 1;
    }
    n=random(sizeof(taskname));
    me->set("emnewbiejob_miejue_task",n+1);
    me->set("emnewbiejob/start",1);
    if (n==0)
    {
        command("say 近日屡有我派弟子被星宿中人打伤，我与星宿派大弟子"+FAMILY_D->get_dadizi_name("星宿派")+"来有故，你去问问他到底怎么回事。");
    }
    if (n==1)
    {
        command("say 华山派宁中则女性生日快要到了，你去替我问候一下吧。");
    }
    return 1;
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

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("class")!="bonze" )
		return "阿弥陀佛！施主并未出家，何故跟贫尼开这等玩笑？";

	if( (string)me->query("family/family_name") != "峨嵋派")
		return "阿弥陀佛！施主非我峨嵋弟子，还俗的事情贫尼作不得主。";

	me->set_temp("pending/leave_emei", 1);
		return "阿弥陀佛！如果" + RANK_D->query_respect(me) + "真想离我佛门而去，就请下决心(decide)吧！";
}

int do_decide()
{
	string* skillname;
	int lev;
	mapping skills;
	int i;
	object me = this_player();
//	object body;
	
	if (me->query_temp("pending/leave_emei") != 1)
		return 0;
	message_vision("$N对$n说道：「阿弥陀佛！从此施主就不再是我峨嵋门下了，请好自为之！」\n",this_object(), me);
	tell_object(me,HIR "你决定叛出峨嵋门下！\n" NOR);
	me->delete_temp("pending/leave_emei");
  me->expell_family("峨嵋派");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
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
        if(random(44)==11)
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
        object me = this_object();
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
	string name, new_name,color;
	
	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}
  
  if ( ob_fam["generation"] == 0 || ob_fam["master_id"]=="zhou zhiruo")
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
			{
				name = ob->query("name");
				color=COLOR_D->get_color(name);
				name=COLOR_D->uncolor(name);
				new_name = "静" + name[1..1];
				new_name=color+new_name+NOR;
			  ob->set("name", new_name);
			  ob->set_face( FACE_FACT, ob->query("name") );
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

int ask_jsjs()
{
        mapping fam;
        object me  = this_player();

        if (!(fam=me->query("family")) || (fam["family_name"] != "峨嵋派")){ 
                command("say 想偷学，门都没有！");
                return 0;
        }
        if (me->query("em/foguang") && me->query_skill("jieshou-jiushi",1)>1){
                command("pat "+me->query("id")); 
                command("say 你已经学会了，好好练习，光复我峨嵋绝学！");
                return 1;        
        } 
        if(me->query("family/master_name") != "灭绝师太"){
                command("look "+me->query("id"));        
                command("say 截手九式只传授给我的弟子！");
                return 1;
        }
        if ((int)me->query_condition("emei_foguang") > 0 )
        {
               command("bored "+me->query("id"));
               command("say 你我无缘，你还是去为峨嵋多做点贡献吧！");      
               return 1;  
        }   
        command("grin "+me->query("id"));
        command("say 嘿嘿，想当年光明顶打伤张无忌，截手九式只传授给有缘人。。");
        if (random(me->query("score")) < 1500)
        {
               command("goaway");
               command("say 也许是你机缘不足，灭绝师太咕噜了几句就没再理你。");
               me->apply_condition("emei_foguang",60);
               return 1;
        }
        command("pat "+me->query("id"));
        me->set_skill("jieshou-jiushi", 3);
        me->set("em/foguang",1);
        command("say 你对峨嵋如此尽力，况且你我之间缘分极好，我就传你几招，记得好好练习，光复我峨嵋武学。");
        command("say 切记，对使用九阳神功的对手不要使用绝招，当年我就吃了这个亏，哎！");
        me->set("em/foguang", 1);
        return 1;
}

#include "/kungfu/class/masterdie.h"
