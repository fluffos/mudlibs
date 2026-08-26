#include <commands.h>
#include <net/i3.h>
void send_locate_req(string user, string from){
     if(base_name(previous_object()) != CMD_LOCATE) return;
    I3_DAEMON->send_packet(PRT_LOCATE_REQ, from, 0, 0, ({ user }));
}
 
void process_locate_reply(mixed *info){
    if(base_name(previous_object()) != I3_DAEMON) return;
    if(sizeof(info) != SIZ_LOCATE_REPLY) return;
    if(find_living(info[5]))
        message("I3",sprintf("%s was located at %s\n",info[7], info[6]), find_living(info[5]));
}
 
void process_locate_req(mixed *info){
    object ob;
    if(base_name(previous_object()) != I3_DAEMON) return;
 
    if(sizeof(info) != SIZ_LOCATE_REQ) return;
    if((ob = find_living(info[6]))){
        I3_DAEMON->send_packet(PRT_LOCATE_REPLY, 0, info[2], info[3], ({ MUD_NAME, ob->query("cap_name") }));
    }
}
 
/* END LOCATE ROUTINES */
 
 

