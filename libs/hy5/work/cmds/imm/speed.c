// who2.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i,a;
    string stri;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str =  "\n               ┏ "+BCYN HIR+MUD_NAME+"成长速度榜"NOR" ┓\n"+HIG;
    str += HIG" 玩家    ID   成长速度/小时  所在房间                                  \n"NOR;
    str += "—————————————————————————————————————\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
if (where)
{
if (ob->query("combat_exp")>1000000)
{
        str += sprintf(WHT"%-8s:  ",ob->name());
        str += sprintf(HIR"%-8s ", ob->query("id"));
//i=1;
if (ob->query("combat_exp") > ob->query_temp("temp_exp"))
{
if (ob->query_temp("temp_exp") && ob->query_temp("mud_age")
&& ob->query("mud_age") && ob->query("combat_exp"))
{
if ((a = (ob->query("combat_exp") - ob->query_temp("temp_exp")) * 60
/ (ob->query("mud_age") - ob->query_temp("mud_age"))) > 100)
a = a*60;
}
}
if (!a) a=0;
        str += sprintf(HIG"%-10d ", a);
        str += sprintf(HIG"%-10s ", environment(ob)->query("short"));
str += sprintf("\n"NOR);
}
}
    }
    str += "—————————————————————————————————————\n";
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
指令格式：toppk

屠人大会信息查询。
HELP
        );
        return 1;
}
