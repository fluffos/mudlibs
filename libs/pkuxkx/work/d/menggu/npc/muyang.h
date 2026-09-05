int given(object ob)
{
	object sheep;
	if (sizeof(filter_array(children(__DIR__"item/sheep"), (: clonep :))) > 5)
		{
			command("say 我们家没有那么多羊啊。");
			return 1;
		}
	else 
		{
			command("say 那就有劳你帮靖儿去放羊了。");
			message_vision("李萍牵出一只羊交给$N。\n", ob);
			sheep=new(__DIR__"items/sheep");
			sheep->set("owner", ob->query("id"));
			ob->set_temp("lpjob/start",1);
			sheep->move(environment(this_object()));
			return 1;
		}
}

int ask_job()
{
	object ob = this_player();
    if ((int)ob->query("level")<2)
    {
        command("say 这孩子，这么弱的身体，心肠倒不错！");
        return 1;
    }
	else if (ob->query_temp("lpjob/start"))
		{
			command("say 你把我的羊弄到哪里去了？");
			return 1;
		}
	else
		{
			command("say 靖儿生病了，你要帮他放羊吗？");
			given(ob);
			return 1;
		}
}
