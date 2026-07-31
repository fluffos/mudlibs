//Cracked by Roath
// ban.c
// Created by Xiang@XKX
// jhy add log 02.9.1

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
	{	write("被封锁了的ip有这些地址。\n");
		BAN_D->print();}
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else
			BAN_D->add(site);
			write("你封锁了"+site+"这个地址。\n");
			log_file("cmds/banip", sprintf("%s%s ban %s (%s) \n",
                me->query("name"),
                "(" + me->query("id") + ")" ,
                site,ctime(time()) ) ); 
		}
	else if (sscanf(arg, "- %s", site) == 1)
		{BAN_D->remove(site);
		write("你解封了"+site+"这个地址。\n");
			log_file("cmds/banip", sprintf("%s%s 解封了 %s (%s) \n",
                me->query("name"),
                "(" + me->query("id") + ")" ,
                site,ctime(time()) ) ); }
	else write("指令格式：ban [+|- site]\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：ban [+|- site]

这条命令是用来防止有人蓄意捣乱。
HELP
	);
	return 1;
}
