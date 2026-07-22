// TanZhu.h for fight and get letter from TanZhu

int do_join(string arg)
{
	object me, ob, obj ;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if( !arg || arg!="mingjiao" )
		return notify_fail("你要加入什么组织？\n"); 
   	if( ob->query_temp("have_letter") || present("tuijian xin1", ob ))
   	{
                command("say 好啊。");
                command("heihei "+ob->query("id") );
//                command("get xin1 from "+ob->query("id") );
		return 1;	
	}
/*
	if (ob->query("weiwang")>49)
        {
		message_vision("$N摇摇头，对$n说道：你已经加入天地会了，不能再入我明教。\n",me,ob);
		return 1;
  	}
	if(ob->query("shenlongjiao")) 
	{
		message_vision("$N摇摇头，对$n说道：你已经加入神龙教了，不能再入我明教。\n",me,ob);
		return 1;
	}
  */
   	if( !mapp(party = ob->query("party")) )
   	{
		message_vision("$N点点头，对$n说道：好，你到昆仑山总舵去找接引使者，他会让你入教的。\n",me,ob);
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
                obj=new("/d/mingjiao/obj/tuijianxin-1");
		obj->move(ob);
		return 1;	
	}
   	if( party["party_name"] != HIG "明教" NOR )
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我明教。\n",me,ob);
		return 1;
	}
	else
		message_vision("$N摇摇头，对$n说道：你已经是我明教的人了。\n",me,ob);
	return 1;
}
int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping ob_fam= ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin2", ob) ) 
	{
		command("say 怎麽样，你拿我的推荐信去见门主了吗 ?");
		return 0;
	}

	if((obj->query("id") == "tieyan ling")
&& ob_fam
	&& ob_fam["family_name"] == "明教"
	&& ob_fam["generation"] == 6
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
		command("say 好，既然已得到教主许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
        command("?");
        command("say 这东西给我可没有什麽用。");
//        command("give " + obj->query("id") + " to " + me->query("id"));
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
	        command("say 青出於蓝胜於蓝，不愧是我明教的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/mingjiao/obj/tuijianxin-2");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
		"还得多加练习，方能在明教诸多弟子中出人头地 !\n");
		return 1;
	}

	return 1;  
}
void attempt_apprentice(object ob)
{
	object me;
	mapping ob_fam,my_fam;
	string name, new_name;  
              me=this_object();
	my_fam  = me->query("family");
	name = ob->query("name");
  if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")
	{
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
		return;
	}
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
                command("say " + RANK_D->query_respect(ob) + "，在下哪里敢当 !");
		return;
	}

        if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
		ob->set("mjlevel",4);
		return;
	}

		command("say 恭喜你荣升为明教本坛教众！");
    command("recruit " + ob->query("id"));
    ob->set("mjlevel",4);
    return;		
}

#include "mingjiao.h"
