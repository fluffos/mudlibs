#include "daemons.h"
#include <connection_cl.h>
int cmd_showalts(string str){
class Connection *ip_list;
string name = str;
int flag;
//string *ip_list;
string *filter_list = ({"", "", "", "", "", "", "", "", "", ""});
string *temp_alts;
int i;
ip_list=IP_D->query_all_connections(str);
i = sizeof(ip_list);
while (i--){
        flag = 1;
        for(int y = 0;y<sizeof(filter_list);y++)
        {
                if (filter_list[y] == ip_list[i]->ip){
                        flag = 0;
                }
        }
        if (flag){
                filter_list += ({ ip_list[i]->ip });
        }
}
i = sizeof(filter_list);
while(i--) {
        write(str + "'s ip : " + filter_list[i]);
        temp_alts = IP_D->sameip(filter_list[i]);
        for(int x = 0;x<sizeof(temp_alts) - 1; x++)
        {
                write(str + "'s alt : " + temp_alts[x]);
        }
}
return 1;
}
