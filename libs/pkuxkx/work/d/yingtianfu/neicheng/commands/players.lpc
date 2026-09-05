// player.c 显示大明在线玩家
// Zine 2012/10/14
#include <ansi.h>
#include <title.h>
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int sort_user(object ob1, object ob2)
{
	if( !ob1->query("mingpin") && ob2->query("mingpin") )
		return -1;	
	if( !ob2->query("mingpin") && ob1->query("mingpin") )
		return 1;
	if( ob1->query("mingpin") && ob2->query("mingpin") &&ob1->query("mingpin") !=ob2->query("mingpin"))
		return (int)ob2->query("mingpin") - (int)ob1->query("mingpin");
	if( ob1->query("ming/tj/pin") && ob2->query("ming/tj/pin")&&ob1->query("ming/tj/pin") !=ob2->query("ming/tj/pin") )
		return (int)ob2->query("ming/tj/pin") - (int)ob1->query("ming/tj/pin");
	if( ob1->query("ming/duty_rank") && ob2->query("ming/duty_rank") )
		return (int)ob2->query("ming/duty_rank") - (int)ob1->query("ming/duty_rank");
	if( ob1->query("ming/credit") && ob2->query("ming/credit") )
		return (int)ob1->query("ming/credit") - (int)ob2->query("ming/credit");
	return strcmp(ob2->query("id"), ob1->query("id"));
}
string get_pin(object pl)
{
    int pin;
    string msg;
	if (pl->query("mingpin"))
	{
		pin=pl->query("mingpin");
	}
    else if (pl->query("ming/tj/pin"))
    {
		pin=pl->query("ming/tj/pin");
    }
	else
	{
		pin=7;
	}
        if (pin>=5)
        {
            msg=CYN+get_major(pl->get_title(TITLE_MING2))+chinese_number(pin)+"品"+NOR;
        }
        else if (pin>2)
        {
            msg=RED+get_major(pl->get_title(TITLE_MING2))+chinese_number(pin)+"品"+NOR;
        }
        else
        {
            msg=HIR+get_major(pl->get_title(TITLE_MING2))+chinese_number(pin)+"品"+NOR;
        }
    return msg;
}
int main(object me, string arg)
{
        string dm_title,title,str, name, str1, *option,extra;
        object *ob, *list;
        int i, j,len,wen=0,wu=0,huan=0;
        int *tmp, *tmp2;
		if (arg=="-h")
		return help(me);
        if(!wizardp(me) && time()-me->query_temp("scan_time") < 5)
                return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
        title="「" +HIW+ "大明在线官员列表" + NOR + "」";
        str =sprintf("%|94s\n", title);
        str += "———————————————————————————————————————\n";

        ob = ming_all();
        list = sort_array(ob,"sort_user");
                j = sizeof(list);
                while( j-- ) 
                {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if( !me->visible(list[j]) ) continue;
                        if (!list[j]->query("ming/title")) continue;
						dm_title=list[j]->query("ming/title");
						if (list[j]->query("ming/pro")=="文")
						{
							dm_title=HIB+dm_title+NOR;
							extra=HBBLU+HIW+"●文臣●"+NOR;
							wen+=1;
						}
						else if (list[j]->query("ming/pro")=="武")
						{
							dm_title=HIR+dm_title+NOR;
							extra=HBRED+HIW+"●武将●"+NOR;
							wu+=1;
						}
						else if (list[j]->query("ming/tj/pin"))
						{
							dm_title=HIM+dm_title+NOR;
							extra=HBMAG+HIW+"●中官●"+NOR;
							huan+=1;
						}
						else
						{
							dm_title=HIG+dm_title+NOR;
							extra=HBGRN+HIW+"●散官●"+NOR;
						}
                        if (list[j]->query("mingpin"))
                        {
                            dm_title=HIW+"大明 "+get_pin(list[j])+" "+dm_title;
							if (list[j]->query("mingpin")==1)
							{
								dm_title=dm_title+HIY+"★"+NOR;
							}
							if (list[j]->query("ming/juewei_1"))
							{
								dm_title=dm_title+HIY+"★★★"+"  "+list[j]->get_title(TITLE_MING3)+NOR;
							}
							else if (list[j]->query("ming/juewei_2"))
							{
								dm_title=dm_title+HIY+"★★"+"  "+list[j]->get_title(TITLE_MING3)+NOR;
							}
							else if (list[j]->query("ming/juewei_3"))
							{
								dm_title=dm_title+HIY+"★"+"  "+list[j]->get_title(TITLE_MING3)+NOR;
							}
							else
							{
								if (list[j]->query("mingpin")==1)
								{
									dm_title=dm_title+HIY+"  ☆"+NOR;
								}
							}
                        }
						if (list[j]->query("ming/tj/pin"))
                        {
                            dm_title=HIW+"大明 "+get_pin(list[j])+" "+dm_title;
                        }
                        str+= sprintf("%|26s%s%|35s%s%s",COLOR_D->uncolor(list[j]->query("name"))+"("+capitalize(list[j]->query("id"))+")","|",extra,"|",dm_title);
                        str+="\n";
                        
                }
       
    

        str += "———————————————————————————————————————\n";
        str +=sprintf("%|94s\n",HIW+"大明"+NOR+"此刻共有"+chinese_number(wen)+"位文臣，"+chinese_number(wu)+"位武将，"+chinese_number(huan)+"位中官在线。",);
        tell_object(me,str);
        return 1;
}
int help(object me)
{
    write("
指令格式 : ming players
显示大明在线玩家。
"    );
    return 1;
}
