#include "daemons.h"
#include <connection_cl.h>
mapping unique_ip = ([]);
mapping unique_alts = ([]);
void gather_ips(string name)
{
        int i;
        mixed ip_keys;
        class Connection *ip_object;
        string *ip_list;
        ip_object=IP_D->query_all_connections(name);
        i = sizeof(ip_object);
        while (i--) {
                unique_ip[ip_object[i]->ip] = 1;
        }
        ip_list = keys(unique_ip);
        write("unique ips :");
        i = sizeof(ip_list);
        while (i--)
        {
                write(ip_list[i]);
        }
        
}
void gather_alts(string ip)
{
        int i;
        string *temp_alts;
        temp_alts = IP_D->sameip(ip);
        i = sizeof(temp_alts);
        
        while (i--)
        {
                unique_alts[temp_alts[i]] = 1;
        }
}
int cmd_test(string str){
int i;
int count = 0;
string *result;
string format;
gather_ips(str); //returns list of ips for that char
//find out chars on every ip (dump ip of every)
i = sizeof(unique_ip);
while (i--)
{
        gather_alts(unique_ip[i]);
}
i = sizeof(unique_alts);
while (i--)
{
        gather_ips(unique_alts[i]);
}
i = sizeof(unique_ip);
while (i--)
{
        gather_alts(unique_ip[i]);
}
result = keys(unique_alts);
i = sizeof(result);
while(i--)
{
        format += result[i];
        count++;
        if (count > 3) { 
                format += "\n";
                count = 0;
        }
        write(format);
}
//grab ips from str
//search individual ips for alts
//add unique ips from individual alts and add alts to mapping
        
//string *alts;
return 1;
}
