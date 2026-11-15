// sp.c


#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
 
 

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	if(!arg)
		return notify_fail("你想设定谁为导师？\n");
	if(VIP_D->query_daoshi(arg))
		return notify_fail("已经有这个导师了！\n");
	VIP_D->set_daoshi(arg,1);
	write("导师设定成功！\n");

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