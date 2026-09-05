int forbid(object me)
{
	string name=me->query("id");
	string *forbid=({});
	object ob=load_object("/d/yingtianfu/neicheng/beianmen");
	if (ob->query("forbid_list"))
	forbid=ob->query("forbid_list");
	else
	return 0;
	if (member_array(name,forbid)!=-1)
	return 1;
	else
	return 0;
}

int permit(object me)
{
	string name=me->query("id");
	string *permit=({});
	object ob=load_object("/d/yingtianfu/neicheng/beianmen");
	if (ob->query("permit_list"))
	permit=ob->query("permit_list");
	else
	return 0;
	if (member_array(name,permit)!=-1)
	return 1;
	else
	return 0;
}

int do_permit(string arg)
{
	object me=this_player();
	object pl,ob=load_object("/d/yingtianfu/neicheng/beianmen");
	string *list=({}),*list2=({});
	if (ob->query("permit_list"))
	{
		list=ob->query("permit_list");
	}
	if (ob->query("forbid_list"))
	{
		list2=ob->query("forbid_list");
	}
	if (!pl=find_player(arg))
	{
		tell_object(me,arg+"此时并不在线！\n");
		return 1;
	}
	if (!pl->query("mingpin")&&!pl->query("ming/tj/pin"))
	{
		tell_object(me,arg+"并不是官员也是中官，不能放进！\n");
		return 1;
	}
	if (member_array(arg,list)==-1)
	list+=({arg});
	if (member_array(arg,list2)!=-1)
	list2-=({arg});
	ob->set("permit_list",list);
	ob->set("forbid_list",list2);
	message_vision("$N和皇城守门的当值卫士交代了，一会可以放"+pl->query("name")+"进来。\n",me);
	return 1;
}
int do_forbid(string arg)
{
	object me=this_player();
	object pl,ob=load_object("/d/yingtianfu/neicheng/beianmen");
	string *list=({});
	if (ob->query("forbid_list"))
	{
		list=ob->query("forbid_list");
	}
	if (!pl=find_player(arg))
	{
		tell_object(me,arg+"此时并不在线！\n");
		return 1;
	}
	if (member_array(arg,list)==-1)
	list+=({arg});
	ob->set("forbid_list",list);
	message_vision("$N和皇城守门的当值卫士交代了，绝不可以放"+pl->query("name")+"进来。\n",me);
	return 1;
}