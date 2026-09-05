// tail.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string file, text;
        int lines, total_lines;

        seteuid(geteuid(me));
        if( !arg ) return help(me);
        if( sscanf(arg, "%s %d", file, lines) != 2 ) {
                file = resolve_path(me->query("cwd"), arg);
                if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
                tail(file);
        }
        else {
                file = resolve_path(me->query("cwd"), file);
                if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
                text = read_file(file);
                if( !text ) {
                        tail(file);
                        return notify_fail("\n文件无内容。\n");
                }
                total_lines = sizeof(explode(text, "\n"));
                if( lines > total_lines ) lines = total_lines;
                text = read_file(file, total_lines - lines + 1, lines);
                me->start_more(text);
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tail <档案> [行数]

此指令可让你(你)直接读取某档案最末尾的几行。
HELP
    );
    return 1;
}
