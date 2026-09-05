#include <net/dns.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

void create() 
{ 
	seteuid( getuid() ); 
}

int main(object me, string arg)
{
	object *ob, *multis = ({ });
	int i,j,k;
	string temp, ip_i, ip_j;

	ob = users();

	write(HIY"目前" + MUD_NAME + "中多重登陆的玩家有："NOR);
       
	temp = "";

	for(i=0; i<sizeof(ob); i++) {
		ip_i = query_ip_number(ob[i]);
		for(j=i+1; j<sizeof(ob); j++) {
			ip_j = query_ip_number(ob[j]);
			if( ip_i == ip_j ) {
				if( member_array(ob[i], multis) == -1 )
				{
					multis += ({ ob[i], ob[j] });
					temp += sprintf("\n%-18s:  %-14s%-14s",
						ip_i,
						ob[i]->query("id"),
						ob[j]->query("id"));
				}
				else if( member_array(ob[j], multis) == -1 )
				{
					multis += ({ ob[j] });
					temp += sprintf("%-14s", ob[j]->query("id"));
				}
			}
		}
	}

	write(temp + "\n");
	write("OK!\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : samelist
此指令可让你(你)直接查寻从同一ip上线的玩家。
HELP
	);
	return 1;
}
