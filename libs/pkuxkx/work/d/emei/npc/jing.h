// jing.h for fight and get letter from Jing
//create bye cuer
//modified by Zine 2011-05-13 峨嵋新手任务
#include <ansi.h>
#include <title.h>
#include "/d/emei/bonus.h"
int ask_job();
int ask_fail();
int ask_finish();

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
  if (!ob->query("inquiry"))
  {
      set("inquiry", ([
			"help" : (: ask_job :),
            "帮助" : (: ask_job :),
            "fail" : (: ask_fail :),
            "失败" : (: ask_fail :),
            "finish": (: ask_finish :),
            "完成": (: ask_finish :),
			
      ]) );
  }
  
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    object jing;
	if (!me->query_temp("emnewbiejob/jingwen/start"))
	{
		command("say 我这里没什么事，你去别处看看吧。");
		return 1;
	}
	if (me->query_temp("emnewbiejob/jingwen/give"))
	{
		command("say 你不是拿过经文了，改好了吗？");
		return 1;
	}
    jing=new("/d/emei/houshan/npc/obj/jing");
    jing->set("owner",me->query("id"));
    jing->move(me);
    me->set_temp("emnewbiejob/jingwen/give",1);
	me->set("emnewbiejob/jingwen/start",1);
    message_vision("$N道：我前些天抄写大般涅槃经抄错了些地方，$n你帮我改正过来吧。\n",ob,me);
    tell_object(me,ob->name()+"给了你一张手抄的经文，你可以用核对(hedui)命令检查抄错的地方。\n");
    return 1;
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    object jing;
    if (!me->query_temp("emnewbiejob/jingwen/finish"))
    {
        command("say 你改正过来了吗？");
        return 1;
    }
    if (!present("jing",me))
    {
        command("say 我的经文你带来了吗？");
        return 1;
    }
    jing=present("jing",me);
    if (!jing->query("is_jing")||jing->query("owner")!=me->query("id"))
    {
        command("say 你带来了改好的经文吗？");
        return 1;
    }
    else
    {
        command("say 不错不错，这样就对了。"); //奖励
		bonus(me);
        me->delete("emnewbiejob/start");
        me->delete("emnewbiejob/jingwen/start");
		me->delete_temp("emnewbiejob");
        destruct(jing);
        return 1;
    }
}

int ask_fail()
{
    object me=this_player();
    object ob=this_object();
    object jing;
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
    if (present("jing",me))
    {jing=present("jing",me);}
	if (me->query("emnewbiejob/jingwen/start"))
	{
		command("say 罢了，求人不如求己，我还是自己来吧。");
		punish(me);
        me->delete("emnewbiejob/jingwen/start");
        me->delete("emnewbiejob/start");
		me->delete_temp("emnewbiejob");
		if (jing&&jing->query("is_jing")&&jing->query("owner")==me->query("id"))
		{destruct(jing);}
		return 1;
	}
	else
	{
		command("say 谁交给你的任务，就找谁去放弃吧。");
		return 1;
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();
	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");
	if ( ob->query_temp("have_letter") && present("jieshao-xin2", ob) ) 
	{
		command("say 怎麽样，你拿我的介绍信去拜师了吗 ?");
		return 0;
	}
	if((obj->query("id") == "emei ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
	        command("say 好，既然已得到掌门许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
	if (obj->query("id") == "jieshao-xin1" 
	&& ob->query_temp("have_letter") )
	{
		if( !(me->query("class")) && ob->query("class") == "bonze" )
                {
                       command("sigh");
                       command("say 我不收出家弟子，施主请回吧。");   
                       command("give " + obj->query("id") + " to " + me->query("id"));
                       return 1;
                }
                ob->set_temp("apprentice_ok",1);
	        command("say 好，" + ob->query("name") + "，你愿意拜我为师吗？");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 1;
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
int accept_fight(object ob)
{
	object me  = this_object();   
	if ( !ob->query_temp("fight_ok") ) return 0;

        set("eff_qi",me->query("max_qi"));
        set("qi",me->query("max_qi"));
        set("neili",me->query("max_neili"));
        set("jing",me->query("max_jing"));
        set("eff_jing",me->query("max_jing"));
        if((int)me->query_skill("sword",1))
            carry_object(__DIR__"obj/changjian")->wield();
        if((int)me->query_skill("blade",1))
            carry_object(__DIR__"obj/gangdao")->wield();

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("fight_ok");
	
	return 1;
}
int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;
	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");
	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
                return 1;
	}
	if ( !present(ob, environment()) ) return 1; 
	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say 青出於蓝胜於蓝，不愧是峨嵋派的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交给$n一封介绍信。\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new(__DIR__"obj/xin2");
		obj->move(ob);
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
			"还得多加练习，方能在峨嵋诸多弟子中出人头地 !\n");
		return 1;
	}
	return 1;  
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
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫尼哪里敢当 !");
		return;
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..0] == "文")
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say 是" + ob_fam["master_name"] + "叫你来找我的吧，哈哈哈 !");
			command("say " + RANK_D->query_self(me) + "又得一可塑之才，真是可喜可贺 !");
      if(ob->query("class") == "bonze" )
			{
				new_name = "文" + name[1..1];
			  ob->set("name", new_name);
			  ob->set_face( FACE_FACT, ob->query("name") );
	      command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为峨嵋派文字辈弟子 !");
      }  
      else
        command("say 恭喜你荣升为峨嵋派五代弟子 !");
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
