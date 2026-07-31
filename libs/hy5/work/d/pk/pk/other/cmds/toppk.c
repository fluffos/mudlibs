// who2.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i;
    string stri;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str =  "\n               ©³ "+BCYN HIR+MUD_NAME+"ÍÀÈË´ó»áÅÅÐÐ°ñ"NOR" ©·\n"+HIG;
    str += HIG" Íæ¼Ò    ÄêÁä ÍÀÈËÊý                                             \n"NOR;
    str += "¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
if (where)
{
if (environment(ob)->query("bwdhpk"))
{
        str += sprintf(WHT"%-8s:  ",ob->name());
        str += sprintf(HIR"%-2d ", ob->query("age"));
        str += sprintf(HIG"%-10d ", ob->query_temp("bwdhpk"));
str += sprintf("\n"NOR);
}
}
    }
    str += "¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n";
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
Ö¸Áî¸ñÊ½£ºtoppk

ÍÀÈË´ó»áÐÅÏ¢²éÑ¯¡£
HELP
        );
        return 1;
}
