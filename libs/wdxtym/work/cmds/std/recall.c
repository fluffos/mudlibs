#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	string str;
	object ob;
 
	
	
	if (arg == "ce")
	{			
        if (me->is_fighting())
			return notify_fail("当你想钻圈圈的时候，被小白一脚踹了出来。\n");
		if (me->query_temp("jun_quest/party"))
			return notify_fail("你还想在战争中使用？！\n");

	if (! me->query("born"))
		return notify_fail("你还没有出生呢！\n");
	
	if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
	
		if (present("biao huo", me))
			return notify_fail("你身上带著镖银，不能施展！\n");
		
		if (present("letter", me) || present("receipt", me)) 
			return notify_fail("你身上带著密函，不能施展。\n");
		
		file = "/d/city/kedian";
		
		if (base_name(environment(me)) == file)
			return notify_fail("你已经在扬州客店了。\n");
			
		if (! get_object(file))
			return notify_fail("你感觉到似乎有什么不对劲！\n");

		message("vision", me->name() + "举起右手在面前极速画了一个圆，竟划破了面前的"
			"空间，只见圆内的空间真空将" + me->name() + "给吸了进去。\n",
			environment(me), ({me}));
		
		tell_object(me, "你从客店的某个角落空间裂缝中钻出。\n");

		me->move(file);
		message("vision", me->name() + "从客店的某个角落空间裂缝中钻出。\n",
			environment(me), ({me}));

		return 1;
	}

   
	
	
	

	return 1;
}


