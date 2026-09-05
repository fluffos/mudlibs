int arrive_mine(object me)
{
	me->move("/d/song/mine");
	me->delete_temp("songtasks/sansishi/wagon_go");
	tell_object(me,"你来到了"+me->query_temp("songtasks/sansishi/task1_area")+"一座铁矿上。\n");
	return 1;
}
string do_gu()
{
	object ob=this_object(),me=this_player(),che;
	string area;
	if (me->is_busy()||me->is_fighting())
	{
		return "你正忙着呢。\n";
	}
	if (time()-me->query("killer/time") < 15*60)
	{
		return "你有命案在身，这时候去雇车，不是自投罗网？\n";
	}
	
	if (!ob->query("this_area"))
	{
		area=AREA_INFO->get_room_area(ob);
		ob->set("this_area",area);
	}
	if (!me->query_temp("songtasks/sansishi/1/finish")&&me->query("song/pro")&&me->query_temp("songtasks/sansishi/task")==1&&me->query_temp("songtasks/sansishi/task1_area")==MAP_D->place_belong(this_object()))
	{
		che=new("/clone/obj/mache");
		che->set("this_area",ob->query("this_area"));
		che->set("from",ob);
		message_vision("$N登上了一辆马车。\n",me);
		me->move(che);
		tell_object(me,"马车开动起来，向着铁矿进发，途中崎岖不平，甚是颠簸。\n");
		me->set_temp("songtasks/sansishi/wagon_go",1);
		call_out("arrive_mine",2+random(2),me);
		return "";
	}
	return ::do_gu();
}