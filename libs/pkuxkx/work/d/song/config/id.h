int identification(object me,string * all_titles)
{
	string title,*top_titles,*top_players;
    mapping* titles=({}),top_managers=([]);
    object ob=load_object("/d/song/record/positions");
    titles=ob->query("give_titles");
    if (titles==({}))
    return 0;
    for (int i=0;i<sizeof(titles);i++)
    {
        if (titles[i]["owner"]==me->query("id")||(arrayp(titles[i]["owner"])&&member_array(me->query("id"),titles[i]["owner"])!=-1))
        {
            title=titles[i]["title"];
			if (member_array(title,all_titles)!=-1)
			return 1;
        }
    }
	top_managers=ob->query("TopLevel/ZhengShi/details");
	if (!mapp(top_managers))
	return 0;
	top_titles=keys(top_managers);
	top_players=values(top_managers);
	for (int i=0;i<sizeof(top_titles);i++)
	{
		if (member_array(top_titles[i],all_titles)!=-1&&me->query("id")==top_players[i])
		return 1;
	}
    return 0;
}