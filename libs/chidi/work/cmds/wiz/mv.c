// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
//       write("mv 命令 v0.21  \nWrite by Lonely@WMKJ 2001/8/29\n");
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
	if (file_size(src)<0)
		return notify_fail("没有这个档名。\n");
       //给东西记录到/log/cmds/mv   黑客(lonely)
/*
        log_file("cmds/mv.log",
        sprintf("%s(%s) mv一个(%s) 到 (%s) on %s\n",
        me->name(),  //记录使用命令的人名
        geteuid(me), //记录使用命令的ID
        src,   //记录源文件
        dst,  //记录目的文件
        ctime(time()) ) ); //记录使用命令的时间
*/

	if (src==dst)	return notify_fail("Ok。\n");
	if (!(int)SECURITY_D->valid_write(src,me,"write_file") )
		return notify_fail("你没有足够的读写权利。\n");
        if( !rename(src, dst) )
                write("Ok.\n");
        else
                write("你没有足够的读写权利。\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : mv <原档名> <目标档名>
 
此指令可让你(你)修改某个档案或目录名称。
HELP
    );
    return 1;
}
 
