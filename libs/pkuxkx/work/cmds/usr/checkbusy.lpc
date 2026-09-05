// checkbusy,告诉玩家他是否正忙着。玩家现在用suicide来判断，在一些地方有问题。
// 也会造成不必要的负担

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    if(me->is_busy())
    {
        write("你正忙\n");
    }
    else
    {
        write("你不忙\n");
    }
    return 1;           
}

int help(object me)
{
     write(@HELP
指令格式: checkbusy

这个指令让你知道自己是否正忙着。

HELP
    );
    return 1;
}
