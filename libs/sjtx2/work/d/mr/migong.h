int valid_leave(object me, string dir)
{
	if (dir == "west")
		me->add_temp("mark/lvl",1);
	if (dir == "south")
		me->add_temp("mark/lvls",1);
	if (dir == "east")
		me->add_temp("mark/lvl",-1); 
	if (dir == "north")
		me->add_temp("mark/lvls",-1);

	if (me->query_temp("mark/lvl") == -6 
	 && me->query_temp("mark/lvls") == -7
	 && random(me->query("int"))>20) {
		me->move(__DIR__"kongfang");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("你走着走着，莫名其妙的走进了一个空房间。\n");
	}
	if (me->query_temp("mark/lvls") == -6
	 && me->query_temp("mark/lvl") == 5) {
 		me->move(__DIR__"zhengtang");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("你正走着，突然发现前面有一点点灯光, 你借着灯光走了过去。\n");
	}
	if (me->query_temp("mark/lvls") > 20 
	|| me->query_temp("mark/lvls") < -20) {  
		me->move(__DIR__"didao2");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("你白费了半天劲, 又走回了原地。\n");
	}
	if (me->query_temp("mark/lvl") > 20
	 || me->query_temp("mark/lvl") < -20) {  
		me->move(__DIR__"didao2");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("你白费了半天劲, 又走回了原地。\n");
	}
	return ::valid_leave(me, dir);
}
