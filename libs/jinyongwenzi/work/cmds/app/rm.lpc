// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string dir)
{
	int i, j;
	mixed file;

	seteuid(geteuid(me));
	if (!dir) return notify_fail("你要删除那个档案?\n");
	dir = resolve_path(me->query("cwd"), dir);
	if (file_size(dir) == -2 && dir[<1] != '/') dir += "/";
	if (dir[<1] == '/') dir += "*";
	file = get_dir(dir, -1);
	i = sizeof(file);
	if (!i) return notify_fail("没有这个档案。\n");
	write("rm " + dir + "\n");
	dir = implode(explode(dir, "/")[0..<2], "/") + "/";
	while (i--)
		if (file[i][1] >=0) {
			if (!rm(dir+file[i][0])) write("\n你没有删除 "+dir+file[i][0]+" 的权力。\n");
			else {
				write(file[i][0] + " deleted.\n");
				j++;
			}
		}
	write(j+" 个文件被删除掉了。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : rm <档名>

此指令可让你删除有权修改的档案。
HELP
	);
	return 1;
}
