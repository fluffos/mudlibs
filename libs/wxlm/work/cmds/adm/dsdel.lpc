// sp.c


#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
 
 

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	if(!arg)
		return notify_fail("你取消谁的导师？\n");
	if(!VIP_D->query_daoshi(arg))
		return notify_fail("没有这个导师！\n");
	VIP_D->delete_daoshi(arg);
	write("导师取消成功！\n");

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: tgm 
设定推广员
HELP );
	return 1;
}