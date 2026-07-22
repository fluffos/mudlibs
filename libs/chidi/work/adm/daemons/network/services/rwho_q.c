/*
 * File    : rhow_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 * Modify  : Fan@Falling-sun  2000-02-12
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to ask a mud for a list of users logged on.
 */
 
#include <command.h>
#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;

#define DEBUG "debug"
#undef DEBUG
/*
* Someone has asked us for a remote who...
* Lets oblige them.
*/
nosave int busy=0;

void send_rwho(mapping info,string *msg,int line)
{
    int i,code=1;
    string str="";
    
    for (i=0;i<10 && line<sizeof(msg);i++,line++)
            str += msg[line]+"\n";
#ifdef DEBUG
    CHANNEL_D->do_channel(this_object(), "debug", sprintf("%s (%d)",str,strlen(str)));
#endif
        code = LOCATE_A->encoding(info["HOSTADDRESS"]);
        if( info["ENCODING"] == "GB" ) code = 0;
        if( code == 1)  str = LANGUAGE_D->toBig5(str);

        DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
            "@@@" + DNS_RWHO_A +
            "||NAME:" + Mud_name() +
            "||PORTUDP:" + udp_port() +
            "||RWHO:" + str +
            "||ASKWIZ:" + info["ASKWIZ"] + "@@@\n");
    if ( line<sizeof(msg) )
        call_out("send_rwho",1,info,msg,line);
    else   busy=0;
}
void incoming_request(mapping info)
{
    string str;
    mapping minfo;

    if(!ACCESS_CHECK(previous_object())) return;

    if (stringp(info["NAME"]) && stringp(info["PORTUDP"])) {
        if (info["NAME"] == Mud_name()) return ;

        minfo = DNS_MASTER->query_mud_info(info["NAME"]);
    if (!sizeof(minfo))  return;

        if (busy){
            DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
            "@@@" + DNS_RWHO_A +
            "||NAME:" + Mud_name() +
            "||PORTUDP:" + udp_port() +
            "||RWHO:网路忙。\n" +
            "||ASKWIZ:" + info["ASKWIZ"] +
            "@@@\n");
            return;
        }
        // if we don't have a record of the mud get it
        CHANNEL_D->do_channel( this_object(), "sys",sprintf(HIR "rwho 回应了 %s@%s(%s %s) 的请求." NOR, info["ASKWIZ"],info["NAME"],info["HOSTADDRESS"],minfo["PORT"] ) );
        if (!DNS_MASTER->dns_mudp(info["NAME"])) {
            PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
        }
//        str = WHO_CMD->main(0, info["VERBOSE"], 1);
        str = WHO_CMD->main(0, 0, 1);

    send_rwho(info,explode(str,"\n"),0);
    busy = 1;
    }
}

void send_rwho_q(string mud, object them, int verbose)
{
    mapping info;
    string askwiz;

    if(!ACCESS_CHECK(previous_object())
    &&  base_name(previous_object()) != WHO_CMD)    return;
    if (!them) them = this_player();
    askwiz = geteuid(them);
    info = DNS_MASTER->query_mud_info(mud);
    if (!info) return ;
    DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
        "@@@"+DNS_RWHO_Q+
        "||NAME:"+ Mud_name() +
        "||PORTUDP:"+ udp_port() +
        "||ASKWIZ:"+ askwiz +
        "||VERBOSE:"+ verbose +
//      (verbose ? "||VERBOSE:1" : "") +
        "||@@@\n");
}

void create() 
{
    seteuid(ROOT_UID);
}

mixed query(string arg)
{
    if (arg && arg=="channel_id")
    return "网路精灵";
}

int visiblep(object obj) { return 1; }

string get_name(object obj) { return capitalize(geteuid(obj)); }

int support_rwho_q_VERBOSE() { return 1; }


