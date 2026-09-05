// list all the users on utf8 ports

inherit F_CLEAN_UP;

#include <mudlib.h>

#define UTF8_PORT 8888

int main(object me)
{
	object ob, *all_users;
	int i;
	all_users = users();
	printf("%s中正在连接UTF8端口的玩家有：\n",CHINESE_MUD_NAME);
	for(i = 0; i < sizeof(all_users); i++)
	{
		if(living(all_users[i]) && query_ip_port(all_users[i]) == UTF8_PORT)
		{
			printf(all_users[i]->query("id")+"\n");
		}
	}
	return 1;
}

int help()
{
	write(@TEXT
指令格式：utf8_users

这个指令可以找出所有连接MUD的UTF8端口的玩家。
TEXT
	);
	return 1;
}
