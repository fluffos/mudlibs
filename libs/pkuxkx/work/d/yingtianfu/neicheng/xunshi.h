//大明高级任务ZINE
#include <ansi.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
void init()
{
	add_action("do_xunshi","xunshi");
	add_action("do_buzhi","buzhi");
	add_action("do_action","action");
}

int do_action(string arg)
{
	object me=this_player();
	if (base_name(environment(me))!="/d/yingtianfu/neicheng/taimiao")
	{
		return 0;
	}
	if (me->query_temp("mingtasks/taichangsi/task")!=2)
	{
		return 0;
	}
	if (!me->query_temp("mingtasks/taichangsi/action"))
	{
		return notify_fail("你要先布置(buzhi)一下，才知道需要干什么！\n");
	}
	if (!arg)
	{
		return notify_fail("你要干么？");
	}
	if (arg!=me->query_temp("mingtasks/taichangsi/action"))
	{
		me->add_temp("mingtasks/taichangsi/action_degree",-1);
	}
	else
	{
		me->add_temp("mingtasks/taichangsi/action_degree",1);
	}
	message_vision("$N在"+environment(me)->query("short")+"里开始"+arg+"。\n",me);
	me->delete_temp("mingtasks/taichangsi/action");
	if (me->query_temp("mingtasks/taichangsi/action_degree")>10)
	{
		tell_object(me,"这里已经被布置的完美无缺了。\n"+HIC+"你的大明功勋增加了！\n"+NOR);
		me->delete_temp("mingtasks");
		me->add("ming/credit",2+random(2));
	}
	else if (me->query_temp("mingtasks/taichangsi/action_degree")<-5)
	{
		tell_object(me,"这里已经被你糟蹋的不可收拾了。\n"+RED+"你的大明功勋下降了！\n"+NOR);
		me->delete_temp("mingtasks");
		me->add("ming/credit",-3);
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
	if (base_name(environment(me))!="/d/yingtianfu/neicheng/taimiao")
	{
		return 0;
	}
	if (me->query_temp("mingtasks/taichangsi/task")!=2)
	{
		return 0;
	}
	if (me->query_temp("mingtasks/taichangsi/action"))
	{
		return notify_fail("快开始吧！\n");
	}
	while (m>0)
	{
		m-=1;
		msg+=" ";
	}
	message_vision("$N仔细观察了一番，发现这里还需要"+msg+HIR+actions[n]+NOR+"一番。\n",me);
	me->set_temp("mingtasks/taichangsi/action",actions[n]);
	tell_object(me,"你可以用action <行为>继续布置太庙任务，比如 action 打扫。\n");
	return 1;
}
int do_xunshi()
{
	object me=this_player(),*place=({});
	int n;
	if (!identification(me,"御前侍卫统领")&&!identification(me,"一等侍卫")&&!identification(me,"御前带刀侍卫")&&me->query("id")!="zine") return 0;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!me->query_temp("ming/shiweichu/job"))
	{
		tell_object(me,"你现在并不在职责范围内。\n");
		return 1;
	}
	if (me->query_temp("ming/shiweichu/job_place"))
	{
		place=me->query_temp("ming/shiweichu/job_place");
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
	me->set_temp("ming/shiweichu/job_place",place);
	if (sizeof(me->query_temp("ming/shiweichu/job_place"))>=10)
	{
		me->delete_temp("ming/shiweichu/job");
		me->delete_temp("ming/shiweichu/job_place");
		write(HIY"你完成了此次巡视的任务！\n"NOR);
		n=8+random(8);
		me->add("ming/credit",n);
		write("你的大明功勋增加了"+chinese_number(n)+"点。\n");
	}
	return 1;
}