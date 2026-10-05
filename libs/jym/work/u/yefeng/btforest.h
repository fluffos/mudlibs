//Cracked by Roath
void init()
{
	object maskman, me=this_player();

	if ( interactive(me) && living(me)) {	
                   if (random(100) < 80) {
                        message_vision("突然头顶上一阵劲风，一个侠客由树上跳了下来！\n", me);
                        maskman = new("u/yefeng/npc/maskman");
			maskman->move(environment(me));
		   }
	}
}
/*
int valid_leave(object me, string dir)
{
        if ( present("xia ke", environment(me)) )
                return notify_fail("侠客拦身说：想走？可没那麽容易！\n");

	return ::valid_leave(me, dir);
}

*/
