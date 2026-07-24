// MenZhu.h for fight and get letter from MenZhu

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping ob_party  = ob->query("party");

	if ( ob->query_temp("have_letter") && present("tuijian xin2", ob) ) 
	{
		command("say 怎麼樣，你拿我的推荐信去見掌旗使了嗎 ?");
		return 0;
	}

	if((obj->query("id") == "tieyan ling")
	&& ob_party["party_name"] == HIG "明教" NOR
	&& ob_party["level"] == 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
		command("say 好，既然已得到教主許可，我們就來驗証一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
        command("?");
        command("say 這東西給我可沒有什麼用。");
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
	        command("say 青出於藍勝於藍，不愧是我明教的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交給$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/mingjiao/obj/tuijianxin-2");
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

#include "mingjiao.h"
