// kuojian.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	string msg;
	object ob=load_object("/d/song/record/other");
	if (!ob||!ob->query("salary_record/"+me->query("id")))
	{
		tell_object(me,"暂无你的俸禄发放记录。\n");
		return 1;
	}
	msg="你的俸禄发放记录\n";
	for (int i=1;i<=ob->records();i++)
	{
		if (ob->query("salary_record/"+me->query("id")+"/"+i))
		msg+=HIR+"【第"+chinese_number(i)+"条】"+NOR+ob->query("salary_record/"+me->query("id")+"/"+i);
	}
	tell_object(me,msg);
	return 1;
}
int help(object me)
{
    write("
指令格式 : salary
查询自己的俸禄发放情况。
"    );
    return 1;
}
