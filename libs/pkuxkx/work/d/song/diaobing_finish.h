int check_army(object me)
{
	object army=me->query_temp("ARMY");
	if (!army||!army->is_army())
	{
		if (me->query_temp("songtasks/"+this_object()->query("songtasks/taskfrom")+"/diaobing"))
		{
			tell_object(me,"你的换防任务失败了。\n");
			return 1;
		}
		return 1;
	}
	if (me->query_temp("songtasks/"+this_object()->query("songtasks/taskfrom")+"/"+this_object()->query("songtasks/tasknumber")+"/finish"))
	return 1;
	me->set_temp("songtasks/"+this_object()->query("songtasks/taskfrom")+"/"+this_object()->query("songtasks/tasknumber")+"/finish",1);
	tell_object(me,"你完成了换防"+this_object()->query("short")+"的任务，可以回"+this_object()->query("songtasks/taskcfrom")+"复命了。\n");
	army->huanfang(this_object()->query("short"));
	return 1;
}
