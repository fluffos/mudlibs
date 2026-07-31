// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	mapping site;
	object *users,obj;
	string item, desc;
	string msg;
	int i;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	i = me->query("zjvip/last_baotu");
	write("宝图测试："+localtime(i)[6]+"。\n");
/*
	users = children(USER_OB);
	for(i=0;i<sizeof(users);i++)
	{
		if(users[i]->query("id")=="dudu66")
		{
			write(users[i]->query("name")+"清除完毕。。。\n");
			destruct(users[i]);
		}
	}
*/
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
