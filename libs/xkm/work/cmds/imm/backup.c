// Cmds:/cmds/usr/backup.c

inherit F_CLEAN_UP;
int help(object me);

#ifndef BACKUP_D
#define BACKUP_D          "/adm/daemons/backupd"
#endif

int main(object me, string arg)
{
	string flag;
	object user;

	if (! arg || arg =="")
	{
		BACKUP_D->backup_user(me);
		return 1;
	}

	if (arg=="-a")
	{
		BACKUP_D->backup_all(me);
		return 1;
	}

	if (objectp(user=find_player(arg)))
	{
		BACKUP_D->backup_user(user);
		return 1;
	}

	if (sscanf(arg, "%s %s",arg,flag))
	{
		if (flag=="-r")
		{
			BACKUP_D->restore_user(me,arg);
			return 1;
		}
	}

	return help(me);
}

int help(object me)
{
	write(@HELP
指令格式：backup [<id>|-a|-r]

备份档案，玩家只能通过不加参数的使用以备份自己的档案。
(arch) 以上的巫师可以使用 -a 参数来备份数据目录下所有
的档案，-r 参数用于恢复玩家在备份区中的档案。<id>为备
份或者恢复指定一个 ID 的档案。
HELP
	);
	return 1;
}
