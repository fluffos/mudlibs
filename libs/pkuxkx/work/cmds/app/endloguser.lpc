//by pal
inherit F_CLEAN_UP;
inherit F_LOGUSER;

int main(object me, string arg)
{
	if (! arg || arg == "")
		return notify_fail("请你指明一个玩家。\n");
	if( !end_log_user(arg) )
		return notify_fail("记录错误。\n");
	tell_object(me,"停止记录用户"+arg+"的log\n");
	log_file("wiz/endlogusr",sprintf("%s于%s停止记录%s得log。\n",geteuid(me),ctime(time()),arg));
	return 1;
}
