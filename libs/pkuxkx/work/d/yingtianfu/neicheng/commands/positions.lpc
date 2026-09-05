// positions.c 
// Zine 2012/10/14
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
	string msg;
    if (arg=="-h")
	return help(me);
	if (time()-me->query_temp("ming_query_position")<5)
    {
		tell_object(me,"请勿频繁使用此命令查询。\n");
		return 1;
    }
    msg=DAMING_D->positions();
	tell_object(me,msg);
	me->set_temp("ming_query_position",time());
	return 1;
}
int help(object me)
{
    write("
指令格式 : ming positions
显示大明高级官员。
"    );
    return 1;
}
