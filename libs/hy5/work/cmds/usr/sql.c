// checkip.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

string check_ip(object ob, object *user);

int main(object me, string arg)
{
        int i, num;
        string msg, result;
	string wiz_status;
        object *user;

	if( me != this_player(1) ) return 0;
	wiz_status = SECURITY_D->get_status(me);
        user = users();

	if( wiz_status != "(admin)" && wiz_status != "(wizard)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

        for(i = 0;i < sizeof(user);i++)
                user[i]->set_temp("pending/ipcheck", 0);

        msg = "\n检查在线玩家IP：\n\n";
        num = 0;
        for(i = 0;i < sizeof(user);i++) {
                if(user[i]->query_temp("pending/ipcheck") )     continue;

                if( result = check_ip(user[i], user) ) {
msg += HIW + result + NOR"目前正从"HIY + query_ip_name(user[i]) + NOR"连线中。\n";
                        num++;
                }
        }
        if(num == 0)    msg += "\n检查结果：目前线上玩家的 IP 各不相同。\n";

        if(num > 0)     msg += sprintf("\n检查结果：有 2 玩家或以上相同 IP 数量%d 。\n",num);
        write(msg);
        return 1;
}

string check_ip(object ob, object *user)
{
        int i, find = 0;
        string result, ip, id;

        id = ob->query("id");
        ip = query_ip_name(ob);
        result = ob->query("name") + "(" + ob->query("id") + ")  ";
        for(i = 0;i < sizeof(user);i++) {
                if(user[i]->query("id") != id && query_ip_name(user[i]) == ip) {
                        result += user[i]->query("name") + "(" + user[i]->query("id") + ")  ";
                        user[i]->set_temp("pending/ipcheck", 1);
                        if(id && user[i]->query("id") )
                                find++;
                }
        }

        if( find )      return result;

        return 0;
}

int help(object me)
{
        write(@HELP
指令格式: checkip

检查线上相同IP的玩家。

HELP
        );
        return 1;
}
