// mkdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir,str;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( mkdir(dir) )
	{
		str = me->query("name") + "(" + me->query("id") + ")于" + ctime(time()) +  
			"创建目录" + dir + "。\n";
		write_file("/log/wiz/mkdir", str);	
		write("Ok.\n");
	}
	else
		write("你没有在这里建子目录的权利。\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式 : mkdir <子目录名>

建立一个子目录。
HELP
	);
	return 1;
}
