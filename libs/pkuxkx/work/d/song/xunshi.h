#include <ansi.h>
void init()
{
	add_action("do_xunshi","xunshi");
}

int do_xunshi()
{
	object me=this_player(),*place=({});
	int n;
	if (me->query__temp("songtasks/dianqian/1/finish"))
	{
		tell_object(me,"你已经完成了巡视任务，可以回殿前都复命了。\n");
		return 1;
	}
	if (me->query_temp("songtasks/dianqian/task")!=1) return 0;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (me->query_temp("songtasks/dianqian/job_place"))
	{
		place=me->query_temp("songtasks/dianqian/job_place");
	}
	if (member_array(this_object(),place)!=-1)
	{
		tell_object(me,"你已经彻底巡视过"+this_object()->query("short")+"了。\n");
		return 1;
	}
	n=random(100);
	if (n>74)
	{
		message_vision("$N开始仔细巡视"+this_object()->query("short")+"的防务。\n",me);
		me->add_busy(4);
	}
	else if (n>49)
	{
		message_vision("$N悉心询问"+this_object()->query("short")+"的侍卫有无任何异常情况。\n",me);
		me->add_busy(5);
	}
	else if (n>24)
	{
		message_vision("$N留心观察"+this_object()->query("short")+"的任何异常情况。\n",me);
		me->add_busy(5);
	}
	else
	{
		message_vision("$N觉得"+this_object()->query("short")+"并无任何不妥，可以放心离开了。\n",me);
		me->add_busy(1);
	}
	place+=({this_object()});
	me->set_temp("songtasks/dianqian/job_place",place);
	if (sizeof(me->query_temp("songtasks/dianqian/job_place"))>=15)
	{
		me->set_temp("songtasks/dianqian/1/finish",1);
		write(HIY"你完成了此次巡视的任务！\n"NOR);
		write("这次，你巡视过了");
		for (int i=0;i<sizeof(place);i++)
		{
			write(place[i]->query("short"));
			if (i!=sizeof(place)-1)
			write("、");
		}
		write("等地点。\n");
	}
	return 1;
}