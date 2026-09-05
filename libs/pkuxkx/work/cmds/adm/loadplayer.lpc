int main(object me, string arg)
{
	object user, where;
	string msg;
	if (!arg) return 0;
	where = environment(me);

	seteuid(arg);
	user = new(USER_OB);
        export_uid(user);
	user->set_name("", ({ arg }));
	if (!user->restore())
        { destruct(user); return notify_fail("没有这个玩家。\n");}
        user->seteuid(geteuid(me));
	user->setup();
        user->seteuid(geteuid(me));
	if( !stringp(msg = me->query("env/msg_clone")) )
		if ( where->query("outdoors") )
                	msg = "$n快步走了过来。\n";
		else
			msg = "$n走了过来。\n";
    log_file("loadplayer",user->name()+"("+getuid(user)+") 被"+getuid(me)+"复制于"+ctime(time())+"\n");
	message_vision(msg + "\n", me, user);
	user->move(where);
	return 1;
}

