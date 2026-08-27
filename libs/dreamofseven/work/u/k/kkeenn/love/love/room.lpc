inherit ROOM;

int valid_leave(object me,string arg)
{
	if( me->query_temp("kill_love") ) {
	foreach(object ob in all_inventory(this_object()))
	{
		if( ob->do_guard(arg) ) return 0;
	}
	}
	:: valid_leave(me, arg);

	return 1;
}
