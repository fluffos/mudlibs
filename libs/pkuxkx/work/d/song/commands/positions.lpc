// positions.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
int help(object me);
int main(object me, string arg)
{
	string msg;
    if (arg=="-h")
	return help(me);
	if (time()-me->query_temp("song/query_position")<5)
    {
		tell_object(me,"请勿频繁使用此命令查询。\n");
		return 1;
    }
    msg=DASONG_D->positions();
	tell_object(me,msg);
	me->set_temp("song/query_position",time());
	return 1;
}
int help(object me)
{
    write("
指令格式 : song positions
显示大宋高级官员。
"    );
    return 1;
}
