// edit.c
#include "/doc/help.h"
inherit F_CLEAN_UP;
mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return HIM "编辑器(Edit)";
    return 0;
}
int main(object me, string file)
{
    string filename;
    if( !file ) return notify_fail("指令格式：edit <档名>\n");
    if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");
    filename=resolve_path(me->query("cwd"), file);
    if (!(int)SECURITY_D->valid_write(filename,me,"write"))
            return notify_fail("你没有足够的读写权利。\n");
    foreach (object user in users())
        if (filename == "/"+in_edit(user) )
            return notify_fail("共享冲突："+user->name(1)+"("+capitalize(user->query("id"))+")"+"正在编辑该文件("+filename+")。\n");

    printf("编辑文件：%s\n",filename);
    CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)正在编辑文件(%s)。",me->name(1),capitalize(me->query("id")),filename));
    seteuid(geteuid(me));
    ed(resolve_path(me->query("cwd"), file));
    me->set("cwf",filename);
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : edit <档名>, edit here
利用此一指令可直接在线上编辑档案。
                /向前搜索匹配项
                ?向后搜索匹配项
                =显示当前所在行数
                a在当前行的后面添加
                A与'a'相似
                c修改当前行，替换查询文本
                d删除一行或多行
                e用另一个文件覆盖当前文件
                E与'e'相似，但只在文件被子修改之后有效
                f显示/改变当前文件的文件名
                g搜索并对匹配的行执行某种命令
                h帮助
                i在当前行前插入字符
                k用一个字符标记当前行
                l列出一行或多行（带控制字符）
                m移动一行或多行到指定的位置（行号）
                n标记行号
                O同'i'
                o同 'a'
                p列出一定范围的行
                q退出
                Q退出，而且不存
                r在文件尾部或指定行后读入其它文件
                s搜索并替换
                set查询、改变或存储某种设定选项
                t拷贝一行或几行到指定行数
                v搜索并对不匹配的行执行某种命令
                x存文件并退出
                w写入当前文件（或指定文件）采用覆盖
                W现'w'相似，采用追加
                z显示20行，可用 . + - 三种标记
                Z显示40行，可用 . + - 三种标记

HELP
    );
    return 1;
}

