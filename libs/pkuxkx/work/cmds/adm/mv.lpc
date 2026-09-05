// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst, str;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
        if( !rename(src, dst) )
{
        str = me->query("name") + "(" + me->query("id") + ")将" + src + "移动到" + dst + "   " + ctime(time())+  " \n";
        write_file("/log/wiz/mv",str);
                write("Ok.\n");
        }
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
 
