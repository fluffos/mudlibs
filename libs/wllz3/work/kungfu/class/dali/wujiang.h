
void attempt_apprentice(object ob)
{
	string oldtitle;
	oldtitle = ob->query("dali_title");

	if ((int)ob->query_skill("kurong-changong",1) < 200 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}

	if ((int)ob->query("shen") < 100000 ){
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
	if((string)ob->query("family/family_name") == "大理段家") {
		command("say 很好，既然入我门来就得终身为奴供我驱使。");
		command("recruit " + ob->query("id"));
		ob->set("dali_title",oldtitle);
	}
	else{
		command("say 你是何人，如此大胆，假冒我府中厮仆！");
		return;
	}
}

int ask_me()
{
	string oldtitle;
	object ob, me;
	me = this_object();
	ob = this_player();
	if ((int)ob->query_skill("kurong-changong",1) < 200){
		command("say 你的武功恐怕是不能胜任武将的薪俸，再练几年功夫吧。\n");
		return 1;
	}
	oldtitle = ob->query("dali_title");
	if (strsrch(oldtitle, "大理镇南王府卫士") >= 0){
		ob->set_temp("fight_ok",1);
		command("say 好，既然如此想切磋，那就看你的本事如何了。\n");
		return 1;
	}
	else{
		command("say 只有卫士才能升武将。\n");
		return 1;
	}
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
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) {
		call_out("checking",2, me, ob);
		return 1;
	}
	if ( !present(ob, environment()) ) return 1;
	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say 青出於蓝胜於蓝，不愧是大理段家的好弟子！恭喜你了！\n");
		command("say 你的已经可以胜任大理武将！\n");
		upgrade_title(ob,"大理镇南王府武将");
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say 看来" + RANK_D->query_respect(ob) + "还得多加练习，方能在大理段家诸多弟子中出人头地！\n");
		return 1;
	}
	return 1;
}
void upgrade_title(object ob,string arg)
{
	string title;
	title=arg+clear_title(ob->query("dali_title"));
	ob->set("dali_title",title);
}
string clear_title(string arg)
{
	if (strsrch(arg, "大理镇南王府卫士") >= 0)
	{
		arg = replace_string(arg, "大理镇南王府卫士","");
	}
	return arg;
}
