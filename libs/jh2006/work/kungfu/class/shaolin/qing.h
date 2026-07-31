// qing.h for fight and get letter from Qing

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin1", ob) ) 
	{
		command("say 怎么样，你拿我的推荐信去拜师了吗 ?");
		return 0;
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok1",1);
	        command("say 好，既然已得到方丈许可，我们就来验证一下武功。");
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

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok1") ) return 0;

	if(me->query("eff_qi") < me->query("max_qi") ||
	me->query("qi") < me->query("eff_qi") ||
	me->query("neili") < me->query("max_neili")) {
		command("say 唉呀，我现在身体感觉不太好，你等一会儿再来吧。");
		return 0;
	}
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	ob->delete_temp("fight_ok1");
	
	return 1;
}

void checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	if (!ob) return;
	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",1, me, ob);
		return;
	}

	if ( !present(ob, environment()) ) return;

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		if (me->query_temp("last_damage_from") == ob) {
			command("say 青出於蓝胜於蓝，不愧是少林寺的佳弟子 ! 恭喜你了 !\n");
			message_vision("$N交给$n一封推荐信。\n", me, ob);
			ob->set_temp("have_letter",1);
			obj=new("/d/shaolin/obj/tuijianxin-1");
			obj->move(ob);
			return;
		}
		command("say 少林出了你们这样喜欢作弊的弟子，真是羞耻啊！");
		return;
	}

	command("say 看来" + RANK_D->query_respect(ob) + 
		"还得多加练习，方能在少林诸多弟子中出人头地 !\n");

	return;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
    mapping ob_fam;
     mapping my_fam  = me->query("family");

//    string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
        command("say " + RANK_D->query_respect(ob) + "是俗家弟子，请去跟清法师兄学艺。");
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

