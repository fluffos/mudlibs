int main(object me, string arg)

{
    int i;
    int times;
    string cmd, verb, path;
    
    seteuid(getuid());

    if(!arg || sscanf(arg,"%d %s",times,cmd)!=2)
        return notify_fail("指令格式: do <次数> <系统指令>\n");
    if (times>10) return notify_fail("do命令最多做10次!\n");
    if (cmd[0..1]=="do") return notify_fail("不能连续用do命令!!!\n");

    me->set_temp("redundant_save", 1);      //避免do 10 drop xxx产生多余save, by boost
    for(i=0;i<times;i++)
    {
        if (i == times - 1)
            me->delete_temp("redundant_save");  //最后一次save即可
        me->force_me(cmd);
    }
    me->delete_temp("redundant_save");
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式: do <次数> <系统指令>

这个指令可以让你重复执行某个命令数次，次数不能超过10。
执行的指令可以是系统指令，也可以是用alias自定义的指令。

HELP
         );
    return 1;
}

