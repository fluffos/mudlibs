// tail.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string file, text;
int line2;
        int lines, total_lines;

        seteuid(geteuid(me));
        if( !arg ) return help(me);
        if( sscanf(arg, "%s %d %d", file, lines,line2) != 3 ) {
                file = resolve_path(me->query("cwd"), arg);
                if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
                tail(file);
        }
        else {
                file = resolve_path(me->query("cwd"), file);
                if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
                text = read_file(file);
                total_lines = sizeof(explode(text, "\n"));
                if( lines > total_lines ) lines = total_lines;
if (line2>total_lines) line2=total_lines;
                text = read_file(file, lines, line2-lines+1);
                me->start_more(text);
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tail2 <档案> [起始行]  [结束行]

此指令可让你(你)直接读取某档案任意连续行。
HELP
    );
    return 1;
}
