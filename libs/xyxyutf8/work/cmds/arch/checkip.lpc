#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
int i, j, k, count = 0;
object *lob, obj, *obs;
string ip, tmp, str = HIW"\n  …… 检查IP相同的玩家 …… "NOR;
mixed groups;
int ip1,ip2,ip3,ip4,n,myip,yourip;
string arg1,clr;

obs = filter_array(objects(), (: interactive :));
obs = filter_array(obs, (:environment:));
obs = sort_array(obs, (:strcmp(query_ip_number($2), query_ip_number($1)):));
i = sizeof(obs);
    
if( stringp(arg) )
        {
        if( objectp(obj = LOGIN_D->find_body(arg)) && me->visible(obj) && interactive(obj))
                {
                arg = query_ip_number(obj);
                tmp = "\n"HIW+ obj->name(1) +"("+ obj->query("id") +")     IP："+ arg +"\n"NOR;
                tmp += "目前和此人从相同IP连入的玩家有：\n\t";
                }
        else    tmp = "\n目前通过 " + arg + " 连入的玩家有：\n\t";
        n=sscanf(arg,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
        myip = (ip1<<24)+(ip2<<16)+(ip3<<8)+ip4;
        while(i--)
                {
                if( obs[i] == obj ) continue;
                arg1 = query_ip_number(obs[i]);
                sscanf(arg1,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
                yourip = (ip1<<24)+(ip2<<16)+(ip3<<8)+ip4;
                if ( query_ip_number(obs[i]) == arg
                  || (myip>>(8*(4-n)))==(yourip>>(8*(4-n))) )
                        {
                        if ( i%2==0 )
                                clr = HIY"";
                        else    clr = HIW"";            
                        tmp += sprintf("%-25s ", clr+obs[i]->query("name") + "("+obs[i]->query("id")+")"NOR);
                        count++;
                        if( count % 3 == 0 )
                                {
                                tmp += "\n\t";
                                count = 0;
                                }
                        }
                }
        write(tmp+"\n");
        return 1;
        }
groups = unique_array(obs, (: query_ip_number($1) :));
k=sizeof(groups);
if ( !sizeof(groups) ) return notify_fail(HIR"\n  …… 完毕 …… \n"NOR);
    
for(i = 0; i < sizeof(groups); i++) 
        {
        if( sizeof( groups[i])  <= 1)  
                continue;
        obs = groups[i];
        lob = obs->query_temp("link_ob") - ({0});
        ip = query_ip_number(obs[0]);
        tmp = sprintf("\n"HIW"%-16s"HIM" → "NOR, ip);
        for( j = 0; j < sizeof(obs); j++ )
                {
                if( j > 0 && j % 4 == 0 ) tmp += "\n\t\t    ";
                if ( i%2==0 )
                        clr = HIY"";
                else    clr = HIW"";                            
                tmp += sprintf("%-16s", clr+obs[j]->query("name")+"("+obs[j]->query("id")+")"NOR);
                }
        str += tmp;
        lob = sort_array(lob, (:strcmp($1->query("email"), $2->query("email")):));
        count = sizeof(lob);
        ip = j = 0;
        tmp = arg = "";
        while(count--)
                {
                if (lob[count]->query("email") != ip) 
                        {
                        if (j > 1) arg += "(" +tmp+") ";
                        ip = lob[count]->query("email");
                        j = 0;
                        tmp = "";
                        }
                tmp += lob[count]->query("id")+", ";
                j++;
                }
        if (j > 1) arg += "(" +tmp+") ";
        if( arg != "" ) str += HIC"\n\t\t    其中Email相同的有："+arg+NOR;
        }
str += HIW"\n  检查完毕，其中独立IP地址共"+ k + "个 \n"NOR;
me->start_more(str);
return 1;
}

int help(object me)
{
write(@HELP
指令格式：checkip [<IP 地址>|<IP 地址范围>|<玩家ID>]


例：
        checkip IP 地址         -> 列出从此ip连入的玩家。
        checkip IP 地址范围     -> 列出从此ip范围内连入的玩家。
        checkip 玩家ID          -> 列出和玩家相同ip的其它玩家。
        checkip                 -> 列出所有相同ip的列表，附带相同 email列表。
        
HELP
);
return 1;
}

