#include <commands.h>
#include <daemons.h>
#include <net/i3.h>
 
void send_finger_req(string from, string user, string mud){
    if(base_name(previous_object()) != CMD_FINGER) return;
    I3_DAEMON->send_packet(PRT_FINGER_REQ, from, mud, 0, ({ user }));
}
 
void process_finger_reply(mixed *info){
    object ob;
 
    if(base_name(previous_object()) != I3_DAEMON) return;
    if(sizeof(info) != SIZ_FINGER_REPLY) return;
    ob = find_living(info[5]);
    if(!ob) return;
    message("I3",sprintf("\nLogin name: %-27s In real life: %s\n",info[6]+"@"+info[2], info[8]), ob);
    message("I3",sprintf("Email Address: %s\n",info[9]),ob);
    if(info[11] == -1) 
        message("I3",sprintf("Last on %s from %s\n",info[10], info[12]), ob);
    else 
        message("I3",sprintf("On since %s from %s\n",info[10], info[12]), ob);
    if(info[11] > 60)
        message("I3",sprintf("%d minutes Idle Time\n",info[11]/60), ob);
    if(!info[14])
        message("I3",sprintf("No Plan.\n"),ob);
    else
	message("I3",sprintf("Plan: %s\n", info[14]), ob);
}
 
void process_finger_req(mixed *info){
    object ob, usr;
    mixed *packet;
 
    if(sizeof(info) != SIZ_FINGER_REQ) return;
    ob = FINGER_D->restore_data(info[6]);
    if(ob){
        usr = find_living(info[6]);
        packet = ({ ob->query("cap_name"),
                    "", /* No title available in Connection Object */
                    ob->query("real_name"),
                    ob->query("email"),
                    ctime(ob->query("last_on")),
                    usr ? query_idle(usr) : -1,
                    ob->query("ip"),
                    0,
                    (file_exists(user_path(info[6])+".plan") ? read_file(user_path(info[6])+".plan") : "No Plan") });
        I3_DAEMON->send_packet(PRT_FINGER_REPLY, 0, info[2], info[3], packet);
    }
}

