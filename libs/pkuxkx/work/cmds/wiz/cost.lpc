// cost.c
#define PROFILE_COMMANDS

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int stime, usertime, eval_cost;
         mapping before1, after1;

        if( me != this_player(1) ) me = this_player(1);

        seteuid(getuid());
        if(!arg) return notify_fail("指令格式：cost <指令> [<参数> ....]\n");

#ifdef PROFILE_COMMANDS
        before1 = rusage();
#endif
        eval_cost = eval_cost();
        me->force_me(arg);
         eval_cost = eval_cost - eval_cost();

#ifdef PROFILE_COMMANDS
        after1 = rusage();
        usertime = after1["utime"] - before1["utime"];
        stime = after1["stime"] - before1["stime"];
#endif
        printf("\n系统时间：%d 微秒\n使用者时间：%d 微秒\nEval cost：%d 单位\n",
                stime, usertime, eval_cost );
                
        return 1;
}

int help()
{
        write( @TEXT
指令格式：cost <指令> [<参数> .... ]

这个指令让你测量另一个指令执行所需的时间。
TEXT
        );
        return 1 ;
}
