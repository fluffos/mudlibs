// destall.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,num;
	object* objs;

	if (!arg) return notify_fail("指令格式 : dest <物件之名称或档名>\n" );

	seteuid(ROOT_UID);
	num=0;
	objs = children(arg);
	if(arrayp(objs) && sizeof(objs) > 0)
	{
		for(i=0;i<sizeof(objs);i++)
		{
			if(clonep(objs[i]))
			{
				destruct(objs[i]);
				num++;
			}
		}
	}

	printf("%d objects are destructed.\n",num);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : destall 档名
清除某文件全部创建出来的clone对象。
HELP
    );
    return 1;
}
