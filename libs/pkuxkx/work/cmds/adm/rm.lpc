// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	string str;
	seteuid(geteuid(me));
    if (!file) return notify_fail("你要删除那个档案?\n");
    file = resolve_path(me->query("cwd"),file);
    if ( rm(file) )
	{
		str = me->query("name") + "(" + me->query("id") + ")于" + ctime(time()) +  
			"删除了" + file + "。\n";
		write_file("/log/wiz/rm", str);	
		write("Ok.\n");
	}
	else
		write("你没有删除这个档案的权利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你(你)删除有权修改的档案。
HELP
    );
    return 1;
}
