// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
                write(HIW"当前目录: " + (string)me->query("cwd") +  "\n"NOR);
                write(HIR"当前文件: " + (string)me->query("cwf") +  "\n"NOR);
		return 1;
	}
}

int help(object me)
{
write(@HELP
指令格式 : pwd
 
这个指令会显示出你目前的工作目录 (cwd) 及工作档案 (cwf).
'update' 不加参数时便会更新你的 cwf.
 
HELP
    );
    return 1;
}
