// ping.c
#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;

int main(object me, string arg)
{
	if (!arg)
		return notify_fail("命令格式：ping 你要查询服务器连接速度的网址或IP，如ping www.pkuxkx.com\n");
	tell_object(me,load_object("/adm/daemons/webd")->query_web(me,arg,"PING"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：ping 地址              例如：> ping www.pkuxkx.com

这个指令让你可以查询北侠服务器到指定网址的连接速度，方便某些
需要通过代理连接的玩家根据自身和北侠服务器到代理的连接速度选
择代理服务器。
HELP
	);
	return 1;
}

