// sp.c


#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
 string *line;
 int i,sum=0;
	mapping m;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	if(!arg)
		return notify_fail("你想查询谁的业绩？\n");
	if(!(m=VIP_D->query_qian(arg)))
		return notify_fail("没有这个推广员！\n");
	line = keys(m);
	for(i=0;i<sizeof(line);i++)
	{
		sum += m[line[i]];
	}
	write(FINGER_D->get_name(arg)+"["+arg+"]的业绩为："+sum+"\n");
	VIP_D->save();
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