//by pal
int start_log_user(string id)
{
	object ob;
	ob = find_player(id);
	if( !ob->is_character() )
		return notify_fail("这不是一个玩家。\n");
	if( ob->query("is_loging") )
		return notify_fail("已经正在记录这个玩家的log了。\n");
	ob->set("is_loging",1);
	return 1;
}

int end_log_user(string id)
{
	object ob;
	ob = find_player(id);
	if( !ob->is_character() )
		return notify_fail("这不是一个玩家。\n");
	if( !ob->query("is_loging") )
		return notify_fail("没有记录这个玩家log。\n");
	ob->delete("is_loging");
	return 1;
}
