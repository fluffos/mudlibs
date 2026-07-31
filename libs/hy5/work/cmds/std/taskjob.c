// who2.c

inherit F_CLEAN_UP;
string  zuji(string str);
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i,j;
    string stri;
    string *dir2;
    string room;
//    object me;
    seteuid(getuid());
    me=this_player();
    if (me->is_busy()) 
    return notify_fail("您先歇口气再说话吧。\n");
   str = sprintf(HIR"--------江湖传闻榜--------\n"NOR);
if (me->query_temp("nhdjob2lb"))
{
    str += sprintf(HIR"任务情况:%s。"NOR, me->query_temp("nhdjob2sc"));
}

    str +=read_file("/log/taskjob");
    me->start_more(str);
    me->start_busy(1);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	//if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	//if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	//if( wizardp(ob1) && wizardp(ob2) )
	//	return (int)SECURITY_D->get_wiz_level(ob2) 
	//		- (int)SECURITY_D->get_wiz_level(ob1);
	//
	//return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
指令格式：taskjob

查询当前随机任务。
HELP
        );
        return 1;
}

