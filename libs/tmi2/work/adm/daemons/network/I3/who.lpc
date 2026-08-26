/*
 * Original by Drizzt, fixed reply format Leto@Earth, 092495
 */

#include <commands.h>
#include <net/i3.h>
/* START WHO ROUTINES */
string send_who_req(string mud, string from){
     if(base_name(previous_object()) != CMD_WHO) return "INVALID";
    if(mud == "global") {
	I3_DAEMON->send_packet(PRT_WHO_REQ, from, 0, 0, ({ }));
	return "Global who request sent!\n";
    }
    mud = I3_DAEMON->query_network_name(mud);
    if(!mud) return "Mud not found in I3 Database!\n";
    I3_DAEMON->send_packet(PRT_WHO_REQ, from, mud, 0, ({ }));
    return "Who Request sent to "+mud+"\n";
}
 
void process_who_reply(mixed *info){
    object ob;
    int i;    
    mixed *data;
 
    if(base_name(previous_object()) != I3_DAEMON) return;
    if(sizeof(info) != SIZ_WHO_REPLY) return;
    if(!(ob = find_living(info[5]))) return;
    /* Put your own little thingy in here, whatever you like */
    data = info[6];
    if(!sizeof(data)){
        message("I3","\n___---==[ Nobody logged into "+info[2]+" ]==---___\n",ob);
        return;
    }
    message("I3","\n___---==[ Who Reply From: "+info[2]+" ]==---___\n",ob);
    message("I3",sprintf("%-15s %-20s %s\n", "Name", "Idle","Extra"),ob);
    message("I3",sprintf("%-15s %-20s %s\n", "----", "----","-----"),ob);
    for(i=0;i<sizeof(data);i++){
        message("I3",sprintf("%-15s %-20s %s\n", capitalize(data[i][0]), format_time(data[i][1]), data[i][2]),ob);
    }
}
 
void process_who_req(mixed *info){
    object *obs;
    mixed packet;
    int i;    
 
    if(base_name(previous_object()) != I3_DAEMON) return;
    if(sizeof(info) != SIZ_WHO_REQ) return;
    packet = ({ });
    obs = users();
    //for(i=0;i<sizeof(obs);i++){
        //packet += ({ ({ ({ obs[i]->query("cap_name"), query_idle(obs[i]), query_ip_name(obs[i]) }) }) }); 

  //}
packet = map(filter(users(),(: !((int)$1->query("invisible")) :)),
    (:  ({  (string)$1->query("cap_name"),query_idle($1),""}) :));

   I3_DAEMON->send_packet(PRT_WHO_REPLY,0 , info[2], info[3], ({ packet }) );
}
 
/* END WHO ROUTINES */
 

