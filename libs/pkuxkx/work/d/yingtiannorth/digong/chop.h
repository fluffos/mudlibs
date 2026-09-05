#include <ansi.h>
void init()
{
	add_action("do_chop",({"chop","kan"}));
	::init();
}
int do_chop()
{
	int allow;
	object obj,tree,me=this_player();
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	else if (!query("chop"))
	{
		write("这里成材的树木都已经被砍光了，只剩下一些小树。\n");
		return 1;
	}
	else
	{
		if (me->query_temp("weapon")&&objectp(obj=me->query_temp("weapon"))&&obj->is_KARMA_AXE()) allow=1;
		else if (me->query_temp("secondary_weapon")&&objectp(obj=me->query_temp("secondary_weapon"))&&obj->is_KARMA_AXE()) allow=1;
		if (!allow)
		{
			tell_object(me,RED"你要砍树，需要一把斧头。\n"NOR);
			return 1;
		}
		if (me->query_temp("karma/level4/skill")!="logger"&&me->query_temp("karma/level4/skill")!="logger2")
		{
			tell_object(me,"你不擅长砍树，找个擅长的人来做吧。\n");
			return 1;
		}
		me->add_busy(3+random(2));
		add("chop",-1);
		message_vision("$N举起手中的$n，砍下了一棵已经成材的树木。\n",me,obj);
		tree=new(__DIR__"obj/tree");
		tree->move(environment(me));
		return 1;
	}
}