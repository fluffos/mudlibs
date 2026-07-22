void check_skills(object ob)
{
	mapping skl;
	int *slevel;
	int counter;

	if (environment()->query("no_fight") || ob->query_temp("user_type") == "worker") return;
	skl = ob->query_skills();
	if (!sizeof(skl)) return;
	slevel  = values(skl);

	counter = 0;
	foreach (int item in slevel) if (item >= 100) counter++;

	if (!random(10) && counter >= 3 && (ob->query("combat_exp") > 100000)) {
		set_leader(ob);
		do_kill(ob);
	}
}

void do_kill(object dest)
{
	object me = this_object(), env = environment();

	remove_call_out("do_kill");
	if (objectp(dest) && present(dest, env) && !dest->is_busy()
	&& !env->query("no_fight") && !env->query("sleep_room")) {
		message_vision(HIR "$N对$n阴阴一笑：送上门的肥肉，"+RANK_D->query_rude(dest)+"，陪大爷我练练吧！\n" NOR, me, dest);
		set_leader(dest);
		kill_ob(dest);
		dest->fight_ob(me);
		checking(dest);
	}
	else call_out("waiting", 2, dest);
}

void waiting(object dest)
{
	object me = this_object();

	remove_call_out("waiting");
	if (objectp(dest)) {
		if (dest->is_ghost()) {
			call_out("do_back", 5+random(5));
			return;
		}
		if (is_fighting() && present(dest, environment())) {
			call_out("checking", 1, dest);
			return;
		}
		if (living(me) && environment(dest)->query("no_fight")){
			call_out("do_back", 2);
			return;
		}
		if (dest->query_temp("user_type") == "worker") {
			call_out("do_back", 2);
			return;
		}
		call_out("waiting", 1, dest);
	}
}

void checking(object dest)
{
	object ob;

	remove_call_out("checking");
	if (!dest) return;
	if (!present(dest, environment())) {
		call_out("waiting", 2, dest);
		return;
	}
	if (!is_fighting(dest)) kill_ob(dest);
	if (is_fighting())
	{
		call_out("checking", 1, dest);
		return;
	}
	if (objectp(ob = present("corpse", environment()))
	&& ob->query("victim_id") == dest->query("id") )
	{
		command("chat* kick corpse");
		tell_room(environment(), query("name")+"拍了拍身上的灰尘，快步走了出去。\n" NOR);
		call_out("do_back", 2);
		return;
	}
	call_out("waiting", 1, dest);
}
