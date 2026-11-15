// ouyang.h

int permit_recruit(object ob)
{
	object me;

	me = this_object();
	if (ob->query("name") == "欧阳锋" ||
	    ob->query("name") == "欧阳轲")
	{
		message_vision("$N大怒：我操！你起这个名字是什么意思啊？\n",
			       this_object());
		return 0;
	}

	if (ob->query("born_family") != "欧阳世家"&&ob->query("haha1"))
	{
		message_vision("$N对$n道：你不是我们欧阳家的人，我怎能收你为徒？\n",
			       me, ob);
		return 0;
	}

	if (ob->query("detach/欧阳世家") ||
	    ob->query("betrayer/times"))
	{
		message_vision("$N摇摇头对$n说：你反复无常，我不能收你为徒！\n",
			       me, ob);
		return 0;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != me->query("family/family_name"))
	{
		message_vision("$N对$n道：你虽然是欧阳家的人，但你入了其他门派，我不能收你为徒！\n",
			       me, ob);
		return 0;
	}

	return 1;
}
