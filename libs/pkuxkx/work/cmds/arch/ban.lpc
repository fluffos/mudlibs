// ban.c
// Created by Xiang@XKX

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;
	string id,reason;
	int days;

	if (!arg)
		BAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else
			BAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->remove(site);
	else if (sscanf(arg, "%s for %d because %s",id,days,reason) == 3)
		{
			if (days < 1)
			{
				write("封存天数不能小于一天。\n");
				return 1;
			}
			BAN_D->add_user(id + " " + (time() + days*3600*24) + " " + reason);
			write("使用者" + id + "已被封禁。\n");
		}
	else write("指令格式：ban [+|- site]或ban userid for xx(天) because 原因\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：ban [+|- site]
或	ban userid for days because reason
这条命令是用来防止有人蓄意捣乱或暂时封禁使用者id。
ban命令有两种格式，一个格式ban +/- site直接封某一ip地址，
ban userid for days because reason是以一定理由封某一id
一定天数。
HELP
	);
	return 1;
}
