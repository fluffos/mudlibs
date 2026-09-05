void init()
{
	add_action("do_zhao","zhao");
}

int zhao(object me,string place)
{
	object arrow;
	string place_name=base_name(environment(me));
	if (!me)
	{
		return 1;
	}
	if (place_name!=place)
	{
		tell_object(me,"你什么也没找到。\n");
		return 1;
	}
	if (me->query_temp("mengguquest/arrow_place"+place_name)>random(7)+5)
	{
		tell_object(me,"这里的羽箭似乎被人捡光了，没那么容易找到了。\n");
		return 1;
	}
	me->add_temp("mengguquest/arrow_place"+place_name,1);
	arrow=new(__DIR__"obj/arrow");
	arrow->move(me);
	message_vision("$N找到了一支$n。\n",me,arrow);
	return 1;
}

int do_zhao()
{
	object me=this_player();
	string place=base_name(environment(me));
	if (!me->query("mengguquest/arrow")&&!me->query_temp("mengguquest/start"))
	{
		return 0;
	}
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	message_vision("$N在四处仔细搜索遗落的羽箭。\n",me);
	me->add_busy(2);
	call_out("zhao",1,me,place);
	return 1;
}

