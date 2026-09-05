//by pal
inherit F_CLEAN_UP;
inherit F_LOGUSER;

int main(object me, string arg)
{
	if (! arg || arg == "")
		return notify_fail("请你指明一个玩家。\n");
	if( !start_log_user(arg) )
		return notify_fail("记录错误。\n");
	tell_object(me,"开始记录用户"+arg+"的log\n");
	log_file("wiz/logusr",sprintf("%s于%s记录%s得log。\n",geteuid(me),ctime(time()),arg));
	return 1;
}
