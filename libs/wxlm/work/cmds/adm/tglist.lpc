// sp.c


#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string str,*list;
	int i;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	if(!list = VIP_D->list_qian())
		return notify_fail("当前游戏中还没有推广员！\n");

	str = ZJOBLONG"当前游戏中有"+sizeof(list)+"位推广员：";
	for(i=0;i<sizeof(list);i++)
	{
		str += ZJBR + list[i];
	}

	write(str + "\n");
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
