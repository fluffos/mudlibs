// murong.h

int permit_recruit(object ob)
{
    object me;

    me = this_object();
    if (ob->query("name") == "慕容柏" ||
	ob->query("name") == "慕容负")
    {
	message_vision("$N大怒：哼！你起这个名字算是什么意思？\n", me);
	return 0;
    }
    
    if (ob->query("detach/慕容世家") ||
	ob->query("betrayer/times"))
    {
	message_vision("$N摇摇头对$n说：你反复无常，我慕容家不留这种人！\n",
		       me, ob);
	return 0;
    }

    if (ob->query("family/family_name") &&
	ob->query("family/family_name") != me->query("family/family_name"))
    {
	message_vision("$N对$n道：你既然是慕容家的人，却入了其他门派，实在是大逆不道！\n",
		       me, ob);
	return 0;
    }

    return 1;
}
