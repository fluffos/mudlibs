int no_user(object me)
{
	if (!me)
	return 1;
	if (!living(me))
	return 1;
	if (!environment(me))
	return 1;
	return 0;
}

int present_ming_user(object me,string arg)
{
	object pl;
	if (!pl=present(arg,environment(me)))
	{
		tell_object(me,arg+"现在似乎不在这里！\n");
		return 0;
	}
	if (!userp(pl))
	{
		tell_object(me,pl->query("name")+"不是大明玩家。\n");
		return 0;
	}
	if (pl==me)
	{
		tell_object(me,pl->query("name")+"就是你自己吧？\n");
		return 0;
	}
	if (!living(pl))
	{
		tell_object(me,"你最好等"+pl->query("name")+"清醒过来在继续下一步！\n");
		return 0;
	}
	if (!pl->query("mingpin"))
	{
		tell_object(me,pl->query("name")+"不是大明官员。\n");
		return -1;
	}
	return 1;
}
int ming_cycle(object me,string type,string benefit)
{
	mixed tm=localtime(time());
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	string month=sprintf("%d-%d", tm[5], tm[4]+1);
	if (type=="day"&&me->query("ming/"+benefit+"/"+type)!=day)
	{
		me->set("ming/"+benefit+"/"+type,day);
		me->set("ming/"+benefit+"/times",0);
	}
	if (type=="month"&&me->query("ming/"+benefit+"/"+type)!=month)
	{
		me->set("ming/"+benefit+"/"+type,month);
		me->set("ming/"+benefit+"/times",0);
	}
	return 1;
}
int deny(object me)
{
	if (me->query("ming/title"))
	tell_object(me,"这并不是"+me->query("ming/title")+"职权范围内的事务。\n");
	else
	tell_object(me,"这并不是你职权范围内的事务。\n");
	return 1;
}