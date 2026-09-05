//addproxy.c	把某个ip加入proxy ip列表中
//by bing

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string ip,limit_num;

	if( !arg || sscanf(arg, "%s %s", ip, limit_num)!= 2) 
	{
		write("用法：addproxy <ip> <限制连接数>。\n");
		return 1;
	}
      BAN_D->add_proxy_ip(arg);
	write("ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：addproxy <ip> <限制连接数>

玩家多于30个时限制从某个proxy server登录的玩家数。
TEXT
	);
	return 1;
}
