/*
 * File    : rwho_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to send a reply to a remote who request.
 */

//UPDATE BY SMALLFISH@HUAXIA

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

mapping whostr = ([]);

mapping query_whostr()
{
        return whostr;
}

// They have answered our remote who question.

void incoming_request(mapping info)
{
        object ob;
        string str,key,is_end;

        if (! ACCESS_CHECK(previous_object())) return;

        if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"]))
        {
                if (info["NAME"] == Mud_name()) return ;
                if (! DNS_MASTER->dns_mudp(info["NAME"]))
                        PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
                if (! (ob = find_player(lower_case(info["ASKWIZ"])))) return;
                if (info["KEY"] == "0")
                        tell_object(ob, info["RWHO"]);
                else
                {
                        key = info["KEY"];
                        is_end = info["NUM"];
                        if (!stringp(whostr[key]))
                                whostr[key] = info["RWHO"];
                        else
                                whostr[key] += info["RWHO"];
                        if (is_end == "1")
                        {
                                str = "";
                                str += whostr[key];
                                ob->start_more(str);
                                map_delete(whostr,key);
                        }                               
                }
        }
        return;
}

void create()
{
        seteuid(ROOT_UID);
}

