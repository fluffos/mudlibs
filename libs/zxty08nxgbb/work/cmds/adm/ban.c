// ban.c
// Created by Xiang@XKX

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;
     BAN_D->load_sites();
	if (!arg)
    write(BAN_D->list_sites());
	else if (sscanf(arg, "+ %s", site) == 1) {
		
			BAN_D->add_site(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->remove_site(site);
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
