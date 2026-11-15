// sp.c


#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
 string txt,*line;
	int i,k,sum;
 

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	sum = 0;

	txt = read_file("/log/pay/success");
	line = explode(txt,"\n");
	for(i=0;i<sizeof(line);i++)
	{
		if(sscanf(line[i],"%*s充值%f元%*s",k)==3)
			sum += k;
	}
	write("共计："+sum+"元。\n");

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