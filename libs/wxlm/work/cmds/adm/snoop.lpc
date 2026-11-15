// snoop.c



inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
		return 1;
	}
	if( objectp(ob = query_snooping(me))
	&&	wiz_level(ob) >= wiz_level(me) )
		tell_object(ob,
			HIW + me->name(1) + "停止监听你所收到的讯息。"NOR"\n");
	if( arg=="none" ) {
		snoop(me);
		write("监听停止，Ok。\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) 
		return notify_fail("没有这个人。\n");

	if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
		
	if (!snoop(me, ob)) 
		return notify_fail("监听失败。\n");
		
	write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");
	
	if (wiz_level(ob) >= wiz_level(me))
		tell_object(ob, HIW + me->name(1) + "开始监听你所收到的讯息。"NOR"\n");
	if (geteuid(me) != "yuj" && userp(ob) && (wiz_level(ob)>3||!wiz_level(ob)))
		log_file("nosave/SNOOP_PLAYER", sprintf("%s(%s) snoops %s(%s) at %s on %s.\n",
			me->name(1), geteuid(me), ob->name(1), geteuid(ob), query_ip_name(ob), ctime(time()) ) );

	return 1;
}

int help()
{
	write(@TEXT
指令格式：snoop <某人>|none

监听其他使用者所收听的讯息，snoop none 则取消监听。
TEXT
	);
	return 1;
}
