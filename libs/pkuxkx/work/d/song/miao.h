void init()
{
	add_action("do_buzhi","buzhi");
	add_action("do_action","action");
}

int do_action(string arg)
{
	object me=this_player();
	if (me->query_temp("songtasks/taichangsi/task")!=1)
	{
		return 0;
	}
	if (me->query_temp("songtasks/taichangsi/1/finish"))
	{
		return notify_fail("既然已经完成，可以回太常寺交卸任务了。\n");
	}
	if (!me->query_temp("songtasks/taichangsi/action"))
	{
		return notify_fail("你要先布置(buzhi)一下，才知道需要干什么！\n");
	}
	if (!arg)
	{
		return notify_fail("你要干么？");
	}
	if (arg!=me->query_temp("songtasks/taichangsi/action"))
	{
		me->add_temp("songtasks/taichangsi/action_degree",-1);
	}
	else
	{
		me->add_temp("songtasks/taichangsi/action_degree",1);
	}
	message_vision("$N在"+environment(me)->query("short")+"里开始"+arg+"。\n",me);
	me->delete_temp("songtasks/taichangsi/action");
	if (me->query_temp("songtasks/taichangsi/action_degree")>10)
	{
		tell_object(me,"这里已经被布置的完美无缺了。\n");
		me->set_temp("songtasks/taichangsi/1/finish",1);
	}
	else if (me->query_temp("songtasks/taichangsi/action_degree")<-5)
	{
		tell_object(me,"这里已经被你糟蹋的不可收拾了。\n"+RED+"你的大宋功勋下降了！\n"+NOR);
		me->delete_temp("songtasks");
		me->add("song/credit",-3);
	}
	else
	{
		tell_object(me,"似乎还有些欠缺，继续布置(buzhi)吧。\n");
	}
	return 1;
}
int do_buzhi()
{
	object me=this_player();
	string *actions=({"打扫","收拾"}),msg="";
	int n=random(2),m=random(10);
	if (me->query_temp("songtasks/taichangsi/task")!=1)
	{
		return 0;
	}
	if (me->query_temp("songtasks/taichangsi/1/finish"))
	{
		return notify_fail("既然已经完成，可以回太常寺交卸任务了。\n");
	}
	if (me->query_temp("songtasks/taichangsi/action"))
	{
		return notify_fail("快开始吧！\n");
	}
	while (m>0)
	{
		m-=1;
		msg+=" ";
	}
	message_vision("$N仔细观察了一番，发现这里还需要"+msg+HIR+actions[n]+NOR+"一番。\n",me);
	me->set_temp("songtasks/taichangsi/action",actions[n]);
	tell_object(me,"你可以用action <行为>继续布置太庙任务，比如 action 打扫。\n");
	return 1;
}