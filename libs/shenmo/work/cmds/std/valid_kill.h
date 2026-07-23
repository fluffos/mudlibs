#include <ansi.h>

void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
object env;
env = environment(killer);
        
if ( userp(victim) && userp(killer) && env && !env->query("alternative_die") )
        {
        if ( killer->query_condition("no_pk_time")>480 ) 
                return notify_fail(RED"\n你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n\n"NOR);
/*
        if ( killer->query("PK模式")!="开" )
                {
                message_vision(YEL"\n$N"YEL"作模作样的对着$n"YEL"一阵乱打，可是招招全部落空。。。。\n\n"NOR,killer,victim);
                return 0;
                }
*/
        if ( victim->query("age")<=16 )
                return notify_fail(HIY"\n本站保护新手。\n\n"NOR);
//        if ( victim->query("PK模式")!="开" )
//                return notify_fail(HIG"\n对方非打开PK模式。\n\n"NOR)
        if ( !no_list ) 
                set_my_killer_list(killer, victim);
        }
return 1;
}

void set_my_killer_list(object killer, object victim)
{
string *list, *listk;
string kill;

listk = killer->query_temp("my_killer_list");
if ( listk && arrayp(listk) ) 
        {
        if ( member_array(victim->query("id"),listk)!=-1 ) 
                 return;
         }

list=victim->query_temp("my_killer_list");
kill=killer->query("id");
if(!list) list=({kill});
else if(member_array(kill, list)==-1)
        list+=({kill});
if(sizeof(list)>100)
        list=list[1..<1]; // remove the first element.
victim->set_temp("my_killer_list", list);
}

int set_to_killer(object killer,object target)
{
string enemy;   
killer->delete_temp("is_killer");//清楚上次记录。
killer->set_temp("is_killer/flag",1);//建立新记录
enemy = target->query("id");//记录敌人名字。
killer->set_temp("is_killer/enemy_id",enemy);
}



