// reveal.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string msg)
{
	if(!msg) return notify_fail("你要揭发些什么？\n");
	write( "你向巫师揭发了" + HIW + msg + NOR + "的罪行，感到自己是正义的化身！" + "\n" NOR);
  log_file("reveal",me->name()+"("+me->query("id")+")揭发："+ msg + " @"+ ctime(time())+"\n");
  return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：reveal <讯息>

这个指令可以用来向巫师检举揭发其他玩家的不正当行为。
例如：reveal icer是全自动推车机器人！
TEXT
	);
	return 1;
}
