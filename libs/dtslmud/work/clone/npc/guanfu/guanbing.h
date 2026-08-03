// guanbing.h
// all include 官兵，武将 by Lklv 2002.1.18

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player())
	 && living(this_object())
	 && ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
        }
}

int accept_fight(object me)
{
	if (!me) return 0;
	if (query("id")=="wu jiang"){
		command("pei ");
		command("say 敢对朝廷命官无礼，今天让大爷我教训教训你！\n");
		fight_ob(me);
		return 1;
	}
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	if (!is_killing(me->query("id")))
		me->add_condition("killer", 5);
	kill_ob(me);
	return 1;
}

void kill_ob(object ob)
{
	if (!ob) return;
	if (query("id") == "wu jiang")
		command("say 你！你！你！来人啊，给我拿下这个反贼！！！");
	else
		command("say 反贼！哪里走！！！");
	::kill_ob(ob);
}
