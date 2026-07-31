// who1.c

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
    str = HIG" ÏßÉÏÍæ¼Ò            ¾«          ¾«Á¦     ¡¡  Æø           ÄÚÁ¦       Éñ      ¾­ÑéÖµ Ç±ÄÜ ¹±Ï×¶È\n"NOR;
    str += "¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);

        str += sprintf(WHT"%-18s:  ",ob->name()+"("+ob->query("id")+")");
        str += sprintf(RED"%5d/%5d ", ob->query("jing"), ob->query("max_jing"));
        str += sprintf(HIR"%5d/%5d ", ob->query("jingli"), ob->query("max_jingli"));
        str += sprintf(YEL"%5d/%5d ", ob->query("qi"), ob->query("max_qi"));
        str += sprintf(BLU"%5d/%5d ", ob->query("neili"), ob->query("max_neili"));
        str += sprintf(GRN"%8d ", ob->query("shen"));      
        str += sprintf(MAG"%7d ", ob->query("combat_exp"));
        str += sprintf(CYN"%3d ", ob->query("potential"));
        str += sprintf(HIG"%5-d \n"NOR,to_int(ob->query("meng/pts")));
       }
    str += "¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n";
    str = sprintf("%s¹²ÓÐ %d Î»Ê¹ÓÃÕßÁ¬ÏßÖÐ¡£\n", str, sizeof(ob_list));
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
	
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½£ºwho1

Íæ¼ÒÐÅÏ¢²éÑ¯¡£
HELP
        );
        return 1;
}
