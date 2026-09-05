inherit ROOM;
#include <ansi.h>
int is_yingshan()
{
	return 1;
}
void init()
{
	add_action("do_xiu","xiushan");
	add_action("do_look","look");
}

int do_xiu()
{
	object ob=this_object();
	object me=this_player();
	if (!me->query_temp("mingtasks/gongbu/yingshan"))
	{
		return 0;
	}
	if (ob->query("short")==me->query_temp("mingtasks/gongbu/yingshan"))
	{
		message_vision("$N指挥起随从，修缮了"+ob->query("short")+"。\n",me);
		tell_object(me,HIG+"这里已经被修好了，你可以回去复命了。\n"+NOR);
		me->set_temp("mingtasks/gongbu/task4finish",1);
		me->delete_temp("mingtasks/gongbu/yingshan");
		return 1;
	}
	else
	{
		tell_object(me,"这里似乎并不是工部侍郎告诉你需要修缮的地方啊。\n");
		return 1;
	}
}

int do_look(string arg)
{
	object ob=this_object();
	object me=this_player();
	if (ob->query("short")==me->query_temp("mingtasks/gongbu/yingshan"))
	{
		write(HIW+"这里似乎就是需要你修缮(xiushan)的地方了。\n\n"+NOR);
	}
	return 0;
}