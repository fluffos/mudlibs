// tail.c

inherit F_CLEAN_UP;

int help(object me);

int tail(string fname) {
     string str;
     int offset = file_size(fname);

     if (offset < 0)
	 return 0;
     
     offset -= 54 * 30;
     if (offset < 0) offset = 0;
     str = read_bytes(fname, offset, 1620);
     if (!str) return 0;
     if (offset) str = str[strsrch(str, "\n")+1..];
     write(str);

     return 1;
}

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
	tail(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tail <档案>

此指令可让你(你)直接读取某档案最末尾的几行。
HELP
    );
    return 1;
}
