// ZhangQiShi.h for fight and get letter from ZhangQiShi

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	add_action("do_join","join");

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping ob_party  = ob->query("party");

	if ( ob->query_temp("have_letter") && present("tuijian xin3", ob) ) 
	{
		command("say 怎麼樣，你拿我的推荐信去見堂主了嗎 ?");
		return 0;
	}

        if((obj->query("id") == "tieyan ling")
        && ob_party["party_name"] == HIG "明教" NOR
        && ob_party["level"] == 2
        && !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
		command("say 好，既然已得到教主許可，我們就來驗証一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

	if (obj->query("id") == "tuijian xin2" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 好，" + ob->query("name") + "，你愿意加入我旗嗎？");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

       
        command("?");
        command("say 這東西給我可沒有什麼用。");
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
                command("say 青出於藍勝於藍，不愧是我明教的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交給$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
                obj=new("/d/mingjiao/obj/tuijianxin-3");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看來" + RANK_D->query_respect(ob) + 
                        "還得多加練習，方能在明教諸多弟子中出人頭地 !\n");
		return 1;
	}

	return 1;  
}

void do_join()
{
	object me,ob;
        mapping ob_party;
        mapping party;
	string qi,new_rank;

	me=this_object();
	ob=this_player();
     ob_party=ob->query("party");

//            if (!(ob_party=ob->query("party"))||ob_party["party_name"]!="明教")
//          {
//                  command("say " + RANK_D->query_respect(ob) + "與本教素無來往，不知此舉是何用意？");
//                  return;
//          }

        if ( ob_party["level"] >= me->query("level") )
	{
                command("say " + RANK_D->query_respect(ob) + "，在下哪里敢當 !");
		return;
	}

	if ( ob_party["level"] == 1 )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say 哈哈哈 !");
                        command("say 本旗又得一可塑之才，真是可喜可賀 !");
                        qi = me->query("title")[11..32];
	        	command("say 恭喜你榮升為明教"+qi+"教眾！");
                party = allocate_mapping(5);
                party["party_name"] = HIG "明教" NOR;
                party["rank"] = qi+"教眾";
                party["level"] = 2;
                party["tasks"] = 0;
                party["enter_time"] = time();
                ob->set("party", party);
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你沒有推荐信，不能越級拜師。");
			return;
		}
	}

	return;
}

#include "mingjiao.h"
