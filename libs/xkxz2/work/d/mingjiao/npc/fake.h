void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting()&&ob->query_temp("protecting")  ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
   object me;
   me=this_player();
	ob=this_object();
	if(ob->query_temp("fighted")) {
		remove_call_out("wait");
		call_out("wait",10,ob);
	}
	if ((me->query_temp("protecting"))&&!(me->query_temp("fighted"))
		&&(me->query("combat_exp")>10000)){
		tell_object(me,HIR"突然你看见"+ob->name()+"向你冲了过来！原来他是六大门派弟子\n\n"
"装扮成"+ob->name()+"而想混入光明顶的。\n\n"NOR);
		command("say "+me->name()+"，拿命来吧！");
		remove_call_out("do_copy");
		call_out("do_copy",1,me);
           }
}

int do_copy(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;
	me = this_object();

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]+(skill_status[sname[i]])/2);
		}
	}

	hp_status = ob->query_entire_dbase();

		me->set("max_qi",    hp_status["max_qi"]+(int)((hp_status["max_qi"])/3));
		me->set("eff_qi",    hp_status["eff_qi"]+(int)((hp_status["eff_qi"])/3));
		me->set("qi",        hp_status["qi"]+(int)((hp_status["qi"])/3));
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]+(int)((hp_status["max_neili"])/3));
		me->set("neili",     hp_status["neili"]+(int)((hp_status["neili"])/3));
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]+(int)((hp_status["combat_exp"])/3));
	remove_call_out("do_kill");
	call_out("do_kill",1,ob);
	return 0;
}
int do_kill(object ob)
{
	object me;
	me=this_object();
	me->kill_ob(ob);
	ob->kill_ob(me);
	ob->set_temp("fighted",1);
	ob->set_temp("foradd",1);
	remove_call_out("do_wait");
	call_out("do_wait",10,ob);
}
int do_wait(object ob)
{
	object me;
	me=this_object();
	ob=this_player();
	if(!(present(ob, environment(me)))){
		message_vision("只见$N整了整衣衫，慌慌张张的离开了。\n", me);
		ob->delete_temp("foradd");
		ob->add_temp("tasted",1);
		ob->delete_temp("fighted");
		destruct(me);
	return 0;
	}
	remove_call_out("wait");
	call_out("wait",10,me);
}

void die()
{
	object ob;
	ob=query_temp("last_damage_from");
	if(objectp(ob) && ob->query_temp("foradd")){
	ob->add_temp("tasted",3);
	ob->delete_temp("foradd");
	ob->delete_temp("fighted");
	}
	::die();
}
