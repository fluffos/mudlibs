// sp.c


#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
 
 
 
 
 

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	"/clone/misc/msgd"->on_time();
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: sp <class> <info>

授权给本地站点某些方面的使用权限。info 如果为空或是 clear 则
表示取消这类的使用权限。
HELP );
	return 1;
}