// yujue 1997.06.16

int main(object me, string arg)
{
	object user, where;
	string msg;
	if (!arg) return 0;
	if (wiz_level(me) < wiz_level(arg))
		return notify_fail("你不能装载巫师级别比你高的玩家。\n");

	where = environment(me);

	user = new(USER_OB);
	seteuid(arg);
	export_uid(user);
	user->set_name("", ({ arg }));
	if (!user->restore())
        { destruct(user); return notify_fail("没有这个玩家。\n");}
	msg = user->name();
	user->create();
	seteuid("MudOS");
	export_uid(user);
	user->set_name(msg, ({ arg }));
	user->setup();
	if( !stringp(msg = me->query("env/msg_clone")) )
		if ( where->query("outdoors") )
                	msg = "$n快步走了过来。\n";
		else
			msg = "$n走了过来。\n";

	message_vision(msg + "\n", me, user);
	user->move(where);
	return 1;
}
