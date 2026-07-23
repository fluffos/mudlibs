// Code of ShenZhou
void init()
{
	object maskman, obj, me=this_player();

	if ( interactive(me) && living(me)) {	
		   if (random(10) == 3 && time() > me->query("mp_job_time") + 180 ) {
			if (obj = present("ling pai",me) && obj->query_temp("owner") == me->query("id"))
				return;
			message_vision("突然头顶上一阵劲风，一个蒙面大汉由树上跳了下来！\n", me);
			maskman = new(__DIR__"npc/maskman");
			maskman->move(environment(me));
		   }
	}
}
/*
int valid_leave(object me, string dir)
{
	if ( present("mengmian ren", environment(me)) )
		return notify_fail("蒙面人拦身说：想走？可没那麽容易！\n");

	return ::valid_leave(me, dir);
}
*/

