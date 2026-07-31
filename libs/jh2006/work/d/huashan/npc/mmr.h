// mmr.h for hs job

int do_clone(object me, object ob);

int count = 0;

void init()
{
	object ling, name1;
	object ob = this_player();
	name1 = ob->query("id");
	ling = present("ling pai");

	::init();
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ling
	&& ling->query_temp("mmr") == name1
	&& ling->query_temp("hsjob") == name1
	&& query_temp("mmr") == name1
	&& ob->query_temp("hs/jobji")
	&& ob->query_temp("hs/have"))
	{
		if (count++) {
			if (count == 5) {
				remove_call_out("kill");
				call_out("dest", 1);
			}
		} else {
			set_leader(ob);
			if (!query_temp("skillset")) do_clone(this_object(), ob);
			call_out("kill", 1, ob); 
		}
	}
}       

void kill(object ob)
{
	if (!ob) return;
	command("say 想跑，大爷今天就超渡你！！！");
	kill_ob(ob);
}

void kill_ob(object ob)
{
	if (ob->query("id") != query_temp("mmr")) {
		ob->remove_killer(this_object());
		tell_object(ob, "这不是抢走你令牌的人。\n");
		return;
	}
	::kill_ob(ob);
}

int do_clone(object me, object ob)
{
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;
	number = (int)ob->query("max_pot");
	number = number-100;
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

	killerskill1 = skill2[random(sizeof(skill2))];
	number = (int)(number - (random(5)?1:-1)*random(number/10));
	me->set("dex", ob->query("dex")*6/5);
	me->set("str", ob->query("str"));
	me->set("con", ob->query("con")*6/5);

	//add log to HS_JOB_LOG
	//      if (userp(ob) && (number > ((int)ob->query("max_pot")-100)))
	if (number > ((int)ob->query("max_pot")-100))
	log_file("job/HS_JOB",sprintf("%s %s(%s) 第%d次任务目标等级%d，本人等级%d。\n",
		ctime(time())[4..19],ob->name(1),ob->query("id"),ob->query("hs_job"),number,ob->query("max_pot")-100));

	/*set killer's skill*/

	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];       

	me->set_skill("force",number);
	me->set_skill("dodge",number);
	me->set_skill("parry",number);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number);
	me->set_skill(killerskill1["t_skill"],number);
	me->set_skill(killerskill1["b_skill"],number);


	/* set killer's  skill maps */

	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

	/* set killer's skill prepares */

	me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

	/* copy entire dbase values */

	me->set("max_qi",k_qi*6/5);
	me->set("eff_qi",k_qi*6/5);
	me->set("qi",k_qi*6/5);
	me->set("max_jing",k_jing);
	me->set("eff_jing",k_jing);
	me->set("jing",k_jing);
	me->set("max_neili",k_neili);
	me->set("neili",k_neili);
	me->set("jiali", k_neili / 200);
	me->set("combat_exp",ob->query("combat_exp"));

	me->add_temp("apply/attack",  number / 10 + random(number / 10));
	me->set_temp("apply/dodge", 50);

	me->set_temp("skillset",1);
	remove_call_out("dest");
	call_out("dest",200);
	return 1;
}

void dest()
{
	if (!living(this_object())) {
		call_out("dest", 10);
		return;
	}
	if (count >= 5) command("say 大爷没时间陪你溜达！");
	else command("say 他奶奶的，这次算你命大，下回看老子还饶得了你！");
	say(name()+"匆匆离开。\n");
	destruct(this_object());
}
/*
void unconcious()
{
	object me, ob,name1, ling;
	me = this_object();
	ob = this_player();
	name1 = ob->query("id");
	ling = present("ling pai", ob);
	if ( ling
			&&  !(ling->query_temp("mmr") != name1 )
			&&  !(me->query_temp("mmr") != name1 ) ) {
		if (! (ling->query_temp("killed") )) {
			ling->set_temp("killed", 1);
			ob = new("/clone/money/gold");
			ob->move(me);
		}
		else {
			ling->add_temp("killed", 1);
		}
	}
	::unconcious();
}

int hit = 0;

int hit_ob(object me, object ob, int damage)
{
	hit+=2;
	if (damage > 800) return (800-damage);
	return 0;
}

int ob_hit(object me, object ob, int damage)
{
	if (!hit) return -damage*8/10;
	hit--;
	return 0;
}
*/
