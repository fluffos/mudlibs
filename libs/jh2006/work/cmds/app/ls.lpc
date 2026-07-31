// ls.c
// 完美改进 YUJ@SJ 2001-0704

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

private string status(string dir, string file)
{
	int *info;

	if (file[<1] == '/' || file[<2..<1] == ".o")
		return file;
	info = stat(dir + file);
	if (!info[2])
		return file;
	if (info[2] >= info[1])
		return HIG + file + NOR;
	return HIR + file + NOR;
}

private string size(int len)
{
	if (len < 0)
		return "<DIR>";
	if (len <1000000)
		return len+"";
	return len/1000+"K";
}

int sort(mixed *i1, mixed *i2)
{
	if (i1[1] == -2 && i2[1] != -2)
		return -1;
	if (i1[1] != -2 && i2[1] == -2)
		return 1;
	return strcmp(i1[0], i2[0]);
}

int main(object me, string arg)
{
	int i, j, w, col, c, x, y, z;
	string dir, pattern, ret;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if (file_size(dir)==-2 && dir[<1] != '/')
		dir += "/";
	file = get_dir(dir, -1);
	if (!sizeof(file)) {
		if (file_size(dir) == -2)
			return notify_fail("目录是空的。\n");
		return notify_fail("没有这个目录。\n");
	}
	file = sort_array(file, (: sort :));
	w = 0;
	foreach (mixed *item in file) {
		if (item[1] == -2)
			item[0] += "/";
		if (strlen(item[0]) > w)
			w = strlen(item[0]);
	}
	if (dir[<1] != '/')
		dir = "/" + implode(explode(dir, "/")[0..<2], "/");
	if (dir[<1] != '/')
		dir += "/";
	j = sizeof(file);
	ret = "目录：" + dir + " total " + j + "\n";
	col = 90 / (w + 10);
	if (col > 1)
		pattern = repeat_string(" ", (90 - w - 7) / (col - 1) - w - 7);
	y = (j + col - 1) / col;
	z = y * col - j;
	for (i = 0; i < y; i++) {
		for (c = 0, x = i; x < j; x += y) {
			ret += sprintf("%-*s%7s%s",
				w, status(dir, file[x][0]),
				size(file[x][1]),
				++c%col?pattern:"");
			if (i == y - 1 && c + z == col)
				break;
			if (c + z > col)
				x--;
		}
		ret += "\n";
	}
	me->start_more(ret);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: ls [<路径名>]

列出目录下所有的子目录及档案, 如果没有指定目录, 则列出所在目录的内容，
所列出的档案中绿色表示已经载入的物件，红色表示需要被更新。

范例：
'ls /' 会列出所有位于根目录下的档案及子目录.

HELP
	);
	return 1;
}
