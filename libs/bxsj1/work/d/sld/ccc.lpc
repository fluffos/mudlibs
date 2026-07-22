// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	int i, j;
	string src, dst, tmps, tmpd;
	mixed file;
	int err;
 
seteuid("xiaoyao");
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("指令格式: cp <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	if (file_size(src) == -2 && src[<1] != '/') src += "/";
	if (src[<1] == '/') src += "*";
	dst = resolve_path(me->query("cwd"), dst);
	if (file_size(dst) == -2 && dst[<1] != '/') dst += "/";
	file = get_dir(src, -1);
	i = sizeof(file);
	if (!i) return notify_fail("没有 "+src+"。\n");
	write(src + " -> " + dst);
	src = "/" + implode(explode(src, "/")[0..<2], "/") + "/";
	while (i--) {
		if (file[i][1] >= 0) {
			tmps = src + file[i][0];
			tmpd = dst;
			if (tmpd[<1] == '/') tmpd += file[i][0];
			write("\n"+tmps+" -> "+tmpd+" ");
			if (tmps == tmpd) {
				write("忽略。");
				continue;
			}
			switch ( err = cp(tmps, tmpd) ) {
				case 1:
					write("成功。");
					j++;
					break;
				case -1:
					write(tmps + " 不可读。");
					break;
				case -2:
					write(tmpd + " 不可写。");
					break;
				default:
					write("错误码：" + err);
			}
		}
	}
	write("\n"+j+" 个文件拷贝成功。\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : cp <原档名> <目标档名>
 
此指令可让你(你)拷贝档案。
HELP
    );
    return 1;
}
 
