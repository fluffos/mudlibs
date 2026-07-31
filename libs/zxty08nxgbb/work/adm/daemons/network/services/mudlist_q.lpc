/* File    : mudlist_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to request a list of muds from another mud.
 */

// Ported to ES2 mudlib by Annihilator (06/15/95)

#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/services.h>   
inherit F_CLEAN_UP;

int my_port;     
void create()
{
        my_port=SRVC_PORT_UDP(mud_port());         
        seteuid(ROOT_UID); 
}

/*
 * Incoming mudlist query.  They want to know which muds we know.
 * We will only tell them about the DNS-enabled muds and not the
 * old tcp ones...
 */
string *build_mudlist(mapping muds)
{
        string *ret;
        string *names;
        int i;

        // only want to send them DNS muds
        names = keys(muds) - ({ "DEFAULT" });
        ret = ({ "" });
        names = sort_array(names, 1);
        // we want to break the mudlist up into smaller packets
        for (i=0;i<sizeof(names);i++) {
                // add the mud to the packet
                ret += ({
                        "||NAME:" + muds[names[i]]["NAME"] +                         "|HOST:"+muds[names[i]]["HOST"]+
                        "||PORT:"+muds[names[i]]["PORT"]+
                        "||PORTUDP:"+muds[names[i]]["PORTUDP"]});
        }
        return ret;
}

void send_mudlist_q(string host, string port)
{
        if(!ACCESS_CHECK(previous_object())) return;
        DNS_MASTER->send_udp(host, port, "@@@"+DNS_MUDLIST_Q+
                "||NAME:"+Mud_name()+
                "||PORT:"+mud_port()+ 
                "||PORTUDP:"+my_port+ "@@@\n");
}

// someone has requests a mudlist from us
void incoming_request(mapping info)
{
        int i;
        string *bits;

        if(!ACCESS_CHECK(previous_object())) return;

        if (info["PORTUDP"])
        {
              bits = build_mudlist((mapping)DNS_MASTER->query_muds());
              for (i=0;i<sizeof(bits);i++) 
              DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                                "@@@"+DNS_MUDLIST_A+ bits[i] + "@@@\n");
        }
}

