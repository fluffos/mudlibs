// qing.h for fight and get letter from Qing
#include <title.h>

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin1", ob) ) 
	{
		command("say 怎麽样，你拿我的推荐信去拜师了吗 ?");
		return notify_fail(" \n");
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) ){
		ob->set_temp("fight_ok",1);
	        command("say 好，既然已得到方丈许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
		}
		else 
                {command("say " RANK_D->query_respect(this_player()) +
                         "得去找你自己的师傅去比试。");
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

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok") ) return 0;

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
		command("say 青出於蓝胜於蓝，不愧是少林寺的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/shaolin/obj/tuijianxin-1");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
			"还得多加练习，方能在少林诸多弟子中出人头地 !\n");
		return 1;
	}

	return 1;  
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name,color;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] == 0 )
	{
		command("say 阿弥陀佛！贫僧就收下你做我的弟子了。");
		command("recruit " + ob->query("id"));
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
           if (this_player()->query("class")=="bonze")
             ob->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
           else
             ob->set("title",HIR "少林" NOR + CYN "俗家弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	         ob->set_title(TITLE_RANK, ob->query("title"));
        }

}

void re_rank(object student)
{
        if (this_player()->query("class")=="bonze")
          student->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
        else
          student->set("title",HIR "少林" NOR + CYN "俗家弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title"));
}
