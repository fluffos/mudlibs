 
#include <ansi.h>

void init()
{
	add_action("do_climb","climb");
}

int explore(object me,object ob)
{
	object valley;
	string s_banshan=base_name(environment(me)),path=base_name(ob);
	if (!me||!living(me))
	{
		return 1;
	}
	if (s_banshan!="/d/menggu/banshan")
	{
		return 1;
	}
	if (path!=me->query("mengguquest/yinzhe/path"))
	{
		tell_object(me,"你尝试了一下，此处实在过于艰险，非人力能渡，或者还是换到别处下去吧。\n");
		tell_object(me,"武功而返，你只好回到了"+ob->query("short")+"。\n");
		me->move(ob);
		return 1;
	}
	else
	{
		valley=load_object(__DIR__"valley");
		tell_room(valley,me->name()+"从"+ob->query("short")+"笨手笨脚地爬了下来。\n");
		me->move(valley);
		me->add_busy(2);
		return 1;
	}
}

int do_climb(string arg)
{
	object me=this_player();
	object ob=this_object(),valley;
	string path,*paths=({"/d/menggu/buerhan-2","/d/menggu/buerhan-3","/d/menggu/buerhan-4","/d/menggu/buerhan-5","/d/menggu/buerhan-6"});
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!arg||(arg!="down"&&arg!="d"&&arg!="下"))
	{
		tell_object(me,"在这里你只能向下爬。\n");
		return 1;
	}
	if (!me->query("mengguquest/yinzhe/path"))
	{
		if (!me->query_temp("mengguquest/yinzhe/clue"))
		{
			tell_object(me,"别开玩笑了，这里山势险峻，飞鸟难渡，你想爬下去？\n");
			return 1;
		}
		else
		{
			me->set("mengguquest/yinzhe/path",paths[random(sizeof(paths))]);
			message_vision("$N尝试着一步一步向下爬去。\n",me);
			me->move(__DIR__"banshan");
			me->add_busy(3);
			call_out("explore",3,me,ob);
			return 1;
		}
	}
	else
	{
		path=base_name(ob);
		if (path=me->query("mengguqest/yinzhe/path"))
		{
			tell_object(me,"你是不是记错了上次下到山谷的路径了？\n");
			if (wizardp(me))
			{
				tell_object(me,base_name(ob));
			}
			return 1;
		}
		else
		{
			message_vision("$N身手敏捷，像猿猴一般向下攀去，一会没了踪迹。\n",me);
			valley=load_object(__DIR__"valley");
			tell_room(valley,me->name()+"从"+ob->query("short")+"爬了下来。\n");
			me->move(__DIR__"banshan");
			me->move(valley);
			me->add_busy(2);
			return 1;
		}
	}
}