#include <commands.h>
#include <net/i3.h>

mapping incoming, outgoing;
private void add_incoming(string mud, int rnd){
    if(!incoming) incoming = ([]);
    incoming[mud] = ({ time(), rnd });
}

private void add_outgoing(string mud, int rnd){
     if(!outgoing) outgoing = ([]);
    outgoing[mud] = ({ time(), rnd });
}
mapping query_incoming(){
    return incoming;
}

mapping query_outgoing(){
    return outgoing;
}

void send_auth_mud_req(string targmud){
    I3_DAEMON->send_packet(PRT_AUTH_MUD_REQ, 0, targmud, 0, ({ }));
}
 
void process_auth_mud_reply(mixed *info){
    if(base_name(previous_object()) != I3_DAEMON) return;
    if(sizeof(info) != SIZ_AUTH_MUD_REPLY) return;
    if(find_living("drizzt"))
        message("I3",sprintf("%s returned an auth-reply of %d\n",info[2],info[6]),find_living("drizzt"));
     add_outgoing(info[2], info[6]);
}
 
void process_auth_mud_req(mixed *info){
    int rnd;
    object ob;
    if(base_name(previous_object()) != I3_DAEMON) return;
 
    if(sizeof(info) != SIZ_AUTH_MUD_REQ) return;
    rnd = random(99999999);
   tell_object(find_living("drizzt"),"Sent "+info[2]+" "+rnd+"\n");
   I3_DAEMON->send_packet(PRT_AUTH_MUD_REPLY, 0, info[2], 0, ({ rnd }));
     add_incoming(info[2], rnd);
}
 

