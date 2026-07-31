// find string in file
// Created by Numa@Sj 2000.2.21
// Modified by Numa@Sj 2000.7

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string str)
{
        mixed *dir_info;
        string arg, file;
        int i, j = 0;
        
        if (!str)
                return notify_fail("指令格式：fstring <字符串>\n"); 
        if (me->query("cwd") == 0 || me->query("cwd") == "/" )
                return notify_fail("这里无法查找。\n"); 
        dir_info = get_dir(me->query("cwd"),-1);
        arg = CYN"开始在"RED+me->query("cwd")+CYN"目录下查找含有字符串\""GRN+str+CYN"\"的文件：\n";
        arg += HIW"───────────────────────────────────\n"NOR;
        for (i=0;i<sizeof(dir_info);i++)
        {
                if (dir_info[i][1] == -2)
                        continue;
                if (file_size(me->query("cwd")+dir_info[i][0]) <= 0)
                        continue;
                file = read_file(me->query("cwd")+dir_info[i][0]);
                if (strsrch(file,str)>=0) {
                        arg += me->query("cwd")+dir_info[i][0] +"\n";
                        j += 1;
                }
        }
        arg += HIW"─────────────────────────────── SJ ──\n"NOR;
        if (j == 0)
                arg += RED"未找到符合搜索条件的文件。\n"NOR;
        else
                arg += CYN"共找到"RED+j+CYN"个符合搜索条件的文件。\n"NOR;
        me->start_more(arg);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: fstring <字符串>

这个指令可以用来查找本目录下哪些文件包含某字符串。

HELP
        );
        return 1;
}

